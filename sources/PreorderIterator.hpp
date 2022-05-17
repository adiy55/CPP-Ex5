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

        void next();

        void pushChildren(Node* node);

    public:

        explicit PreorderIterator(Node *ptr = nullptr);

        Iterator &operator++() override;

    };

}

#endif //CPP_EX5_PREORDERITERATOR_HPP
