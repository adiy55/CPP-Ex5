#ifndef CPP_EX5_REVERSELEVELITERATOR_HPP
#define CPP_EX5_REVERSELEVELITERATOR_HPP

#include "LevelOrderIterator.hpp"

namespace ariel {

    class ReverseLevelIterator : public LevelOrderIterator {

    public:

        explicit ReverseLevelIterator(Node *ptr = nullptr);

        Iterator &operator++() override;

    };

}

#endif //CPP_EX5_REVERSELEVELITERATOR_HPP
