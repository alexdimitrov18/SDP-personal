//! Link List: SortedMerge() FrontBackSplit() MergeSort()
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

Node* SortedMerge(Node* a, Node* b)
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
        if(a->data < b->data)
        {
            tail->next=a;
            tail=a;
            a=a->next;
        }
        else
        {
            tail->next=b;
            tail=b;
            b=b->next;
        }
    }

    return dummy.next;
}

void FrontBackSplit(Node* head, Node*& Front, Node*& Back)
{

    if(head==nullptr) //length<2 cases
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

void MergeSort(Node*& head)
{
   if(head==nullptr || head->next==nullptr) return;
   Node* Front=nullptr;
   Node* Back=nullptr;
   FrontBackSplit(head,Front,Back);
   MergeSort(Front);
   MergeSort(Back);
   head=SortedMerge(Front,Back);

}




int main()
{
   Node* a=nullptr;
   for (int i=2; i>=-3; i--)
   {
       Insert_begin(a,i);
   }
   Node* b=nullptr;
   for (int i=-1; i>=-5; i--)
   {
       Insert_begin(b,i);
   }
   PrintList(a);
   PrintList(b);
   Node* head1=SortedMerge(a,b);
   PrintList(head1);

   Node*head=nullptr;
   for(int i=1;i<=10;i++)
   {
       int x;
       cout << "Push new element: ";
       cin >> x;
       Insert_begin(head,x);
   }
   PrintList(head);
   MergeSort(head);
   PrintList(head);

}
