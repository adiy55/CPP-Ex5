#ifndef CPP_EX5_ITERATOR_HPP
#define CPP_EX5_ITERATOR_HPP

#include "Node.hpp"

namespace ariel {

    class Iterator {

    protected:

        Node *_ptr;

//        virtual void next(); // derived classes must implement this

    public:

        explicit Iterator(Node *ptr = nullptr);

        Node &operator*();

        Node *operator->();

        bool operator==(const Iterator &other) const;

        bool operator!=(const Iterator &other) const;

        virtual Iterator &operator++();



    };

}

#endif //CPP_EX5_ITERATOR_HPP
