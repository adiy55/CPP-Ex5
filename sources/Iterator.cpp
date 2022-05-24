#include "Iterator.hpp"

namespace ariel {

    Iterator::Iterator(Node *ptr)
            : _ptr{ptr} {}

    std::string &Iterator::operator*() const { return _ptr->getName(); }

    std::string *Iterator::operator->() const { return &(_ptr->getName()); }

    bool Iterator::operator==(const Iterator &other) const { return (_ptr == other._ptr); }

    bool Iterator::operator!=(const Iterator &other) const { return !(*this == other); }

    // protected methods for derived classes

    void Iterator::setPointer(Node *ptr) { _ptr = ptr; }

    Node *Iterator::getPointer() const { return _ptr; }

}