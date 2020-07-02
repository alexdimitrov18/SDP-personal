#include <iostream>
#include <queue>
using namespace std;


struct BSTNode
{
    char data;
    BSTNode *left, *right;
};

void insertNode(BSTNode *& t, char x)
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

void preOrder(BSTNode* root)
{
  if (root==nullptr) return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(BSTNode* root)
{
  if (root==nullptr) return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}


int main()
{
    BSTNode* root=nullptr;
    insertNode(root, 'F');
    insertNode(root, 'D');
    insertNode(root, 'J');
    insertNode(root, 'B');
    insertNode(root, 'E');
    insertNode(root, 'G');
    insertNode(root, 'K');
    insertNode(root, 'A');
    insertNode(root, 'C');
    insertNode(root, 'I');
    insertNode(root, 'H');
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    return 0;
}
