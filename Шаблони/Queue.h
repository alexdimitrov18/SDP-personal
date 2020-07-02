#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "Node.h"

#include <cassert>

template <typename T>
class Queue
{
    public:
        Queue() = default;
        Queue(const Queue<T>& other);
        Queue<T>& operator = (const Queue<T>& other);
        ~Queue();

        bool empty() const;
        const T& front() const;
        void pop();
        void push(const T&);

    private:
        void clear();
        void copy(const Queue<T>& other);

    private:
        Node<T>* start{nullptr};
        Node<T>* end{nullptr};
};

template <typename T>
bool Queue<T>::empty() const
{
    return this->start == nullptr;
}

template <typename T>
const T& Queue<T>::front() const
{
    assert(this->start != nullptr);
    return this->start->data;
}

template <typename T>
void Queue<T>::pop()
{
    if(this->start == nullptr)
        return;

    Node<T>* forDelete = this->start;
    this->start = this->start->next;

    if(this->start == nullptr)
    {
        this->end = nullptr;
    }

    delete forDelete;
}

template <typename T>
void Queue<T>::push(const T& elem)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = elem;
    newNode->next = nullptr;

    if(this->start == nullptr)
    {
        this->start = newNode;
        this->end = newNode;
    }
    else
    {
        this->end->next = newNode;
        this->end = newNode;
    }
}

template <typename T>
void Queue<T>::clear()
{
    while(!this->empty())
    {
        this->pop();
    }
}

template <typename T>
void Queue<T>::copy(const Queue<T>& other)
{
    Node<T>* p = other.start;
    while(p)
    {
        this->push(p->data);
        p = p->next;
    }
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    copy(other);
}

template<typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}

template<typename T>
Queue<T>::~Queue()
{
    clear();
}

#endif // QUEUE_H_INCLUDED
