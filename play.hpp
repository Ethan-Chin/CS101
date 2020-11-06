#include <iostream>

int num = 0;
int m, n;

bool hav_trv_check[1000001] = {false};

struct Index_node
{
    int which_node;
    int raw_decay;

    Index_node* next_In;

    Index_node(int wn = 0, int rd = 0, Index_node* ni = nullptr) : which_node(wn), raw_decay(rd), next_In(ni){};
};


class Node
{
public:
    int decay;

    Index_node* childs_head;
    Index_node* childs_tail;

    Node(int d = 0, Index_node* ch = nullptr, Index_node* ct = nullptr) : decay(d), childs_head(ch), childs_tail(ct){};


    void check(Index_node* item)
    {
        if (!childs_head)
        {
            childs_head = item;
            childs_tail = item;
        }
        else
        {
            childs_tail->next_In = item;
            childs_tail = item;
        }
        
    };
};

Node* tree[1000001] = {nullptr};

void build_raw_tree()
{
    int l, r, len;

    tree[l] = new Node();
    tree[l] = new Node();


    tree[l]->check(new Index_node(r, len));
    tree[r]->check(new Index_node(l, len));
}

//int main()
//{
//build_raw_tree();
//
//return 0;
//}
