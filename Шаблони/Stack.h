#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Node.h"

#include <cassert>

template <typename T>
class Stack
{
    public:
        Stack(): start(nullptr){}
        Stack(const Stack<T>& other);
        Stack<T>& operator = (const Stack<T>& other);
        ~Stack();

        bool empty() const;
        const T& top() const;
        void pop();
        void push(const T&);

    private:
        void clear();
        void copy(const Stack<T>& other);

    private:
        Node<T>* start;
};

template<typename T>
bool Stack<T>::empty() const
{
    return this->start == nullptr;
}

template<typename T>
const T& Stack<T>::top() const
{
    assert(this->start != nullptr);
    return this->start->data;
}

template<typename T>
void Stack<T>::pop()
{
    if(this->start == nullptr)
        return;

    Node<T>* forDelete = this->start;
    this->start = this->start->next;
    delete forDelete;
}

template<typename T>
void Stack<T>::push(const T& elem)
{
    Node<T>* newElem = new Node<T>;
    newElem->data = elem;
    newElem->next = this->start;
    this->start = newElem;
}

template<typename T>
void Stack<T>::clear()
{
    while(!this->empty())
    {
        this->pop();
    }
}

template<typename T>
void Stack<T>::copy(const Stack<T>& other)
{
    if(other.start == nullptr)
    {
        this->start = nullptr;
        return;
    }

    Node<T>* p = other.start;
    Node<T>* newElem, *last = nullptr;

    this->start = new Node<T>;
    this->start->data = p->data;
    this->start->next = nullptr;

    p = p->next;
    last = this->start;

    while(p)
    {
        newElem = new Node<T>;
        newElem->data = p->data;
        newElem->next = nullptr;

        last->next = newElem;
        last = newElem;

        p = p->next;
    }
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    copy(other);
}

template<typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}

template<typename T>
Stack<T>::~Stack()
{
    clear();
}

#endif // STACK_H_INCLUDED
