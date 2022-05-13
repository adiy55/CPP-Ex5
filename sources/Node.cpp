#include "Node.hpp"

namespace ariel {

    Node::Node() : _name{}, _children{} {}

    Node::Node(const std::string &name) : _name{name} {}

    std::size_t Node::size() const { return 0; }

    std::string Node::getName() const { return _name; }

    bool Node::getVisited() const { return _visited; }

    void Node::setVisited(bool val) { _visited = val; }

    std::vector<Node> &Node::getChildren() { return _children; }

    std::ostream &operator<<(std::ostream &out, const Node &node) {
        return out;
    }

}