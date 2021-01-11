#include <iostream>


int desire[500010], sets[500010], m, n;

bool if_add[500010] = {false};

long long times = 0;

struct Edge
{
    int l;
    int r;

    bool operator <(const Edge& e) const { return desire[l] < desire[e.l]; }
    bool operator >(const Edge& e) const { return desire[l] > desire[e.l]; }

    explicit Edge()=default;
    explicit Edge(int in_l, int in_r){ if (desire[in_l] < desire[in_r]) l = in_l, r = in_r; else r = in_l, l = in_r; }
};

Edge edges[1000010];


int find(int i)
{
    if (i != sets[i]) sets[i] = find(sets[i]);
    return sets[i];
}


void insertion_sort(Edge* eds, int N)
{
    Edge temp;
    int j;

    for (int i = 1; i < N; i++)
    {
        temp = eds[i];
        for (j = i; j > 0 && eds[j - 1] < temp; j--) eds[j] = eds[j - 1];
        eds[j] = temp;
    }
}

Edge pre_qsort(Edge* eds, int first, int last)
{
    int mid = (first + last - 1)/2;

    if (eds[first] < eds[mid]) std::swap(eds[first], eds[mid]);

    if (eds[mid] < eds[last - 1]) std::swap(eds[mid], eds[last - 1]);

    if (eds[first] < eds[mid]) std::swap(eds[first], eds[mid]);

    std::swap(eds[mid], eds[last - 2]);

    return eds[last - 2];
}

void quick_sort(Edge *eds, int first, int last)
{
    if (last - first > 10)
    {
        int i = first, j = last - 2;
        Edge pivot = pre_qsort(eds, first, last);

        while (true)
        {
            while (eds[++i] > pivot);
            while (eds[--j] < pivot);
            if (i < j) std::swap(eds[i], eds[j]); else break;
        }

        std::swap(eds[i], eds[last - 2]);

        quick_sort(eds, first, i);
        quick_sort(eds, i + 1, last);
    }
    else insertion_sort(eds + first, last - first);
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::cin>>n>>m;

    for (int i = 1; i <= n; ++i) std::cin>>desire[i], sets[i] = i;

    int l, r, root;

    for (int i = 0; i < m; ++i) std::cin>>l>>r, edges[i] = Edge(l, r);

    quick_sort(edges, 0, m);

    for (int i = 0; i < m; ++i)
    {
        l = find(edges[i].l), r = find(edges[i].r);
        if (l != r) times += desire[r] - desire[edges[i].l], sets[r] = l;
    }

    for (int i = 1; i <= n ; ++i)
    {
        root = find(sets[i]);
        if (!if_add[root]) times += desire[root], if_add[root] = true;
    }

    std::cout<<times<<std::endl;


    return 0;
}


