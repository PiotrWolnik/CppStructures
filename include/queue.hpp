#pragma once
#include <iostream>
#include "custom_errors.hpp"

template <typename T>
struct Node {
    T value{};
    Node<T> * next{nullptr};
};

template <typename T>
class Queue {
public:
    Queue() = default;
    Queue(Queue const&) = delete;
    Queue& operator=(Queue const&) = delete;
    template <typename NodeOrT>
    void append(NodeOrT arg);
    void remove();
    ~Queue();
    template <typename Type>
    friend std::ostream& operator<<(std::ostream& os, Queue<Type> const& queue);
private:
    Node<T> * head{nullptr};
};

template <typename T>
template <typename NodeOrT>
void Queue<T>::append(NodeOrT arg) {
    if constexpr (std::is_same_v<NodeOrT, T>) {
        if (!head) {
            head = new Node<T>{.value=arg};
        }
        else {
            auto temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = new Node<T>{.value=arg};
        }
    }
    else if constexpr (std::is_same_v<NodeOrT, Node<T>*>) {
        if (!head) {
            head = arg;
        }
        else {
            auto temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = arg;
        }
    }
}

template <typename T>
void Queue<T>::remove() {
    if (!head) {
        throw QueueErrors::IsEmpty();
    }
    else {
        auto temp = head;
        if (!head->next) {
            head = nullptr;
        } else {
            head = head->next;
            temp->next = nullptr;
        }
        delete temp;
        
    }
}

template <typename T>
Queue<T>::~Queue() {
    if (head) {
        auto temp = head;
        while (temp->next != nullptr)
            remove();
        delete head;
    }
}

template <typename Type>
std::ostream& operator<<(std::ostream& os, Queue<Type> const& queue) {
    if (!queue.head) {
        return os << "Queue is empty!";
    } else {
        auto temp = queue.head;
        while (temp->next != nullptr) {
            os << temp->value << " -> ";
            temp = temp->next;
        }
        return os << temp->value;
    }
}
