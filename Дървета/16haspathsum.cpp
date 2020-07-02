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
bool hasPathSum(BSTNode* root , int sum)
{

    if (root== nullptr)
    {
        return (sum == 0);
    }

    bool ans = false;


    int subSum = sum - root->data;


    if (subSum == 0 && root->left == nullptr && root->right == nullptr) return true;


    if(root->left!=nullptr)
    {
        ans = ans || hasPathSum(root->left, subSum);
    }
    if(root->right)
    {
        ans = ans || hasPathSum(root->right, subSum);
    }
    return ans;

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
    for (int i=0; i<10; i++)
    {
        cout << hasPathSum(root,i) << endl;
    }
    return 0;
}
