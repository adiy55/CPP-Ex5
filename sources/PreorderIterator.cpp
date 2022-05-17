#include "PreorderIterator.hpp"
#include <stack>

namespace ariel {

    PreorderIterator::PreorderIterator(Node *ptr)
            : Iterator{ptr}, _node_stack{} {
    }


    Iterator &PreorderIterator::operator++() {
        this->next();
        return *this;
    }

    void PreorderIterator::next() {
        this->pushChildren(_ptr);
        if (_node_stack.empty()) {
            _ptr = nullptr;
        } else {
            Node *curr_node = _node_stack.top();
            _node_stack.pop();
            _ptr = curr_node;
        }
    }

    void PreorderIterator::pushChildren(Node *node) {
        std::vector<Node *> &children = node->getChildren();
        std::for_each(children.rbegin(), children.rend(), [this](Node *child) { _node_stack.push(child); });
    }

}