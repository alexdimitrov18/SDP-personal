#include <iostream>
#include <limits>
using namespace std;


struct BSTNode
{
    int data;
    BSTNode *left, *right;
};

void insertNode(BSTNode *& t, int x)
{
    if (t==nullptr)
    {
        t=new BSTNode;
        t->data=x;
        t->left=t->right=nullptr;
    }
    else if (x != t->data)
    {
        if(x<t->data)
        {
             insertNode(t->left,x);
        }
        else
        {
             insertNode(t->right,x);
        }
    }
}

void inOrder(BSTNode* root)
{
  if (root==nullptr) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}



bool isBalanced(BSTNode* root, int& height)
{
    if (root==nullptr)
    {
        height=0;
        return true;
    }

    int hl,hr;
    bool resl=isBalanced(root->left, hl);
    bool resr=isBalanced(root->right, hr);
    if(hl>hr)
    {
        height=hl+1;
    }
    else
    {
        height=hr+1;
    }

    if (hl-hr < -1 || hl-hr > 1) return false;
    return resl && resr;
}




int main()
{
    BSTNode* root=nullptr;

    cout << boolalpha;

    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        insertNode(root,i);
        inOrder(root);
        cout << endl;

    }
    int height;
    cout << isBalanced(root, height) << endl;

    return 0;
}
