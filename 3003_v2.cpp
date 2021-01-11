

#include <iostream>



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
};
Vertex v[6000];
int sets[6000];

inline int DistanceMH(Vertex v1, Vertex v2) {return abs(v1.x - v2.x) + abs(v1.y - v2.y);}

struct Edge
{
    int lv;
    int rv;
    int length;

    bool operator <(const Edge& e) const { return length < e.length; }
    bool operator >(const Edge& e) const { return length > e.length; }

    explicit Edge()=default;
    Edge(int l, int r) : lv(l), rv(r), length(DistanceMH(v[lv], v[rv])){}
};

void insertion_sort(Edge* eds, int N)
{
    Edge temp;
    int j;

    for (int i = 1; i < N; i++)
    {
        temp = eds[i];
        for (j = i; j > 0 && eds[j - 1] > temp; j--) eds[j] = eds[j - 1];
        eds[j] = temp;
    }
}

inline Edge pre_qsort(Edge* eds, int first, int last)
{
    int mid = (first + last - 1)/2;

    if (eds[first] > eds[mid]) std::swap(eds[first], eds[mid]);

    if (eds[mid] > eds[last - 1]) std::swap(eds[mid], eds[last - 1]);

    if (eds[first] > eds[mid]) std::swap(eds[first], eds[mid]);

    std::swap(eds[mid], eds[last - 2]);

    return eds[last - 2];
}

void quick_sort(Edge* eds, int first, int last)
{
    if (last - first > 10)
    {
        int i = first, j = last - 2;
        Edge pivot = pre_qsort(eds, first, last);

        while (true)
        {
            while (eds[++i] < pivot);
            while (eds[--j] > pivot);
            if (i < j) std::swap(eds[i], eds[j]); else break;
        }

        std::swap(eds[i], eds[last - 2]);

        quick_sort(eds, first, i);
        quick_sort(eds, i + 1, last);
    }
    else insertion_sort(eds + first, last - first);
}

Edge e[36000000];

int find(int i)
{
    if (i != sets[i]) sets[i] = find(sets[i]);
    return sets[i];
}




int main()
{
    int n, k, fl, fr, ans = 0, m, count = 0;
    Qin::read(n), Qin::read(k), m = n*(n-1)/2;

    for (int i = 0; i < n; ++i)
    {
        Qin::read(v[i].x), Qin::read(v[i].y);
        sets[i] = i;
        for (int j = 0; j < i; ++j) e[i*(i - 1)/2 + j] = Edge(j, i);
    }

    quick_sort(e, 0, m);


    for (int i = 0; i < m; i++)
    {
        fl = find(e[i].lv), fr = find(e[i].rv);

        if (fl != fr)
        {
            sets[fl] = fr;
            ans += e[i].length;
            count++;
            if (count == n - 2) break;
        }

    }

    std::cout<<ans<<std::endl;

    return 0;
}
