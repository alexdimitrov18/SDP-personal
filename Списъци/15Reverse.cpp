#include <iostream>
#include <stack>
using namespace std;


struct Node
{
    int data;
    Node* link;
};

void Insert(Node*& head, int x)
{
    Node* temp= new Node;
    temp->data=x;
    temp->link=head;
    head = temp;
}



void recursiveReverse(Node*& head)
{
    if (head==nullptr || head->link==nullptr) return;

    Node *next=head->link;
    recursiveReverse(next);
    head->link->link=head;
    head->link=nullptr;
    head=next;

}

void iterativeReverse(Node*& head)
{
    Node* result=nullptr;
    Node* current=head;
    Node* next;
    while(current!=nullptr)
    {
        next=current->link;
        current->link=result;
        result=current;
        current=next;
    }
    head=result;
}



void stackReverse(Node*& head)
{
    if (head==nullptr)
    {
        return;
    }
    Node* temp=head;
    stack<Node*> st;
    while(temp->link!=nullptr)
    {
        st.push(temp);
        temp=temp->link;
    }
    head=temp;
    while(!st.empty())
    {
        temp->link=st.top();
        st.pop();
        temp=temp->link;
    }
    temp->link=nullptr;
}

void PrintList(Node* head)
{
    cout << "List is : ";
    while(head!=nullptr)
    {
        cout << head->data << "  ";
        head=head->link;
    }
    cout << endl;
}

int main()
{
   Node* head=nullptr;
   int x,n;
   cout << "Enter the number of elements you want to insert:  ";
   cin >> n;
   for (int i=0; i<n; i++)
   {
       cout << "Enter new data:  ";
       cin >> x;
       Insert(head,x);
       PrintList(head);
   }
   recursiveReverse(head);
   PrintList(head);
   iterativeReverse(head);
   PrintList(head);
   stackReverse(head);
   PrintList(head);
}
