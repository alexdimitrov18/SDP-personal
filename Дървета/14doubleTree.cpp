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


void doubleTree(BSTNode* root)
{
   if (root==nullptr) return;
   //! do the subtrees
   doubleTree(root->left);
   doubleTree(root->right);

   //! duplicate this node to its left
   BSTNode* oldLeft = root->left;
   root->left=NewNode(root->data);
   root->left->left=oldLeft;

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
    BSTNode* root = nullptr;
    inOrder(root);
    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        insertrec(root,i);
        inOrder(root);
        cout << endl;

    }
    doubleTree(root);
    inOrder(root);
}
