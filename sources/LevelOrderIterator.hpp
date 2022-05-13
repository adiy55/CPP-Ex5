#ifndef CPP_EX5_LEVELORDERITERATOR_HPP
#define CPP_EX5_LEVELORDERITERATOR_HPP

#include "Iterator.hpp"
#include <queue>

namespace ariel {

    class LevelOrderIterator : public Iterator {

    private:
        std::queue<Node *> __queue;

        void next();

    public:

        explicit LevelOrderIterator(Node* ptr);

        Iterator& operator++() override;

    };

}


#endif //CPP_EX5_LEVELORDERITERATOR_HPP
