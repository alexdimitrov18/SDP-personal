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

int getLeafCount(BSTNode* root)
{
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 1;
    return getLeafCount(root->left)+getLeafCount(root->right);
}

int getcountNodes(BSTNode* root)
{
    if (root==nullptr) return 0;
    return (getcountNodes(root->left)
    + getcountNodes(root->right)+1);
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

   cout << getLeafCount(root) << endl;
   cout << getcountNodes(root) << endl;

    return 0;
}
