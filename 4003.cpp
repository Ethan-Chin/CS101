#include <iostream>

int n, nxn[501][501];

bool visited[501];

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


int main()
{
    Qio::read(n);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            Qio::read(nxn[i][j]);

    int min_val = 1001;
    int min_id = 0;
    int count = 1;
    int start = 1;
    Qio::put(' ', 1);

    while (count < n)
    {
        min_val = 1001;

        for (int i = 2; i <= n; ++i)
        {
            if (nxn[start][i] < min_val && !visited[i])
            {
                min_id = i;
                min_val = nxn[start][i];
            }
        }

        Qio::put(' ', min_id);
        visited[min_id] = true;
        start = min_id;
        count++;
    }

    putchar('\n');

    return 0;
}