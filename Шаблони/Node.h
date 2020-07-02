#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <typename T>
struct Node
{
    T data{};
    Node<T>* next{ nullptr };

    Node() = default;
    Node(const T& newData, Node<T>* link) : data(newData), next(link) {}
};

#endif // !NODE_H_INCLUDED
