#include <bits/stdc++.h>




/* PLEASE DO NOT CHANGE BELOW*/
int A, B, C, lfsr;
double P[4][4];
int lfsr_generator()
{
    auto ret = lfsr;
    return (lfsr ^= lfsr << 13, lfsr ^= lfsr >> 17, lfsr ^= lfsr << 5, ret);
}

std::tuple<int, int> command()
{
    auto imm = lfsr_generator();
    static int state = 0;
    auto p = double(lfsr_generator() & 0x7fffffff) / INT32_MAX;
    for (int i = 0; i < 4; i++)
        if ((p -= P[state % 4][i]) < 0)
        {
            state += 4 - state % 4 + i;
            break;
        }
    return {state % 4, (imm * A + state * B + C) & 0x7fffffff};
}
/* PLEASE DO NOT CHANGE ABOVE*/


struct AVL
{
    AVL() : imm(0), l_tree(nullptr), r_tree(nullptr), size(0), height(-1), repeated(0){};
    explicit AVL(int const v) : imm(v), l_tree(nullptr), r_tree(nullptr), size(1), height(0), repeated(1){};

    int kth(int k) const;

    int imm, size, height, repeated;

    AVL* l_tree;
    AVL* r_tree;
};


inline int Size(AVL* target)
{
    if (!target) return 0;
    return target->size;
}

inline int Height(AVL* target)
{
    if (!target) return -1;
    return target->height;
}

inline int Repeated(AVL* target)
{
    if (!target) return 0;
    return target->repeated;
}



inline void left_left(AVL* &K2)
{
    AVL* K1 = K2->l_tree;
    K2->l_tree = K1->r_tree;
    K1->r_tree = K2;
    K2->height = std::max(Height(K2->l_tree), Height(K2->r_tree)) + 1;
    K1->height = std::max(Height(K1->l_tree), K2->height) + 1;
    K2->size = Size(K2->l_tree) + Size(K2->r_tree) + Repeated(K2);
    K1->size = Size(K1->l_tree) + K2->size + Repeated(K1);
    K2 = K1;
}

inline void right_right(AVL* &K2)
{
    AVL* K1 = K2->r_tree;
    K2->r_tree = K1->l_tree;
    K1->l_tree = K2;
    K2->height = std::max(Height(K2->r_tree), Height(K2->l_tree)) + 1;
    K1->height = std::max(Height(K1->r_tree), K2->height) + 1;
    K2->size = Size(K2->r_tree) + Size(K2->l_tree) + Repeated(K2);
    K1->size = Size(K1->r_tree) + K2->size + Repeated(K1);
    K2 = K1;
}

inline void left_right(AVL* &K3)
{
    right_right(K3->l_tree);
    left_left(K3);
}

inline void right_left(AVL* &K3)
{
    left_left(K3->r_tree);
    right_right(K3);
}


static void insert(int v, AVL* &target)
{
    if (!target)
    {
        target = new AVL(v);
        return;
    }

    target->size++;

    if (v < target->imm)
    {
        insert(v, target->l_tree);
        if (Height(target->l_tree) - Height(target->r_tree) == 2)
        {
            if (v < target->l_tree->imm) left_left(target);
            else left_right(target);
        }
    }
    else if (v > target->imm)
    {
        insert(v, target->r_tree);
        if (Height(target->r_tree) - Height(target->l_tree) == 2)
        {
            if (v > target->r_tree->imm) right_right(target);
            else right_left(target);
        }
    }
    else    target->repeated++;

    target->height = std::max(Height(target->l_tree), Height(target->r_tree)) + 1;
}

static AVL* pop_which(int v, AVL* &target)
{

    target->size--;
    AVL* result;

    if (v == target->imm)
    {

        if (target->repeated == 1)
        {
            result = target;

            if (!target->r_tree) target = target->l_tree;
            else if (!target->l_tree) target = target->r_tree;
            else
            {
                result = pop_which(target->r_tree->kth(0), target->r_tree);
                target->imm = result->imm;
            }


            if (!target) return result;
        }
        else
        {
            target->repeated --;
            result = new AVL(target->imm);
        }
    }


    else if  (v < target->imm) result = pop_which(v, target->l_tree);
    else result = pop_which(v, target->r_tree);



    if (Height(target->r_tree) - Height(target->l_tree) == 2)
    {
        if (Height(target->r_tree->r_tree) >= Height(target->r_tree->l_tree)) right_right(target);
        else right_left(target);
    }

    if (Height(target->l_tree) - Height(target->r_tree) == 2)
    {
        if (Height(target->l_tree->l_tree) >= Height(target->l_tree->r_tree)) left_left(target);
        else left_right(target);
    }

    target->height = std::max(Height(target->l_tree), Height(target->r_tree)) + 1;

    return result;
}

int AVL::kth(int k) const
{
    if (k >= Size(l_tree) && k < (Size(l_tree) + repeated))  return imm;
    else if (k < Size(l_tree)) return l_tree->kth(k);
    else return r_tree->kth(k - Size(l_tree) - repeated);
}
inline int rank(int v, AVL* target)
{
    if (!target)    return 0;

    if (v == target->imm)   return Size(target->l_tree);
    else if (v < target->imm)   return rank(v, target->l_tree);
    else    return Size(target->l_tree) + rank(v, target->r_tree) + target->repeated;
}

//void print(AVL* node)
//{
//    if (!node) return;
//    std::cout<<node->imm<<' '<<node->size<<' '<<node->height<<' '<<node->repeated<<std::endl;
//    print(node->l_tree);
//    print(node->r_tree);
//}


int main()
{
    AVL* tree = nullptr;
    int m;
    std::cin >> m >> lfsr >> A >> B >> C;
    for (auto & i : P)
        for (double & j : i) std::cin >> j;
    int tans = 0;
    int op, imm;


    for(int i = 0; i < m; ++i)
    {
        //std::cout<<i<<std::endl;
        std::tie(op, imm) = command();
        //std::cout<<op<<' '<<imm<<std::endl;
        if (op == 0) insert(imm, tree);
        if (tree)
        if (op == 1) delete pop_which(tree->kth(imm % Size(tree)), tree);
        if (op == 2) tans ^= rank(imm, tree);
        if (tree)
        if (op == 3) tans ^= tree->kth(imm % Size(tree));
    }
    std::cout << tans << "\n";
//    AVL* tree = nullptr;
//    int m;
//    for (int i = 0; i < 10; ++i)
//    {
//        std::cin >>m;
//        insert(m, tree);
//    }
//
//
//    delete pop_which(6, tree);
//
//    print(tree);
//    std::cout<<tree->size<<std::endl;

}