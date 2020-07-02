//! Linked List: SortedIntersect()
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

Node* SortedIntersect(Node* a, Node* b)
{
    Node dummy;
    Node* tail=&dummy;
    dummy.next=nullptr;
    while(a!=nullptr && b!=nullptr)
    {
       if(a->data==b->data)
       {
           tail->next = new Node;
           tail=tail->next;
           tail->data=a->data;
           a=a->next;
           b=b->next;
       }
       else if(a->data < b->data)
       {
           a=a->next;
       }
       else
       {
           b=b->next;
       }
    }
    tail->next=nullptr;

    return dummy.next;
}

Node* SortedIntersect2(Node* a, Node* b) //! intersection without duplicates
{
    Node dummy;
    Node* tail=&dummy;
    dummy.next=nullptr;
    int value;
    while(a!=nullptr && b!=nullptr)
    {
       if(a->data==b->data)
       {
           tail->next = new Node;
           tail=tail->next;
           value=a->data;
           tail->data=value;
           while (a!=nullptr && a->data==value)
           {
               a=a->next;
           }
       }
       else if(a->data < b->data)
       {
           a=a->next;
       }
       else
       {
           b=b->next;
       }
    }
    tail->next=nullptr;

    return dummy.next;
}


int main()
{
   Node* a=nullptr;
   Node* b=nullptr;
   int n,x;
   cout << "Enter the number of elements you want to insert:  ";
   cin >> n;
   for (int i=0; i<n; i++)
   {
       cin >> x;
       Push(a,x);
   }
   cout << "Enter the number of elements you want to insert:  ";
   cin >> n;
   for (int i=0; i<n; i++)
   {
       cin >> x;
       Push(b,x);
   }

   PrintList(a);
   PrintList(b);
   Node* head=SortedIntersect2(a,b);
   PrintList(head);


}
