#include "RLevelOrderIterator.hpp"
#include <queue>

namespace ariel {

    /**
     * @param ptr Default value is nullptr
     */
    RLevelOrderIterator::RLevelOrderIterator(Node *ptr)
            : Iterator{ptr} {
        this->pushLevels(this->getPointer());
    }

    /**
     * Prefix increment.
     * Each increment removes top node in the stack.
     */
    RLevelOrderIterator &RLevelOrderIterator::operator++() {
        if (_node_stack.empty()) {
            this->setPointer(nullptr);
        } else {
            this->setPointer(_node_stack.top());
            _node_stack.pop();
        }
        return *this;
    }

    RLevelOrderIterator RLevelOrderIterator::operator++(int) {
        RLevelOrderIterator tmp{*this};
        ++(*this);
        return tmp;
    }

    /**
     * Helper function- insert node pointers to stack in reverse BFS order.
     * @param node
     */
    void RLevelOrderIterator::pushLevels(Node *node) {
        if (node != nullptr) {
            std::queue<Node *> node_queue;
            node_queue.push(node);
            Node *curr_node = nullptr;
            while (!node_queue.empty()) {
                curr_node = node_queue.front();
                _node_stack.push(curr_node);
                node_queue.pop();
                std::vector<Node *> children = curr_node->getChildren();
                // add children to queue in reverse order -> order in stack will be from left to right
                std::for_each(children.rbegin(), children.rend(),
                              [&node_queue](Node *child) { node_queue.push(child); });
            }
            this->setPointer(_node_stack.top()); // init pointer to first element
            _node_stack.pop();
        }
    }
}