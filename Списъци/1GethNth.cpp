//! Linked List: GetNth()
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Push(Node*& head, int x)
{
    Node* temp= new Node;
    temp->data=x;
    temp->next=head;
    head = temp;
}


int GetNth(Node* head, int index)
{
    int count=0;
    Node* current=head;
    while(current!=nullptr && count<index)
    {
      current=current->next;
      count++;
    }
    if (current!=nullptr && count==index) return current->data;
    cerr << "Error. Not such an index position.";
    exit(1);

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
   int n;
   cout << "Enter the number of elements you want to insert:  ";
   cin >> n;
   for (int i=0; i<n; i++)
   {
       Push(head,i);
   }
   PrintList(head);
   int index;
   cout << "Enter index:";
   cin >> index;
   cout << GetNth(head,index);
return 0;
}
