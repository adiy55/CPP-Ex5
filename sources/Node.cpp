#include "Node.hpp"

namespace ariel {

    Node::Node() : _name{}, _children{} {}

    Node::Node(const std::string &name) : _name{name}, _children{} {}

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


}