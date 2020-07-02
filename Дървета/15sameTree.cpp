#include <iostream>

using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

void inOrder(BSTNode* root)
{
  if (root==nullptr) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

BSTNode* NewNode(int data)
{
    BSTNode* newnode=new BSTNode;
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;

    return newnode;

}


bool sameTree(BSTNode* a, BSTNode* b)
{
   if(a==nullptr && b==nullptr) return true;

   if(a!=nullptr && b!=nullptr)
   {
        return a->data == b->data && sameTree(a->left, b->left) && sameTree(a->right, b->right);
   }

   return false;

}

void insertrec(BSTNode*& root, int data)
{

    if(root==nullptr)
    {
        BSTNode* newnode= new BSTNode;
        newnode->data=data;
        newnode->left=nullptr;
        newnode->right=nullptr;
        root=newnode;
        return;
    }
    if(data<=root->data)
    {
        insertrec(root->left,data);
    }
    else
    {
        insertrec(root->right,data);
    }

}



int main()
{
    BSTNode* root1 = nullptr;
    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        insertrec(root1,i);
        inOrder(root1);
        cout << endl;

    }
    BSTNode* root2 = nullptr;
    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        insertrec(root2,i);
        inOrder(root2);
        cout << endl;

    }
    cout << boolalpha << sameTree(root1,root2);

}
