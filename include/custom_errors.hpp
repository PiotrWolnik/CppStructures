#pragma once
#include <stdexcept>

namespace LinkedListErrors {
    struct IsEmpty : public std::exception {
        const char * what() const noexcept override {
            return "List is empty!\n";
        }
    };
};
