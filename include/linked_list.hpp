#pragma once
#include "custom_errors.hpp"
#include <iostream>

template <typename T>
struct NodeLinkedList {
    T value{}; // The type T shall be equipped with default constructor   
    NodeLinkedList<T> * next{nullptr};
};

template <typename T>
class LinkedList {
public:
    LinkedList() = default;
    ~LinkedList();
    LinkedList(LinkedList const&) = delete; // We don't want copy operation
    LinkedList & operator=(LinkedList const&) = delete;
    template<typename NodeOrT>
    void append(NodeOrT value);
    void remove();
    template <typename Type>
    friend std::ostream & operator<<(std::ostream & os, LinkedList<Type> const& linked_list);
private:
    void append_value(T value);
    void append_node(NodeLinkedList<T>* node);
private:
    NodeLinkedList<T> *head{nullptr};
};

template <typename T>
void LinkedList<T>::append_value(T value) {
    if (!head) {
        head = new NodeLinkedList<T>{.value=value};
    }
    else {
        auto temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new NodeLinkedList<T>{.value=value};
    }
}

template <typename T>
void LinkedList<T>::append_node(NodeLinkedList<T>* node) {
    if (!head) {
        head = node;
    }
    else {
        auto temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

template <typename T>
void LinkedList<T>::remove() {
    if (head) {
        auto temp = head;
        if (!head->next) {
            head = nullptr;
            delete temp;
        }
        else {
            auto temp = head;
            auto prev = temp;
            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == head) {
                head = nullptr;
            }
            else {
                prev->next = nullptr;
            }
            delete temp;
        }
    }
    else {
        throw LinkedListErrors::IsEmpty();
    }
}

template <typename T> 
template <typename NodeOrT>
void LinkedList<T>::append(NodeOrT value) {
    if constexpr (std::is_same_v<NodeOrT, T>) {
        this->append_value(value);
    }
    else if constexpr (std::is_same_v<NodeOrT, NodeLinkedList<T>*>) {
        this->append_node(value);
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr)
        this->remove();
}

template <typename T>
std::ostream & operator<<(std::ostream & os, LinkedList<T> const& linked_list) {
    if (linked_list.head) {
        auto temp = linked_list.head;
        while (temp->next!= nullptr) {
            os << temp->value << " -> ";
            temp = temp->next;
        }
        return os << temp->value;
    }
    return os << "List is empty!";
}
