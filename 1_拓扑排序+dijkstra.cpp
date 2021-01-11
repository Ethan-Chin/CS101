#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 25005
#define MAXE 150005
inline int read() {
    int x=0,f=1;char c=getchar();
    while (!(c>='0'&&c<='9')) {if(c=='-') f=-1; c=getchar();}
    while (c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}

template <typename T>
struct Heap { 
    T *data;
    int m_size = 0, capacity = 4;
    explicit Heap(): data(new T[5]) {}
    ~Heap() {delete[] data; data = nullptr;}
    inline void swap(int a, int b) {T tmp = data[a]; data[a] = data[b]; data[b] = tmp;}   
    void expand() {
        capacity <<= 1;
        T *new_data = new T[capacity+1];
        std::copy(data, data+m_size+1, new_data);
        delete[] data; data = new_data;
    }
    void push(const T& v) {
        if (m_size == capacity) expand();
        int pos = ++m_size; data[pos] = v;
        while (pos != 1) {
            if (data[pos] < data[pos>>1]) this->swap(pos, pos >> 1);
            else return;
            pos >>= 1;
        }
    }
    void remove(int pos = 1) {
        data[pos] = data[m_size--];
        while (pos<<1 <= m_size) {
            int new_pos = pos << 1;
            if (data[new_pos+1] < data[new_pos] && new_pos < m_size) new_pos |= 1;
            if (data[new_pos] < data[pos]) this->swap(pos, new_pos);
            else return;
            pos = new_pos;
        }
    }
    inline T root() const {return data[1];}
    inline bool empty() const {return m_size == 0;}
    Heap& operator +=(const T& v) {push(v); return *this;}
};
template <typename T>
struct Vector {
    T *data = new int[4];
    int length = 0, max_size = 4;
    inline void push_back(const T v) {
        if (length == max_size) {
            max_size <<= 1;
            T *new_data = new T[max_size];
            std::copy(data, data+length, new_data);
            delete[] data; data = new_data;
        }
        data[length++] = v;
    }
    inline int size() const {return length;}
    T& operator[](const int pos) const {return data[pos];}
};
template <typename T>
struct Queue {
    T* data;
    int head = 0, tail = 0;
    explicit Queue(unsigned n): data(new T[n]) {}
    ~Queue() {delete[] data;}
    inline void push(const T v) {data[tail++]=v;}
    inline T pop() {return data[head++];}
    inline bool empty() const {return tail-head==0;}
};

struct Edge {
    int to, next, w;
}e[MAXE];
struct Vertex {
    int num, dis;
    bool operator < (const Vertex& other) const {return dis < other.dis;}
};
int n, m, k, s;
int head[MAXN]={0}, edge_cnt=0, dis[MAXN];
int belong[MAXN]={0}, group_cnt=0, deg[MAXN]={0};
bool vis[MAXN] = {0};
Vector<int> group[MAXN];
Queue<int> q(MAXN);
Heap<Vertex> h;
inline void add_Edge(int from, int to, int w) {
    e[++edge_cnt] = (Edge){to,head[from],w};
    head[from] = edge_cnt;
}

void dfs(int x) {
    belong[x] = group_cnt;
    group[group_cnt].push_back(x);
    for (int i = head[x]; i != 0; i = e[i].next)
        if (!belong[e[i].to]) dfs(e[i].to);
}

void dijkstra(int st) {
    int sz = group[st].size();
    for (int i = 0; i < sz; i++) 
        h += (Vertex){group[st][i], dis[group[st][i]]};
    while (!h.empty()) {
        int p = h.root().num; 
        h.remove();
        if (vis[p]) continue;
        vis[p] = true;
        for (int i = head[p]; i != 0; i = e[i].next) {
            int y = e[i].to;
            if (dis[p] + e[i].w < dis[y]) {
                dis[y] = dis[p] + e[i].w;
                if (belong[p] == belong[y] && !vis[y]) 
                    h += (Vertex){y, dis[y]};
            }
            if (belong[p] != belong[y]) {
                deg[belong[y]]--;
                if (!deg[belong[y]]) q.push(belong[y]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    n=read(),m=read(),k=read(),s=read();
    for (int i = 0; i < m; i++) {
        int u=read(),v=read(),w=read();
        add_Edge(u,v,w);
        add_Edge(v,u,w);
    }
    for (int i = 1; i <= n; i++) 
        if (!belong[i]) group_cnt++, dfs(i);
    for (int i = 0; i < k; i++) {
        int u=read(),v=read(),w=read();
        add_Edge(u,v,w);
        deg[belong[v]]++;
    }
    
    std::fill(dis+1, dis + n + 1, 0x3fffffff);
    dis[s] = 0, q.push(belong[s]);
    for (int i = 1; i <= group_cnt; i++)
        if (!deg[i]) q.push(i);
    while (!q.empty()) dijkstra(q.pop());

    for (int i = 1; i <= n; i++)
        if (dis[i] > int(5e8)) cout << "UNREACHABLE" << "\n";
        else cout << dis[i] << "\n";
    return 0;
}
