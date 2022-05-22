#include "PreorderIterator.hpp"
#include <stack>

namespace ariel {

    PreorderIterator::PreorderIterator(Node *ptr)
            : Iterator{ptr}, _node_stack{} {
    }

    PreorderIterator &PreorderIterator::operator++() {
        this->pushChildren(_ptr);
        if (_node_stack.empty()) {
            _ptr = nullptr;
        } else {
            _ptr = _node_stack.top();
            _node_stack.pop();
        }
        return *this;
    }

    void PreorderIterator::pushChildren(Node *node) {
        std::vector<Node *> &children = node->getChildren();
        std::for_each(children.rbegin(), children.rend(), [this](Node *child) { _node_stack.push(child); });
    }

}