#ifndef CPP_EX5_LEVELORDERITERATOR_HPP
#define CPP_EX5_LEVELORDERITERATOR_HPP

#include "Iterator.hpp"
#include <queue>

namespace ariel {

    class LevelOrderIterator : public Iterator {

    private:
        std::queue<Node *> _node_queue;

        void pushChildren(Node* node);

    public:

        LevelOrderIterator(Node* ptr = nullptr);

        LevelOrderIterator& operator++() override;

        LevelOrderIterator operator++(int);

    };

}


#endif //CPP_EX5_LEVELORDERITERATOR_HPP
