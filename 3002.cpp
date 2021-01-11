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

struct subgraph
{
    unsigned int num_v;
    unsigned int num_e;
    unsigned int root;
    explicit subgraph(int rt) : num_v(1), num_e(0), root(rt){};
};


subgraph* sets[100005];

unsigned int find(unsigned int i)
{
    if (i != sets[i]->root) sets[i]->root = find(sets[i]->root);
    return sets[i]->root;
}



int main()
{
    std::ios::sync_with_stdio(false);
    unsigned int n, m, l, r, ans = 0;
    Qin::read(n),  Qin::read(m);
    for (int i = 1; i <= n; ++i) sets[i] = new subgraph(i);
    for (int i = 0; i <  m; ++i)
    {
        Qin::read(l), Qin::read(r);
        unsigned int mg = find(r);
        unsigned int tp = find(l);
        if (mg != tp)
        {
            sets[tp]->root = mg;
            sets[mg]->num_v += sets[tp]->num_v;
            sets[mg]->num_e += sets[tp]->num_e + 1;
        }
        else sets[mg]->num_e++;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (sets[i]->root == i)
        {
            l = sets[i]->num_e, r = sets[i]->num_v;
            if (l > r) ans += (l - r);
        }
    }

    std::cout<<ans<<std::endl;

    return 0;
}