#ifndef CPP_EX5_ITERATOR_HPP
#define CPP_EX5_ITERATOR_HPP

#include "Node.hpp"

namespace ariel {

    class Iterator {

    protected:

        Node *_ptr;

//        virtual void next() = 0; // derived classes must implement this

    public:

        explicit Iterator(Node *ptr = nullptr);

        std::string &operator*() const;

        std::string *operator->() const;

        bool operator==(const Iterator &other) const;

        bool operator!=(const Iterator &other) const;

        virtual Iterator &operator++() = 0;

    };

}

#endif //CPP_EX5_ITERATOR_HPP
