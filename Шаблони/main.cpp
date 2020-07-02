#include "Stack.h"
#include "Queue.h"

#include <iostream>

template <typename T>
void print(Stack<T> st)
{
    while(!st.empty())
    {
        std::cout << st.top() << " ";
        st.pop();
    }

    std::cout << std::endl;
}

void testStack()
{
    Stack<int> st;
    for(int i = 1; i < 5; ++i)
    {
        st.push(i);
    }

    print(st);
}

template <typename T>
void print(Queue<T> q)
{
    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }

    std::cout << std::endl;
}

void testQueue()
{
    Queue<int> q;
    for (int i = 1; i < 5; ++i)
    {
        q.push(i);
    }

    print(q);
}

int main()
{
    testStack();
    testQueue();

    return 0;
}
