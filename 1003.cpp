#include <iostream>

unsigned long long base = 4987;
unsigned long long hash_values[int(1e6)];
char queue[int(1e6)];

void insertion_sort(unsigned long long* array, int N)
{
    unsigned long long temp;
    int j;

    for (int i = 1; i < N; i++)
    {
        temp = array[i];
        
        for (j = i; j > 0 && array[j - 1] > temp; j--)
        {
            array[j] = array[j - 1];
        }
        
        array[j] = temp;
    }
    
}

unsigned long long pre_qsort(unsigned long long* array, int first, int last)
{
    int mid = (first + last - 1)/2;

    if (array[first] > array[mid])
    {
        std::swap(array[first], array[mid]);
    }

    if (array[mid] > array[last - 1])
    {
        std::swap(array[mid], array[last - 1]);
    }

    if (array[first] > array[mid])
    {
        std::swap(array[first], array[mid]);
    }

    std::swap(array[mid], array[last - 2]);

    return array[last - 2];
}

void quick_sort(unsigned long long* array, int first, int last)
{
    if (last > first+10)
    {
        int i = first, j = last - 2;
        unsigned long long pivot = pre_qsort(array, first, last);

        while (1)
        {
            while (array[++i] < pivot);
            while (array[--j] > pivot);
            if (i < j)
            {
                std::swap(array[i], array[j]);
            }
            else
            {
                break;
            }
        }
        std::swap(array[i], array[last - 2]);

        quick_sort(array, first, i);
        quick_sort(array, i + 1, last);
    }
    else
    {
        insertion_sort(array + first, last - first);
    }

}




unsigned long long Hash(int * team )
{
    unsigned long long hash_value = 0;
    for (int i = 0; i < 26; i++)
    {
        hash_value  = (hash_value * base) + team[i];
    }

    return hash_value;
    
}


int main()
{
    int n, k, team[26] = {0}, count = 1;

    std::cin>>n>>k>>queue;

    for (int i = 0; i < k; i++)
    {
        team[queue[i] - 'a']++;
    }
    hash_values[0] = Hash(team);

    for (int i = 1; i < n - k + 1; i++)
    {
        team[queue[i - 1] - 'a']--;
        team[queue[i + k - 1] - 'a']++;
        hash_values[i] = Hash(team);
    }

    quick_sort(hash_values, 0, n - k + 1);

    for (int i = 1; i < n - k + 1; i++)
    {
        if (hash_values[i - 1] != hash_values[i])
        {
            count++;
        }
        
    }
    std::cout<<count<<std::endl;


    return 0;
}
