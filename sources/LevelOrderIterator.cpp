#include "LevelOrderIterator.hpp"

namespace ariel {

    LevelOrderIterator::LevelOrderIterator(Node *ptr) : Iterator{ptr}, __queue{} {
        __queue.push(_ptr);
    }

    void LevelOrderIterator::next() {
        if (__queue.empty()) {
            _ptr = nullptr;
        } else {
            Node *curr_node = __queue.front();
            __queue.pop();
            for (Node *child: curr_node->getChildren()) {
                __queue.push(child);
            }
            _ptr = curr_node;
        }
    }

    Iterator &LevelOrderIterator::operator++() {
        this->next();
        return Iterator::operator++();
    }


}