#ifndef CPP_EX5_ORGCHARTITERATOR_HPP
#define CPP_EX5_ORGCHARTITERATOR_HPP

#include "OrgChart.hpp"
#include "Node.hpp"

namespace ariel {

    class Node;

    class OrgChartIterator { // base iterator

    public:
        using Pointer = Node *;
        using Reference = Node &;
        using Iterator = OrgChartIterator;

    protected:

        Node *_ptr;

    public:

        OrgChartIterator(Pointer ptr);

        Reference operator*();

        Pointer operator->();

        virtual Iterator &operator++();

        virtual Iterator operator++(int);

        virtual Iterator &operator--();

        virtual Iterator operator--(int);

        bool operator==(const Iterator &other) const;

        bool operator!=(const Iterator &other) const;

    };

}

#endif //CPP_EX5_ORGCHARTITERATOR_HPP
