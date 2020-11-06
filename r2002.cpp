#include <iostream>

int n, size = 0, times = 0;
long long benefit = 0;


struct Stall
{
    int points;
    bool double_sale;

    explicit Stall(int pts = 0, bool ds = false);
};

Stall::Stall(int pts, bool ds) : points(pts), double_sale(ds) {}

Stall* plan[2000010];

void push(Stall* new_item)
{
    size++;
    plan[size] = new_item;

    for (int i = size; i > 1; i = i / 2)
    {
        if (plan[i]->points < plan[i/2]->points)
            std::swap(plan[i], plan[i/2]);
        else if (plan[i]->points == plan[i/2]->points && plan[i]->double_sale && !plan[i/2]->double_sale)
            std::swap(plan[i], plan[i/2]);
        else
            return;
    }


}

void rept(Stall* new_item)
{
    delete plan[1];
    plan[1] = new_item;

    for (int i = 1; i <= size/2;)
    {
        int target = 2*i;

        if (target != size)
        {
            if(plan[target]->points > plan[target+1]->points)
                target++;
            else if (plan[target]->points == plan[target+1]->points && !plan[target]->double_sale && plan[target+1]->double_sale)
                target++;
        }

        if (plan[target]->points < plan[i]->points)
        {
            std::swap(plan[target], plan[i]);
            i = target;
        }
        else if (plan[target]->points == plan[i]->points && plan[target]->double_sale && !plan[i]->double_sale)
        {
            std::swap(plan[target], plan[i]);
            i = target;
        }

        else
            return;
    }

}


int main()
{
    std::cin>>n;

    int st;

    for (int i = 0; i < n; ++i)
    {
        std::cin>>st;

        if (!size)
        {
            plan[1] = new Stall(st);
            size++;
        }
        else if (st <= plan[1]->points)
        {
            push(new Stall(st,false));
        }
        else
        {
            benefit += st - plan[1]->points;

            if (plan[1]->double_sale)
            {
                rept(new Stall(plan[1]->points, false));
                push(new Stall(st,true));
            }

            else
            {
                times+=2;
                rept(new Stall(st,true));
            }

        }

    }

    std::cout<<benefit<<' '<<times<<std::endl;

}
