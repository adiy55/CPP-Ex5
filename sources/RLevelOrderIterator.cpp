#include <queue>
#include "RLevelOrderIterator.hpp"

namespace ariel {

    RLevelOrderIterator::RLevelOrderIterator(Node *ptr)
            : Iterator{ptr} {
        this->pushLevels(_ptr);
    }

    RLevelOrderIterator &RLevelOrderIterator::operator++() {
        if (_node_stack.empty()) {
            _ptr = nullptr;
        } else {
            _ptr = _node_stack.top();
            _node_stack.pop();
        }
        return *this;
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