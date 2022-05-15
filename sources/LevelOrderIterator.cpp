#include "LevelOrderIterator.hpp"

namespace ariel {

    LevelOrderIterator::LevelOrderIterator(Node *ptr)
            : Iterator{ptr}, __node_queue{} {
        __node_queue.push(_ptr);
        this->next();
    }

    void LevelOrderIterator::next() { // todo: test case for nullptr
        if (__node_queue.empty()) {
            _ptr = nullptr;
        } else {
            Node *curr_node = __node_queue.front();
            __node_queue.pop();
            for (Node *child: curr_node->getChildren()) {
                __node_queue.push(child);
            }
            _ptr = curr_node;
        }
    }

    Iterator &LevelOrderIterator::operator++() {
        this->next();
        return *this;
    }

}