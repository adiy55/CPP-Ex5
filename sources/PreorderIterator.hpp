#ifndef CPP_EX5_PREORDERITERATOR_HPP
#define CPP_EX5_PREORDERITERATOR_HPP

#include "Iterator.hpp"
#include <vector>
#include "Node.hpp"

namespace ariel {

    class PreorderIterator : public Iterator {

    private:

        std::vector<Node *> __node_list;

        std::size_t __index;

        void dfs();

    public:

        PreorderIterator(Node *ptr);

        Iterator &operator++() override;

    };

}

#endif //CPP_EX5_PREORDERITERATOR_HPP
