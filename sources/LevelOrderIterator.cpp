#include "LevelOrderIterator.hpp"

namespace ariel {

    LevelOrderIterator::LevelOrderIterator(Node *ptr)
            : Iterator{ptr} {}

    void LevelOrderIterator::pushChildren(Node *node) {
        for (Node *child: node->getChildren()) {
            _node_queue.push(child);
        }
    }

    LevelOrderIterator &LevelOrderIterator::operator++() { // todo: test case for nullptr
        this->pushChildren(_ptr);
        if (_node_queue.empty()) {
            _ptr = nullptr;
        } else {
            _ptr = _node_queue.front();
            _node_queue.pop();
        }
        return *this;
    }

    LevelOrderIterator LevelOrderIterator::operator++(int) {
        LevelOrderIterator tmp{*this}; // todo: check ctor
        ++(*this);
        return tmp;
    }


}