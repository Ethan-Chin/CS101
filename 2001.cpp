#include <iostream>

int num = 0;
int m, n;

bool hav_trv_check[1000001] = {false};


struct Index_node
{
    int which_node;
    int raw_decay;

    Index_node* next_In;

    Index_node(int wn = 0, int rd = 0) : which_node(wn), raw_decay(rd), next_In(nullptr){};
};


class Node
{
public:

    int decay;
    int max_decay;

    Index_node* childs_head;
    Index_node* childs_tail;

    Node() : decay(0), max_decay(0), childs_head(nullptr), childs_tail(nullptr){};

    void push_back(Index_node* item)
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


    void remv_next(Index_node* pre_item)
    {
        Index_node* temp = pre_item->next_In;
        pre_item->next_In = temp->next_In;
        if (childs_tail == temp)
        {
            childs_tail = pre_item;
        }
        delete temp;
    };

    void remv_frst()
    {
        Index_node* fst_item = childs_head;
        childs_head = childs_head->next_In;
        if (childs_tail == fst_item)
        {
            childs_tail = nullptr;
        }
        delete fst_item;
    };
};


Node* tree[1000001] = {nullptr};


void build_raw_tree()
{
    int l, r, len;

    for (int i = 1; i < n; i++)
    {
        std::cin>>l>>r>>len;

        if (!tree[l])
        {
            tree[l] = new Node();
        }
        if (!tree[r])
        {
            tree[r] = new Node();
        }

        tree[l]->push_back(new Index_node(r, len));
        tree[r]->push_back(new Index_node(l, len));
    }
}


void build_tree(Node* cur, int dcy)
{

    Index_node* ptr = cur->childs_head;
    Index_node* ptr_nxt = ptr;

    cur->decay = dcy;

    if (!ptr)
    {
        return;
    }


    while (hav_trv_check[ptr->which_node])
    {
        ptr = ptr->next_In;
        cur->remv_frst();
        if (!ptr)
            break;
    }

    while (ptr)
    {
        ptr_nxt = ptr->next_In;

        hav_trv_check[ptr->which_node] = true;
        build_tree(tree[ptr->which_node], ptr->raw_decay);

        if (!ptr_nxt)
        {
            return;
        }
        
        if (hav_trv_check[ptr_nxt->which_node])
        {
            cur->remv_next(ptr);
        }
        else
        {
            ptr = ptr->next_In;
        }
    }
}


void count(Node* cur)
{

    Index_node* ptr = cur->childs_head;

    while (ptr)
    {
        count(tree[ptr->which_node]);

        int md = tree[ptr->which_node]->max_decay;
        int n = tree[ptr->which_node]->decay;

        if (md+n >= m)
        {
            if (tree[ptr->which_node]->childs_head)
            {
                num++;
                md = 0;

            }
            else
            {
                throw "E";
            }  
        }

        if (md+n > cur->max_decay)
        {
            cur->max_decay = md+n;
        }  

        ptr = ptr->next_In;
    }
    if (cur->max_decay > m)
    {
        throw "E";
    }
}


int main()
{

    std::cin>>n;

    build_raw_tree();


    hav_trv_check[1] = true;
    build_tree(tree[1], 0);
    
    std::cin>>m;

    try
    {
        count(tree[1]);
        std::cout<<num<<std::endl;
    }
    catch(...)
    {
        std::cout<<"No solution."<<std::endl;
    }

    return 0;
}