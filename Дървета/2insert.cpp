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
    BSTNode* newnode= new BSTNode;
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;

    return newnode;

}

void insert(BSTNode*& root, int data)
{
    BSTNode* newnode= NewNode(data);
    if(root==nullptr)
    {
        root=newnode;
        return;
    }
    BSTNode* current=root;
    BSTNode* previous=nullptr;

    while(current!=nullptr)
    {
        previous=current;
        if(data<=current->data)
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }
    }
    if(data <= previous->data)
    {
        previous->left=newnode;
    }
    else
    {
        previous->right=newnode;
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

void insertrec2(BSTNode *& root, int x)
{
    if (root==nullptr)
    {
        root=NewNode(x);
        return;
    }

    if (x != root->data)
    {
        if(x < root->data)
        {
             insertrec2(root->left,x);
        }
        else
        {
             insertrec2(root->right,x);
        }
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
        insertrec2(root,i);
        inOrder(root);
        cout << endl;

    }

    return 0;
}
