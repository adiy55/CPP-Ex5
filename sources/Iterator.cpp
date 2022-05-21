#include "Iterator.hpp"

namespace ariel {

    Iterator::Iterator(Node *ptr)
            : _ptr{ptr} {}

    std::string &Iterator::operator*() const { return _ptr->getName(); }

    std::string *Iterator::operator->() const { return &(_ptr->getName()); }

    bool Iterator::operator==(const Iterator &other) const {
        return (_ptr == other._ptr);
    }

    bool Iterator::operator!=(const Iterator &other) const {
        return !(this->operator==(other));
    }

//    Iterator &Iterator::operator++() {
//        this->next();
//        return *this;
//    }


}