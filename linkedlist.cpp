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
Node * tail;



void InsertBefore(Node * curr, int data)
{
	Node * newNode = new Node(data, curr->next);
    curr->next = newNode;
    std::swap(curr->data, newNode->data);
    
}



void Reverse(Node * &head, Node * &tail) {
		
		std::cout<<"!!!"<<std::endl;
		std::cout<<head<<std::endl;
		std::cout<<head->data<<std::endl;
		std::cout<<head->next<<std::endl;
		std::cout<<&head<<std::endl;
		//std::cout<<type(*&head)<<std::endl;
		std::cout<<"!!!"<<std::endl;
	Node * prevNode = head;

	Node * rotateNode = head->next;
	
	head->next = NULL;

	
	while (rotateNode) {
		
		Node *next = rotateNode->next;
		
		rotateNode->next = prevNode;
		
		prevNode = rotateNode;
		
		rotateNode = next;
		
	}
	
	std::swap(head, tail);
	
}


int main()
{   
	head = new Node(1, nullptr);
	tail = head;
	InsertBefore(head, 3);
	tail = tail->next;
	InsertBefore(head, 99);
	InsertBefore(head, 13232);
	InsertBefore(head, 2333);
	InsertBefore(head, 121);
	std::cout<<"Before Reverse"<<std::endl;
	Node * ptr = head;
	while (ptr)
	{
		std::cout<<ptr->data<<std::endl;

		ptr = ptr->next;

	}
	
	 
    // std::cout<<head->data<<'?'<<head->next->data<<std::endl;
	// std::cout<<tail->data<<std::endl;
	Reverse(head, tail);
	// std::cout<<head->data<<'?'<<head->next->data<<std::endl;
	std::cout<<"After Reverse"<<std::endl;
	ptr = head;
	while (ptr)
	{
		std::cout<<ptr->data<<std::endl;

		ptr = ptr->next;
		
	}

}
// int main()
// {
//     int a = 1;
//     int b = 2;
//     std::swap(a, b);
//     printf("%d, %d\n", a, b);
// }