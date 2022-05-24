#include "PreorderIterator.hpp"
#include <vector>

namespace ariel {

    /**
     * @param ptr Default value is nullptr
     */
    PreorderIterator::PreorderIterator(Node *ptr)
            : Iterator{ptr} {}

    /**
     * Prefix increment.
     * Each increment executes the next iteration of DFS (depth first) traversal.
     */
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

    PreorderIterator PreorderIterator::operator++(int) {
        PreorderIterator tmp{*this};
        ++(*this);
        return tmp;
    }

    /**
     * Private helper function. Adds children to queue in reverse order (first child -> top of stack).
     * @param node parent node
     */
    void PreorderIterator::pushChildren(Node *node) {
        std::vector<Node *> &children = node->getChildren();
        std::for_each(children.rbegin(), children.rend(), [this](Node *child) { _node_stack.push(child); });
    }

}