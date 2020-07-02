//! Link List: MoveNode() AlternatingSplit()
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


void MoveNode(Node*& dest, Node*& source)
{
    if(source!=nullptr)
    {
        Node* temp=source;
        source=source->next;
        temp->next=dest;
        dest=temp;
    }
}

void AlternatingSplit(Node*& source, Node*& first, Node*& second)
{
   first=nullptr;
   second=nullptr;
   while(source!=nullptr)
   {
       MoveNode(first,source);
       if(source!=nullptr)
       MoveNode(second,source);
   }
}

void AlternatingSplit2(Node* source, Node*& first, Node*& second)
{
  Node dummyfirst;
  Node* tailf=&dummyfirst;
  dummyfirst.next=nullptr;

  Node dummysecond;
  Node* tails=&dummysecond;;
  dummysecond.next=nullptr;


  while (source!=nullptr)
  {
      tailf->next=source;
      tailf=source;
      source=source->next;
      if(source!=nullptr)
      {
      tails->next=source;
      tails=source;
      source=source->next;
      }
  }

  tailf->next=nullptr;
  tails->next=nullptr;
  first =dummyfirst.next;
  second=dummysecond.next;
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
   for (int i=10; i>=1; i--)
   {
       Insert_begin(head,i);
   }
   Node* first=nullptr;
   Node* second =nullptr;
   PrintList(head);
   AlternatingSplit(head,first,second);
   PrintList(first);
   PrintList(second);
   PrintList(head);

   Node* head1=nullptr;
   for (int i=11; i>=1; i--)
   {
       Insert_begin(head1,i);
   }
   Node* first1=nullptr;
   Node* second1 =nullptr;
   PrintList(head1);
   AlternatingSplit2(head1,first1,second1);
   PrintList(first1);
   PrintList(second1);
   PrintList(head1);




}
