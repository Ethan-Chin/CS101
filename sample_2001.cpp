#include <iostream>

#include <stack>


using namespace std;
int MaxReduction=0;
struct Node{
int num;//节点编号
int reduction;//到父节点之间 的衰减
int maxReduction;//到所有子节点之间的 最大衰减
bool flag;//是否添加放大器
Node * left;
Node * right;
};
void Create(Node * & root)
{
int t,s;
cin>>t;
if(t==-1)
return;
cin>>s;
root=new Node;
root->num=t;
root->reduction=s;
root->flag=false;
root->maxReduction=0;
root->left=root->right=NULL;
Create(root->left);
Create(root->right);
}
void PostTraverse(Node * root)
{
if(root==NULL)return;
PostTraverse(root->left);
PostTraverse(root->right);
if(root->left)
{
if(root->left->maxReduction+root->left->reduction>=MaxReduction)
root->left->flag=true;
else
{
if(root->left->maxReduction+root->left->reduction>root->maxReduction)
root->maxReduction=root->left->maxReduction+root->left->reduction;
}
}
if(root->right)
{
if(root->right->maxReduction+root->right->reduction>=MaxReduction)
root->right->flag=true;
else
{
if(root->right->maxReduction+root->right->reduction>root->maxReduction)
root->maxReduction=root->right->maxReduction+root->right->reduction;
}
}


}
void Show(Node * root)
{
if(root==NULL)
return;
if(root->flag)
cout<<"节点"<<root->num<<" 放置放大器"<<endl;
Show(root->left);
Show(root->right);

}
int main()
{
cout<<"请输入最大衰减值\n";
cin>>MaxReduction;
cout<<"请输入二叉树\n";
Node * root;
Create(root);
PostTraverse(root);//后序遍历过程中 确定何处加放大器
Show(root);

return 0;

}