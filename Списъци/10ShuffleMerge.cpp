//! Linked List: Shuffle()
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

Node* ShuffleMerge(Node* a, Node* b)
{
    Node dummy;
    Node* tail=&dummy;
    dummy.next=nullptr;
    while(true)
    {
        if(a==nullptr)
        {
            tail->next=b;
            break;
        }
        else if(b==nullptr)
        {
            tail->next=a;
            break;
        }
        else
        {
            tail->next=a;
            tail=a;
            a=a->next;
            tail->next=b;
            tail=b;
            b=b->next;
        }
    }
    return dummy.next;
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

void Shuffle(Node*& head)
{

   Node* Front=nullptr;
   Node* Back=nullptr;
   FrontBackSplit(head,Front,Back);
   head=ShuffleMerge(Front, Back);

}



int main()
{
   Node* a=nullptr;
   for (int i=1; i<=10; i++)
   {
       Push(a,i);
   }
   Shuffle(a);
   PrintList(a);
}
