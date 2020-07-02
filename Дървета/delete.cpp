#include <iostream>

using namespace std;


struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
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


bool Delete(BSTNode*& root, int x)
{
    if(root==nullptr) return false;
    if(x < root->data)
    {
        return Delete(root->left,x);
    }
    if(x > root->data)
    {
        return Delete(root->right,x);
    }

    //!At this point root->data==x
    //Lief
    if(root->left==nullptr && root->right==nullptr)
    {
         delete root;
         root=nullptr;
    }
    // One right child
    else if (root->left==nullptr)
    {
          BSTNode* oldroot=root;
          root=root->right;
          delete oldroot;
    }
    // One left child
    else if(root->right==nullptr)
    {
          BSTNode* oldroot=root;
          root=root->left;
          delete oldroot;
    }
    // Two children
    else
    {
        // Find leftmost right leaf
        BSTNode* previous = root;
        BSTNode* current  = root->right;
        while(current->left!=nullptr)
        {
             previous=current;
             current=current->left;
        }
        root->data=current->data;
        if(previous==root)
        {
              previous->right=current->right;
        }
        else
        {
              previous->left=current->right;
        }
        delete current;
     }
     return true;


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
    cout << boolalpha;
    BSTNode* root=nullptr;
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
    /*
    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        cout << Delete(root,i) << endl;
        inOrder(root);
        cout << endl;

    }
    */

    while(root!=nullptr)
    {
        cout << Delete(root,root->data) << endl;
        inOrder(root);
        cout << endl;
    }


    return 0;
}
