#ifndef CPP_EX5_LEVELORDERITERATOR_HPP
#define CPP_EX5_LEVELORDERITERATOR_HPP

#include "Iterator.hpp"
#include <queue>

namespace ariel {

    class LevelOrderIterator : public Iterator {

    private:
        std::queue<Node *> _node_queue;

        void next();

        void pushChildren(Node* node);

    public:

        explicit LevelOrderIterator(Node* ptr = nullptr);

        Iterator& operator++() override;

    };

}


#endif //CPP_EX5_LEVELORDERITERATOR_HPP
