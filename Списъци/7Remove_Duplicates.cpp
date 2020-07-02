//! Link List: DeleteDuplicates() two realizations
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

void DeleteDuplicates(Node* head)
{
    if(head==nullptr) return;
    Node* current=head;

    while(current->next!=nullptr)
    {
        if(current->data==current->next->data)
        {
            Node* nextNext=current->next->next;
            delete current->next;
            current->next=nextNext;
        }
        else
        {
            current=current->next;
        }
    }
}

void DeleteDuplicates2(Node* head)
{

    Node* current=head;
    Node* temp;
    Node* todelete;
    while(current!=nullptr)
    {
       int value=current->data;
       temp = current->next;
       while(temp!=nullptr && temp->data == value)
       {
           todelete=temp;
           temp=temp->next;
           delete todelete;
       }
       current->next=temp;
       current=current->next;

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
   for (int i=9; i>=1; i--)
   {
       int x;
       cout << "Push an element:";
       cin >> x;
       Insert_begin(head,x);
   }
   PrintList(head);
   DeleteDuplicates2(head);
   PrintList(head);


}
