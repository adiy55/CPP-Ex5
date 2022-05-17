#include "LevelOrderIterator.hpp"

namespace ariel {

    LevelOrderIterator::LevelOrderIterator(Node *ptr)
            : Iterator{ptr}, _node_queue{} {}

    void LevelOrderIterator::next() { // todo: test case for nullptr
        this->pushChildren(_ptr);
        if (_node_queue.empty()) {
            _ptr = nullptr;
        } else {
            Node *curr_node = _node_queue.front();
            _node_queue.pop();
            _ptr = curr_node;
        }
    }

    void LevelOrderIterator::pushChildren(Node *node) {
        for (Node *child: node->getChildren()) {
            _node_queue.push(child);
        }
    }

    Iterator &LevelOrderIterator::operator++() {
        this->next();
        return *this;
    }

}