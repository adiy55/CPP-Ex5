#include "Iterator.hpp"

namespace ariel {

    Iterator::Iterator(Node *ptr) : _ptr{ptr} {}


    Node &Iterator::operator*() { return *_ptr; }

    Node *Iterator::operator->() { return _ptr; }

    bool Iterator::operator==(const Iterator &other) const {
        return (_ptr == other._ptr);
    }

    bool Iterator::operator!=(const Iterator &other) const {
        return !(this->operator==(other));
    }

    Iterator &Iterator::operator++() {
//        this->next();
        return *this;
    }



}