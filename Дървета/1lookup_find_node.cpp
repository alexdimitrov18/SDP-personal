#include <iostream>
#include <queue>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* NewNode(int data)
{
    BSTNode* newnode= new BSTNode;
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;

    return newnode;

}

bool lookup(BSTNode* root, int target)
{
    if(root==nullptr) return false;
    if(root->data == target)
    {
        return true;
    }
    if(root->data > target)
    {
        return lookup(root->left,target);
    }
    else
    {
        return lookup(root->right, target);
    }
}

BSTNode* findNode(BSTNode *root, int x)
{
    if (root==nullptr) return nullptr;
    if (x==root->data) return root;
    if (x < root->data)
    {
        return findNode(root->left, x);
    }
    else
    {
        return findNode(root->right, x);
    }
}

void insertrec(BSTNode*& root, int data)
{

    if(root==nullptr)
    {
        root=NewNode(data);
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

void inOrder(BSTNode* root)
{
  if (root==nullptr) return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
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

    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        cout << boolalpha << lookup(root,i);
        cout << endl;

    }
    return 0;
}
