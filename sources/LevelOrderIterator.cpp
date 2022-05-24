#include "LevelOrderIterator.hpp"

namespace ariel {

    /**
     * @param ptr Default value is nullptr
     */
    LevelOrderIterator::LevelOrderIterator(Node *ptr)
            : Iterator{ptr} {}


    /**
     * Prefix increment.
     * Each increment executes the next iteration of BFS (level order) traversal.
     */
    LevelOrderIterator &LevelOrderIterator::operator++() {
        this->pushChildren(this->getPointer()); // add children nodes of current node
        if (_node_queue.empty()) {
            this->setPointer(nullptr);
        } else { // update pointer to next node in queue
            this->setPointer(_node_queue.front());
            _node_queue.pop();
        }
        return *this;
    }

    LevelOrderIterator LevelOrderIterator::operator++(int) {
        LevelOrderIterator tmp{*this};
        ++(*this);
        return tmp;
    }

    /**
     * Private helper function. Adds children to queue.
     * @param node parent node
     */
    void LevelOrderIterator::pushChildren(Node *node) {
        for (Node *child: node->getChildren()) {
            _node_queue.push(child);
        }
    }

}