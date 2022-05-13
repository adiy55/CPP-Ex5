#include "Node.hpp"

namespace ariel {

    Node::Node() : _name{}, _children{} {}

    Node::Node(const std::string &name) : _name{name}, _children{} {}

    void Node::addChild(Node *child) {
        _children.push_back(child);
    }


}