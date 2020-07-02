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


bool isSubtreeLesser(BSTNode* root, int x)
{
    if (root==nullptr) return true;
    return root->data<=x
    && isSubtreeLesser(root->left,x)
    && isSubtreeLesser(root->right,x);
}

bool isSubtreeGreater(BSTNode* root, int x)
{
    if (root==nullptr) return true;
    return root->data>x
    && isSubtreeGreater(root->left,x)
    && isSubtreeGreater(root->right,x);
}

bool isBST1(BSTNode* root)
{
    if (root==nullptr) return true;
    return isSubtreeLesser(root->left,root->data)
    && isSubtreeGreater(root->right,root->data)
    && isBST1(root->left)
    && isBST1(root->right);
}

bool isBSTUtil(BSTNode* root, int MinValue, int MaxValue)
{
   if(root==nullptr) return true;
   return (root->data > MinValue && root->data < MaxValue
           && isBSTUtil(root->left, MinValue, root->data)
           && isBSTUtil(root->right,root->data, MaxValue));
}

bool isBST2(BSTNode* root)
{
     return isBSTUtil(root,INT_MIN,INT_MAX);
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
    cout << isBST1(root) << endl;
    cout << isBST2(root) << endl;
    root->data=7;
    cout << isBST1(root) << endl;
    cout << isBST2(root) << endl;
    return 0;
}
