#include <iostream>

int main()
{
    int N = 0, data[int(5e5)][2] = {0}, size = 0, count = 0, i = 0, temp[2] = {0};

    std::cin>>N;

    bool in = true;

    while (1)
    {

        if (in)
        {
            std::cin>>temp[0];
            temp[1] = 0;
            i++;
        }

        if (!size)
        {
            size++;
            data[size - 1][0] = temp[0];
            data[size - 1][1] = temp[1];
            in = true;
            if (i == N)
            {
                break;
            }
            continue;
        }
        
    
        if (temp[0] < data[size - 1][0])
        {
            count += 1;
            size++;
            data[size - 1][0] = temp[0];
            data[size - 1][1] = temp[1];
            in = true;
            if (i == N)
            {
                break;
            }
            
            continue;
        }

        else if (temp[0] == data[size - 1][0])
        {
            temp[1] = data[size - 1][1] + 1;
            if (data[0][0] == temp[0])
            {
                count += temp[1];
            }
            else
            {
                count += (temp[1]+1);
            }
            size++;
            data[size - 1][0] = temp[0];
            data[size - 1][1] = temp[1];
            in = true;
            if (i == N)
            {
                break;
            }
            
            continue;
        }
        
        else
        {
            data[size - 1][1] = 0;
            count++;
            size--;
            in = false;
        }
        
    }
    
    std::cout<<count<<std::endl;

    return 0;
}