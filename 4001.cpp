#include <iostream>
#define INF 0x3f3f3f3f


namespace Qio
{
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1u<<21u,stdin),p1==p2)?EOF:*p1++)
    char buf[1u << 21u], *p1 = buf, *p2 = buf;

    template<class T>
    inline void read(T &x)
    {
        x = 0; char c = getchar(); bool f = false;
        while (!isdigit(c))f ^= c == '-', c = getchar();
        while (isdigit(c))x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
        if (f)x = -x;
    }
    template <class T> inline void put(const char ch,T x)
    {
        static std::streambuf *obuf = std::cout.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {obuf -> sputc('-');x=-x;}
        if (!x) {obuf -> sputc('0');obuf -> sputc(ch);return;}
        while (x) {stack[++top] = x % 10 + '0';x /= 10;}
        while (top) {obuf -> sputc(stack[top]);--top;}
        obuf -> sputc(ch);
    }
}

int n, m, k, s;
int dist_from_s[25005];

bool v[25005];

struct Adj_Vertex;

struct Vertex
{
    int id;
    int block_belongs_to;
    Adj_Vertex* fst_child;
    Vertex* next_linked_in_block;
    int pos = 0;

    explicit Vertex(int i = 0, Adj_Vertex* fstchld = nullptr, Vertex* nlib = nullptr) : id(i), block_belongs_to(i), fst_child(fstchld), next_linked_in_block(nlib){};
};

struct Adj_Vertex
{
    int edge_length_to_self;
    int target_vertex_id;
    Adj_Vertex* next;
    explicit Adj_Vertex(int length = INF, int tgt = 0, Adj_Vertex* nxt = nullptr) : edge_length_to_self(length), target_vertex_id(tgt), next(nxt){};
};


Vertex* vertex_list[25005];
int v_heap[25005];

static inline void pswap(int f, int si)
{
    std::swap(v_heap[f], v_heap[si]);
    std::swap(vertex_list[v_heap[f]]->pos, vertex_list[v_heap[si]]->pos);
}

struct Inner_Block
{
    Vertex* members;
    Vertex* members_tail;

    explicit Inner_Block(Vertex* mi = nullptr) : members(mi), members_tail(members){};
};


struct LVB
{
    int vertex_from = 0;
    int vertex_to_other = 0;
    int edge_length = 0;
    LVB* next = nullptr;

    explicit LVB(int from = 0, int to = 0, int length = 0, LVB* nxt = nullptr) : vertex_from(from), vertex_to_other(to), edge_length(length), next(nxt){};
};

struct Block
{
    int in_degree;

    int out_degree;

    LVB* Linked_Vertex_to_Block = nullptr;

    Inner_Block* inner;

    explicit Block(Inner_Block* in = nullptr, int ind = 0, int oud = 0) : inner(in), in_degree(ind), out_degree(oud)
    {
    };
};

Block* block_list[25005];


inline int find(int i)
{
    if (i != vertex_list[i]->block_belongs_to) vertex_list[i]->block_belongs_to = find(vertex_list[i]->block_belongs_to);
    return vertex_list[i]->block_belongs_to;
}


inline void initialize()
{
    for (int i = 1; i <= n; ++i)
    {
        vertex_list[i] = new Vertex(i);
        block_list[i] = new Block(new Inner_Block(vertex_list[i]), 0);
        dist_from_s[i] = INF;
        v[i] = false;
    }
}



inline void vertex_add_neighbor(int self, int neighbor, int dis)
{
    vertex_list[self]->fst_child = new Adj_Vertex(dis, neighbor, vertex_list[self]->fst_child);
}

inline void merge_two_block(int first, int second)
{
    vertex_list[second]->block_belongs_to = first;

    block_list[first]->inner->members_tail->next_linked_in_block = block_list[second]->inner->members;
    block_list[first]->inner->members_tail = block_list[second]->inner->members_tail;

    delete block_list[second];
    block_list[second] = nullptr;
}


inline void add_warp(int l, int r, int dis)
{

    vertex_add_neighbor(l, r, dis), vertex_add_neighbor(r, l, dis);

    int l_id = find(l), r_id = find(r);

    if (l_id != r_id) merge_two_block(l_id, r_id);
}


inline void add_E_R_Bridge(int l, int r, int dis)
{
    int from_block_id = find(l);

    block_list[from_block_id]->Linked_Vertex_to_Block = new LVB(l, r, dis, block_list[from_block_id]->Linked_Vertex_to_Block);

    block_list[from_block_id]->out_degree++;

}

inline void select_reachable(int block_id)
{
    int target;

    LVB* tt = block_list[block_id]->Linked_Vertex_to_Block;

    for (int i = 1; i <= block_list[block_id]->out_degree; ++i)
    {
        target = find (tt->vertex_to_other);
        block_list[target]->in_degree++;
        if (!v[target])
        {
            v[target] = true;
            select_reachable(target);
        }
        tt = tt->next;
    }
}


inline void percolateDown(int pos, int size)
{
    int fst_chld;


    for (int i = pos; i <= (size/2);)
    {

        fst_chld = i*2;

        if (fst_chld > size) return;


        if (fst_chld+1 > size)
        {
            if (dist_from_s[v_heap[fst_chld]] < dist_from_s[v_heap[i]]) pswap(fst_chld, i);
            return;
        }

        if (dist_from_s[v_heap[fst_chld]] < dist_from_s[v_heap[i]] && dist_from_s[v_heap[fst_chld]] <= dist_from_s[v_heap[fst_chld+1]])
        {
            pswap(fst_chld, i);
            i = fst_chld;
        }


        else if (dist_from_s[v_heap[fst_chld+1]] < dist_from_s[v_heap[i]])
        {
            pswap(fst_chld+1, i);
            i = fst_chld+1;
        }


        else return;
    }
}


inline int construct(Inner_Block* ib)
{
    Vertex* ptr = ib->members;
    int i = 1;
    for (; ptr; ++i)
    {
        v_heap[i] = ptr->id;
        ptr->pos = i;
        ptr = ptr->next_linked_in_block;
    }

    int size = i-1;


    for (i = size/2; i > 0; i--) percolateDown(i, size);


    return size;
}



inline void heap_decrs_key(int target, int new_dis)
{
    dist_from_s[target] = new_dis;

    int position = vertex_list[target]->pos;

    for (int i = position; i > 1; i >>= 1u)
    {
        int parent = i>>1u;
        if (dist_from_s[v_heap[parent]] > dist_from_s[v_heap[i]]) pswap(parent, i);
        else return;
    }
}

inline void heap_expand(const bool* Visited)
{
    Adj_Vertex* ptr = vertex_list[v_heap[1]]->fst_child;

    int new_dis;

    while (ptr)
    {

        if (Visited[ptr->target_vertex_id])
        {
            ptr = ptr->next;
            continue;
        }

        new_dis = dist_from_s[v_heap[1]] + ptr->edge_length_to_self;

        if (dist_from_s[ptr->target_vertex_id] > new_dis) heap_decrs_key(ptr->target_vertex_id, new_dis);

        ptr = ptr->next;
    }
}

inline void heap_pop(int size)
{
    pswap(1, size);

    percolateDown(1, size-1);
}


inline void dijkstra(int target)
{
    bool Visited[25005] = {false};
    int size = construct(block_list[target]->inner);

    while (size)
    {
        Visited[v_heap[1]] = true;
        heap_expand(Visited);
        heap_pop(size);
        size--;
    }
}

inline void recur_pop(int block_id)
{
    LVB* target = block_list[block_id]->Linked_Vertex_to_Block;
    int target_BLOCK, ini;
    for (int i = 1; ; ++i)
    {
        if (!target) return;

        target_BLOCK = find(target->vertex_to_other);
        block_list[target_BLOCK]->in_degree--;

        ini = dist_from_s[target->vertex_from] + target->edge_length;

        if (dist_from_s[target->vertex_to_other] > ini) dist_from_s[target->vertex_to_other] = ini;

        if (!block_list[target_BLOCK]->in_degree)
        {
            dijkstra(target_BLOCK);
            recur_pop(target_BLOCK);
        }

        target = target->next;
    }
}

int main()
{

    std::ios::sync_with_stdio(false);

    Qio::read(n), Qio::read(m), Qio::read(k), Qio::read(s);

    initialize();

    int l, r, dis;



    for (int i = 0; i < m; ++i)
    {
        Qio::read(l), Qio::read(r), Qio::read(dis);
        add_warp(l, r, dis);
    }



    for (int i = 0; i < k; ++i)
    {
        Qio::read(l), Qio::read(r), Qio::read(dis);
        add_E_R_Bridge(l, r, dis);
    }

    int start_block_id = find(s);

    select_reachable(start_block_id);

    dist_from_s[s] = 0;
    dijkstra(start_block_id);

    recur_pop(start_block_id);

    for (int i = 1; i <= n ; ++i)
    {
        if (dist_from_s[i] < INF) Qio::put('\n', dist_from_s[i]);
        else std::cout<<"UNREACHABLE"<<'\n';
    }

    return 0;
}