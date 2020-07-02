//! Linked List: InsertNth()
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void InsertNth(Node*& head, int index, int x)
{
    Node* temp= new Node;
    temp->data=x;

    if(index==0)
    {
        temp->next=head;
        head=temp;
        return;
    }

    int i=0;
    Node* current=head;
    while(current!=nullptr && i<index-1)
    {
        i++;
        current=current->next;
    }
    if(current!=nullptr && i==index-1)
    {
        temp->next=current->next;
        current->next=temp;
    }
    else
    {
        cerr << "Error. No such index";
        exit(1);
    }
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
   InsertNth(head,0,3);
   PrintList(head);
   InsertNth(head,0,2);
   PrintList(head);
   InsertNth(head,1,4);
   PrintList(head);
   InsertNth(head,3,5);
   PrintList(head);
   InsertNth(head,5,6);
   PrintList(head);


}
