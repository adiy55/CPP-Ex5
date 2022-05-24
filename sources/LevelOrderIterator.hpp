#ifndef CPP_EX5_LEVELORDERITERATOR_HPP
#define CPP_EX5_LEVELORDERITERATOR_HPP

#include "Iterator.hpp"
#include <queue>

/*
 * https://en.cppreference.com/w/cpp/container/queue
 * queue front: returns reference to first element.
 * queue pop: removes first element from queue (returns void!)
 */

namespace ariel {

    class LevelOrderIterator : public Iterator {

    private:
        std::queue<Node *> _node_queue;

        void pushChildren(Node *node);

    public:

        LevelOrderIterator(Node *ptr = nullptr);

        LevelOrderIterator &operator++() override;

        LevelOrderIterator operator++(int);

    };

}


#endif //CPP_EX5_LEVELORDERITERATOR_HPP
