#include <iostream>

void insertion_sort(int* array, int N)
{
    int temp, j;

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

int pre_qsort(int* array, int first, int last)
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

void quick_sort(int* array, int first, int last)
{
    if (last - first > 10)
    {
        int i = first, j = last - 2;
        int pivot = pre_qsort(array, first, last);

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


int main()
{
    int n, k, ages[int(1e6)], diff[int(1e6)], sum = 0;

    std::cin>>n>>k;

    for (int i = 0; i < n; i++)
    {
        std::cin>>ages[i];
    }
    quick_sort(ages, 0, n);

    for (int i = 0; i < n - 1; i++)
    {
        diff[i] = ages[i+1] - ages[i];
    }
    quick_sort(diff, 0, n-1);

    for (int i = 0; i < k; i++)
    {
        sum += diff[i];
    }

    std::cout<<sum<<std::endl;

    return 0;
}
