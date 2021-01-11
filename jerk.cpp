#include <iostream>


int lo[10000][10000];

int main()
{
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            lo[i][j] = 1;
        }
    }
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            std::cout<<lo[i][j]<<std::endl;
        }
    }
}