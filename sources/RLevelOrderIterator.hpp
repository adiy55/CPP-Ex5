#ifndef CPP_EX5_RLEVELORDERITERATOR_HPP
#define CPP_EX5_RLEVELORDERITERATOR_HPP

#include "Iterator.hpp"
#include <stack>

namespace ariel {

    class RLevelOrderIterator : public Iterator {

    private:

        std::stack<Node *> _node_stack;

        void pushLevels(Node *node);

    public:

        RLevelOrderIterator(Node *ptr = nullptr);

        RLevelOrderIterator &operator++() override;

    };

}

#endif //CPP_EX5_RLEVELORDERITERATOR_HPP
