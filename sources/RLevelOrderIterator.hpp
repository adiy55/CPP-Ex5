#ifndef CPP_EX5_RLEVELORDERITERATOR_HPP
#define CPP_EX5_RLEVELORDERITERATOR_HPP

#include "Iterator.hpp"

namespace ariel {

    class RLevelOrderIterator : Iterator {

    public:

        explicit RLevelOrderIterator(Node *ptr = nullptr);

        Iterator &operator++() override;

    };

}

#endif //CPP_EX5_RLEVELORDERITERATOR_HPP
