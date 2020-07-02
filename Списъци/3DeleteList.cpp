//! Link List: Delete()
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Insert_begin(Node*& head, int x)
{
    Node* temp= new Node;
    temp->data=x;
    temp->next=head;
    head = temp;
}

void DeleteList(Node*& head)
{
    Node* current=head;
    Node* temp;
    while(current!=nullptr)
    {
        temp=current;
        current=current->next;
        delete temp;
    }
    head=nullptr;
}


void PrintList(Node* head)
{
    cout << "List is : ";
    while(head!=nullptr)
    {
        cout << head->data << "  ";
        head=head->next;
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
       Insert_begin(head,i);
   }
   PrintList(head);
   DeleteList(head);
   PrintList(head);

}
