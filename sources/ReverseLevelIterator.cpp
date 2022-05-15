#include "ReverseLevelIterator.hpp"

namespace ariel {

    ReverseLevelIterator::ReverseLevelIterator(Node *ptr)
            : LevelOrderIterator{ptr} {
        _index = _node_list.size() - 1;
        _ptr = _node_list[static_cast<unsigned int>(_index)];
    }

    Iterator &ReverseLevelIterator::operator++() {
        --_index;
        if (_index == -1) { _ptr = nullptr; }
        else { _ptr = _node_list[static_cast<unsigned int>(_index)]; }
        return *this;
    }

}