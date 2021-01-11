#include <iostream>

unsigned int size = 0;
int most_cost = 0, ans = 0;

namespace Qin
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
}

struct Vertex
{
    int x;
    int y;
    unsigned int position;


    int distance;

    explicit Vertex(int x = 0, int y = 0, int pos = 0) : x(x), y(y), distance(1u<<24u), position(pos){};

    bool operator < (const Vertex& v) const { return distance < v.distance; }
    bool operator > (const Vertex& v) const { return distance > v.distance; }
    bool operator <=(const Vertex& v) const { return distance <= v.distance; }
    bool operator >=(const Vertex& v) const { return distance >= v.distance; }
    bool operator ==(const Vertex& v) const { return distance == v.distance; }
};

Vertex* v_heap[1u<<14u];


static inline int DistanceMH(Vertex v1, Vertex v2) {return abs(v1.x - v2.x) + abs(v1.y - v2.y);}

static inline void pswap(Vertex* &v1, Vertex* &v2)
{
    std::swap(v1, v2);
    std::swap(v1->position, v2->position);
}


static inline void percolateDown(unsigned int pos)
{
    unsigned int fst_chld;


    for (unsigned int i = pos; i <= (size>>1u);)
    {


        fst_chld = i<<1u;

        if (fst_chld > size) return;

        if (fst_chld+1 > size)
        {
            if (*v_heap[fst_chld] < *v_heap[i]) pswap(v_heap[fst_chld], v_heap[i]);
            return;
        }

        if (*v_heap[fst_chld] < *v_heap[i] && *v_heap[fst_chld] <= *v_heap[fst_chld+1])
        {
            pswap(v_heap[fst_chld], v_heap[i]);
            i = fst_chld;
        }

        else if (*v_heap[fst_chld+1] < *v_heap[i])
        {
            pswap(v_heap[fst_chld+1], v_heap[i]);
            i = fst_chld+1;
        }

        else return;
    }
}

static inline Vertex* pop()
{
    pswap(v_heap[1], v_heap[size]);

    size--;

    percolateDown(1u);

    return v_heap[size+1];
}

static inline void decrs_key(Vertex* &v, int new_dis)
{
    v->distance = new_dis;

    for (unsigned int i = v->position; i > 1; i >>= 1u)
    {
        unsigned int parent = i>>1u;
        if (*v_heap[parent] > *v_heap[i]) pswap(v_heap[parent], v_heap[i]);
        else return;
    }

}



int main()
{
    std::ios::sync_with_stdio(false);


    int n, k, x, y;

    Qin::read(n), Qin::read(k);

    for (int i = 0; i < n; ++i)
    {
        Qin::read(x), Qin::read(y);
        v_heap[i] = new Vertex(x, y, i);
        v_heap[i]->distance = DistanceMH(*v_heap[0], *v_heap[i]);
    }


    size = n - 1;

    for (int i = (int)size/2; i > 0; i--) percolateDown(i);


    Vertex* target = pop();
    ans += target->distance, most_cost = target->distance;



    while(size > 0)
    {
        for (int j = 1; j <= size; ++j)
        {
            x = DistanceMH(*target, *v_heap[j]);
            if (x < v_heap[j]->distance) decrs_key(v_heap[j], x);
        }

        target = pop();

        ans += target->distance, most_cost = std::max(most_cost, target->distance);
    }

    std::cout<<(ans-most_cost)<<std::endl;
    return 0;
}
