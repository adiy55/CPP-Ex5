#ifndef CPP_EX5_ITERATOR_HPP
#define CPP_EX5_ITERATOR_HPP

#include "Node.hpp"

/**
 * Base Iterator class for OrgChart Iterators.
 * This class is an abstract class (it is incomplete).
 */

/*
 * https://en.cppreference.com/w/cpp/language/abstract_class
 * "Defines an abstract type which cannot be instantiated, but can be used as a base class."
 * "No objects of an abstract class can be created"
 * "Abstract types cannot be used as parameter types, as function return types, or as the type of an explicit conversion"
 * "Pointers and references to an abstract class can be declared."
 */

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
        virtual Iterator &operator++() = 0; // pure virtual- derived classes must implement

    };

}

#endif //CPP_EX5_ITERATOR_HPP
