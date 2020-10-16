#include <iostream>
#include <time.h>
#include <math.h>


clock_t start, stop;

double duration;

#define MAXN int(1e4)
#define MAXK 1e5




double fpoly1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++)
    {
        p += (a[i]*pow(x, i));
    }
    return p;
}

double fpoly2 (int n, double a[], double x)
{   
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
    {
        p = a[i-1] + x*p;
    }
    return p;
}

int main()
{
    int i;
    double a[MAXN];

    for (i = 0; i < MAXN; i++)
    {
        a[i] = (double)i;
    }

    start = clock();
    for (i = 0; i < MAXK; i++)
    {
        fpoly1(MAXN - 1, a, 1.1);
    }
    stop = clock();

    duration = ((double)(stop - start))/CLK_TCK/MAXK;
    printf("ticks1 = %f\n", (double)(stop - start));
    printf("duration1 = %6.2e\n", duration);

    start = clock();
    for (i = 0; i < MAXK; i++)
    {
        fpoly2(MAXN - 1, a, 1.1);
    }
    stop = clock();

    duration = ((double)(stop - start))/CLK_TCK/MAXK;
    printf("ticks2 = %f\n", (double)(stop - start));
    printf("duration2 = %6.2e\n", duration);

    return 0;

}
