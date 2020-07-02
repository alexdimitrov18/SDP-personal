#include <iostream>
#include <cstdlib>
#include <ctime>

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



int Min_Element(BSTNode* root)
{
    if(root==nullptr)
    {
        cout << "The tree is empty." << endl;
        return -1;
    }
    int m=root->data;
    if(root->left==nullptr && root->right==nullptr)
    {
        return m;
    }
    else if (root->left==nullptr)
    {
        int rm=Min_Element(root->right);
        if(rm<m)
        {
            return rm;
        }
        return m;
    }
    else if (root->right==nullptr)
    {
        int lm=Min_Element(root->left);
        if(lm<m)
        {
            return lm;
        }
        return m;
    }
    else
    {
        int lm=Min_Element(root->left);
        int rm=Min_Element(root->right);
        if(lm<m) m=lm;
        if(rm<m) return rm;
        return m;

    }



}

BSTNode* NewNode(int data)
{
    BSTNode* newnode= new BSTNode;
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;

    return newnode;

}



void InsertRandom(BSTNode*& root, int data)
{

    if(root==nullptr)
    {
        root=NewNode(data);
        return;
    }
    int n=rand()%2;
    if(n==0)
    {
        InsertRandom(root->left,data);
    }
    else
    {
        InsertRandom(root->right,data);
    }

}



int main()
{
    srand(time(NULL));
    BSTNode* root = nullptr;
    inOrder(root);
    while(true)
    {
        int i;
        cout << ":";
        cin >> i;
        if(i==0) break;
        InsertRandom(root,i);
        inOrder(root);
        cout << endl;

    }
    cout << Min_Element(root) << endl;

    return 0;
}
