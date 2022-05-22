#ifndef CPP_EX5_ITERATOR_HPP
#define CPP_EX5_ITERATOR_HPP

#include "Node.hpp"

namespace ariel {

    class Iterator {

    protected:

        Node *_ptr;

    public:

        Iterator(Node *ptr);

        std::string &operator*() const;

        std::string *operator->() const;

        bool operator==(const Iterator &other) const;

        bool operator!=(const Iterator &other) const;

        /*
         * https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Covariant_Return_Types
         */
        virtual Iterator &operator++() = 0; // derived classes must implement this

    };

}

#endif //CPP_EX5_ITERATOR_HPP
