//! Link List: FrontBackSplit()
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

void FrontBackSplit(Node* head, Node*& Front, Node*& Back)
{

    if(head==nullptr)
    {
        Front=head;
        Back=nullptr;
    }
    else
    {
        Node* slowptr=head;
        Node* fastptr=head->next;
        while (fastptr!=nullptr)
        {
            fastptr=fastptr->next;
            if(fastptr!=nullptr)
            {
                fastptr=fastptr->next;
                slowptr=slowptr->next;
            }
        }
        Back=slowptr->next;
        slowptr->next=nullptr;
        Front=head;
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
   Node* Front=nullptr;
   Node* Back=nullptr;
   for (int i=9; i>=1; i--)
   {
       Insert_begin(head,i);
   }
   PrintList(head);
   FrontBackSplit(head,Front,Back);
   PrintList(Front);
   PrintList(Back);



}
