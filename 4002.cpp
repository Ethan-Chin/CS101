#include <iostream>

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

__uint128_t opt[1001][1001];

//bool cal[1001][1001];

int n, t[1001];

__uint128_t power3(__uint128_t target) {return target*target*target;}

void initialize()
{
    for (int i = 1; i < n; ++i)
    {
        opt[i][i] = 0;
        opt[i][i+1] = 0;
    }
}

//__uint128_t func(int i, int j)
//{
//    if (i+1 >= j) return 0;
//
//    if (cal[i][j]) return opt[i][j];
//
//    cal[i][j] = true;
//
//    __uint128_t result = func(i+1, j) + power3(t[i]+t[i+1]+t[j]);
//
//    opt[i][j] = result;
//
//    for (int k = i + 2; k < j; ++k)
//    {
//        result = func(i, k)+func(k, j) + power3(t[i]+t[k]+t[j]);
//
//        if (opt[i][j] > result) opt[i][j] = result;
//    }
//
//    return opt[i][j];
//};

int main()
{
    Qio::read(n);

    for (int i = 1; i <= n; ++i) Qio::read(t[i]);

    initialize();

    int up_row = (n - 1) / 2;
    int up_col = up_row + 2;

    int dw_row = n / 2;
    int dw_col = dw_row + 2;


    while (up_row >= 1 && dw_col <= n)
    {
        while (up_col <= dw_col)
        {
            __uint128_t result1 = opt[up_row + 1][up_col] + power3(t[up_row] + t[up_row + 1] + t[up_col]), result2 = opt[dw_row + 1][dw_col] + power3(t[dw_row] + t[dw_row + 1] + t[dw_col]);

            opt[up_row][up_col] = result1, opt[dw_row][dw_col] = result2;

            for (int k1 = up_row + 1; k1 < up_col; ++k1)
            {
                result1 = opt[up_row][k1] + opt[k1][up_col] + power3(t[up_row] + t[k1] + t[up_col]);

                if (opt[up_row][up_col] > result1) opt[up_row][up_col] = result1;
            }

            for (int k2 = dw_row + 1; k2 < dw_col; ++k2)
            {
                result2 = opt[dw_row][k2] + opt[k2][dw_col] + power3(t[dw_row] + t[k2] + t[dw_col]);

                if (opt[dw_row][dw_col] > result2) opt[dw_row][dw_col] = result2;
            }

            up_col++;
            dw_row--;
        }


        up_row--;
        up_col = up_row + 2;

        dw_col++;
        dw_row = dw_col - 2;
    }


    Qio::put('\n', opt[1][n]);

    return 0;
}