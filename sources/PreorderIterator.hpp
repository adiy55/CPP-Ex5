#ifndef CPP_EX5_PREORDERITERATOR_HPP
#define CPP_EX5_PREORDERITERATOR_HPP

#include "Iterator.hpp"
#include <vector>
#include "Node.hpp"
#include <stack>

namespace ariel {

    class PreorderIterator : public Iterator {

    private:

        std::stack<Node *> _node_stack;

        void pushChildren(Node* node);

    public:

        PreorderIterator(Node *ptr = nullptr);

        PreorderIterator &operator++() override;

        PreorderIterator operator++(int);

    };

}

#endif //CPP_EX5_PREORDERITERATOR_HPP
