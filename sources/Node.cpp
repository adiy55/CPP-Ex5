#include "Node.hpp"
#include <regex>

namespace ariel {

    Node::Node(const std::string &name)
            : _name{name}, _children{} {
    }

    std::ostream &operator<<(std::ostream &out, const Node &node) {
        out << node._name;
        return out;
    }

    std::size_t Node::size() const {
        return 0;
    }


}