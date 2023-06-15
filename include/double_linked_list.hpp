#pragma once
#include <iostream>
#include <tuple>
#include <string>

template <typename T>
struct NodeDoubleLinkedList {
    T value{};
    NodeDoubleLinkedList<T> *prev{nullptr};
    NodeDoubleLinkedList<T> *next{nullptr};
};

template <typename T>
class DoubleLinkedList {
public:
    using DoubleLinkedListForReversedOption = std::tuple<DoubleLinkedList<T>&, bool>;
    friend std::ostream& operator<<(std::ostream & os, DoubleLinkedListForReversedOption const& dll) {
        decltype(auto) double_linked_list = std::get<0>(dll);
        auto reversed = std::get<1>(dll);
        if (reversed) {
            return os << double_linked_list.print_reversed();
        }
        else {
            return os << double_linked_list.print_normal();
        }
    }
    DoubleLinkedList() = default;
    DoubleLinkedList(DoubleLinkedList const&) = delete;
    DoubleLinkedList& operator=(DoubleLinkedList const&) = delete;
    ~DoubleLinkedList();
    template <typename NodeOrT>
    void append_at_begin(NodeOrT arg);
    template <typename NodeOrT>
    void append_at_end(NodeOrT arg);
    void remove_at_begin();
    void remove_at_end();
private:
    void append_at_end_value(T arg);
    void append_at_begin_value(T arg);
    void append_at_end_node(NodeDoubleLinkedList<T> *arg);
    void append_at_begin_node(NodeDoubleLinkedList<T> *arg); 
    std::string print_normal();
    std::string print_reversed();
private:   
    NodeDoubleLinkedList<T> *head{nullptr};
};

// Definitions of private methods
template <typename T>
void DoubleLinkedList<T>::append_at_end_value(T arg) {
    if (!head) {
        head = new NodeDoubleLinkedList<T>{.value=arg};
    }
    else {
        auto temp = head;
        auto prev = temp;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        temp->next = new NodeDoubleLinkedList<T>{.value=arg, .prev=temp};
    }
}

template <typename T>
void DoubleLinkedList<T>::append_at_begin_value(T arg) {
    if (!head) {
        head = new NodeDoubleLinkedList<T>{.value=arg};
    }
    else {
        auto new_node = new NodeDoubleLinkedList<T>{.value=arg, .prev=nullptr, .next=head};
        head->prev = new_node;
        head = head->prev;
    }
}

template <typename T>
void DoubleLinkedList<T>::append_at_end_node(NodeDoubleLinkedList<T> *arg) {
    if (!head) {
        head = arg;
    }
    else {
        auto temp = head;
        auto prev = temp;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        temp->next = arg;
        arg->prev = temp;
    }
}


template <typename T>
void DoubleLinkedList<T>::append_at_begin_node(NodeDoubleLinkedList<T> *arg) {
    if (!head) {
        head = arg;
    }
    else {
        arg->next = head;
        head->prev = arg;
        head = arg;
    }
}

template <typename T>
template <typename NodeOrT>
void DoubleLinkedList<T>::append_at_begin(NodeOrT arg) {
    if constexpr(std::is_same_v<NodeOrT, T>) {
        append_at_begin_value(arg);
    }
    else if constexpr (std::is_same_v<NodeOrT, NodeDoubleLinkedList<T>*>) {
        append_at_begin_node(arg);
    }
}

template <typename T>
template <typename NodeOrT>
void DoubleLinkedList<T>::append_at_end(NodeOrT arg) {
    if constexpr(std::is_same_v<NodeOrT, T>) {
        append_at_end_value(arg);
    }
    else if constexpr (std::is_same_v<NodeOrT, NodeDoubleLinkedList<T>*>) {
        append_at_end_node(arg);
    }
}


template <typename T>
std::string DoubleLinkedList<T>::print_normal() {
    std::string result{};
    if (head) {
        auto temp = head;
        while (temp->next != nullptr) {
            result +=  std::to_string(temp->value) + " -> ";
            temp = temp->next;
        }
        return result += std::to_string(temp->value);
    } else {
        return result += "Double linked list is empty!";
    }
}

template <typename T>
std::string DoubleLinkedList<T>::print_reversed() {
    std::string result{};
    if (head) {
        auto temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp->prev != nullptr) {
            result += std::to_string(temp->value) + " -> ";
            temp = temp->prev;
        }
        return result += std::to_string(temp->value);
    } else {
        return result += "Double linked list is empty!";
    }
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    if (head) {
        auto temp = head;
        if (!head->next) {
            head = nullptr;
            delete temp;
        }
        else {
            auto prev = temp;
            while (temp->next != nullptr) {
                prev = temp;
                temp = temp->next;
                delete prev;
            }
            delete temp;
        }
    }
}
