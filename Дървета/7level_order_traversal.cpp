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

    levelorder(root);

    return 0;
}
