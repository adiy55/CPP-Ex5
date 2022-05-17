#include "RLevelOrderIterator.hpp"

namespace ariel {

    RLevelOrderIterator::RLevelOrderIterator(Node *ptr)
            : Iterator{ptr} {
    }

    Iterator &RLevelOrderIterator::operator++() {
        return *this;
    }

}