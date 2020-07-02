#include <iostream>
#include <queue>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
};

void levelorder(BSTNode* root)
{
    if  (root==nullptr) return;
    queue<BSTNode*> q;
    q.push(root);
    BSTNode* current;
    //! while there is at least one discovered node
    while (!q.empty())
    {
        current=q.front();
        cout << current->data << " ";


        if (current->left!=nullptr)
        {
            q.push(current->left);
        }
        if (current->right!=nullptr)
        {
            q.push(current->right);
        }
        q.pop();
    }
    cout << endl;

}

BSTNode* Newnode(int data)
{
    BSTNode* newnode= new BSTNode;
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}

void CBTfromarray(BSTNode*& root,int a[],int n, int i)
{
    if(i<n)
    {
        root=Newnode(a[i]);
        CBTfromarray(root->left,a,n,2*i+1);
        CBTfromarray(root->right,a,n,2*i+2);
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
    int a[]= {1,2,3,4,5,6,7,8,9};
    int n=9;
    CBTfromarray(root,a,n,0);
    inOrder(root);
    cout<< endl;
    levelorder(root);


    return 0;
}
