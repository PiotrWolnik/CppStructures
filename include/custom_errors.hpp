#pragma once
#include <stdexcept>

namespace LinkedListErrors {
    struct IsEmpty : public std::exception {
        const char * what() const noexcept override {
            return "List is empty!\n";
        }
    };
};

namespace DoubleLinkedListErrors {
    struct IsEmpty : public std::exception {
        const char * what() const noexcept override {
            return "DoubleLinkedList is empty!\n";
        }
    };
};

namespace QueueErrors {
    struct IsEmpty : public std::exception {
        const char * what() const noexcept override {
            return "Queue is empty!\n";
        }
    };
};
