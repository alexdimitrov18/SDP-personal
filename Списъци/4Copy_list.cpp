//! Link List: CopyList()
#include <iostream>
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


Node* CopyList(Node* head)
{
    Node dummy;
    Node* tail=&dummy;
    dummy.link=nullptr;
    while(head!=nullptr)
    {
        tail->link=new Node;
        tail=tail->link;
        tail->data=head->data;
        head=head->link;
    }
    tail->link=nullptr;
    return dummy.link;
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

   Node* newList=CopyList(head);
   PrintList(newList);
}
