#include "Node.hpp"
#include <regex>

namespace ariel {

    Node::Node(const std::string &name)
            : _name{name}, _children{} {
        validateName(_name);
    }

    void Node::addChild(Node *child) {
        _children.push_back(child);
    }

    std::vector<Node *> &Node::getChildren() { return _children; }

    std::ostream &operator<<(std::ostream &out, const Node &node) {
        out << node._name;
        return out;
    }

    std::size_t Node::size() const {
        return 0;
    }

    void Node::validateName(const std::string &name) {
        std::regex valid_format{R"([a-zA-z_]+)"};
        // regex_match checks for a full match
        if (!std::regex_match(name, valid_format)) { throw std::invalid_argument{"Invalid name!"}; }
    }


}