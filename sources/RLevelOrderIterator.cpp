#include <queue>
#include <iostream>
#include "RLevelOrderIterator.hpp"

namespace ariel {

    RLevelOrderIterator::RLevelOrderIterator(Node *ptr)
            : Iterator{ptr}, _node_stack{} {
        this->pushLevels(_ptr);
    }

    Iterator &RLevelOrderIterator::operator++() {
        this->next();
        return *this;
    }

    void RLevelOrderIterator::next() {
        if (_node_stack.empty()) {
            _ptr = nullptr;
        } else {
            Node *curr_node = _node_stack.top();
            _node_stack.pop();
            _ptr = curr_node;
        }
    }

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
                std::for_each(children.rbegin(), children.rend(),
                              [&node_queue](Node *child) { node_queue.push(child); });
            }
            _ptr = _node_stack.top();
            _node_stack.pop();
        }
    }
}