#include <iostream>

class Node {
public:
	int data;
	Node * next;
	
	Node(int val, Node * nextNode): data(val), next(nextNode)
	{
	}
};

Node * head;


int main()
{
    int N, tallest, shortest, count = 0;
    std::cin>>N;
    int val;
    std::cin>>val;

    head = new Node(val, nullptr);

    for (int i = 1; i < N; i++)
    {
        std::cin>>val;
        head->next = new Node(val, head->next);
        std::swap(head->data, head->next->data);
        Node * ptr = head->next->next;
        tallest = head->next->data;
        count++;
        while (ptr)
        {
            shortest = std::min(head->data, ptr->data);

            if (shortest >= tallest)
            {
                count++;
            }

            else if (head->data < tallest)
            {
                break;
            }
            
            tallest = std::max(tallest, ptr->data);
            ptr = ptr->next;
            
        }
        
    }
    std::cout<<count<<std::endl;
    return 0;
}