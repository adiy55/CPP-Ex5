#ifndef CPP_EX5_PREORDERITERATOR_HPP
#define CPP_EX5_PREORDERITERATOR_HPP

#include "Iterator.hpp"
#include "Node.hpp"
#include <stack>

/*
 * https://en.cppreference.com/w/cpp/container/stack
 * stack top: returns reference to top element.
 * stack pop: removes top element from stack (returns void!)
 */

namespace ariel {

    class PreorderIterator : public Iterator {

    private:

        std::stack<Node *> _node_stack;

        void pushChildren(Node *node);

    public:

        PreorderIterator(Node *ptr = nullptr);

        PreorderIterator &operator++() override;

        PreorderIterator operator++(int);

    };

}

#endif //CPP_EX5_PREORDERITERATOR_HPP
