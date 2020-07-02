#include <iostream>
using namespace std;

struct Node
{
        int data;
        Node *next;
};
void push(Node ** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void Print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void append(Node *first, Node **second)
{
    Node *firstRef = first;

    while (firstRef->next != NULL)
    {
         firstRef = firstRef->next;
    }

    firstRef->next = *second;
}
int main()
{
    Node *first = NULL, *second = NULL;
    push(&first, 5);
    push(&first, 4);
    push(&first, 3);
    push(&first, 2);
    push(&first, 1);
    cout<<"First Linked List:\n";
    Print(first);

    push(&second, 10);
    push(&second, 9);
    push(&second, 8);
    push(&second, 7);
    push(&second, 6);
    cout<<"\nSecond Linked List:\n";
    Print(second);

    append(first, &second);
    cout<<"\nappendd list is: ";
    Print(first);

    return 0;
}
