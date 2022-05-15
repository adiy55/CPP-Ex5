#include "PreorderIterator.hpp"
#include <stack>
#include <set>

namespace ariel {

    PreorderIterator::PreorderIterator(Node *ptr)
            : Iterator{ptr}, __node_list{}, __index{0} {
        this->dfs(); // setup
    }

    void PreorderIterator::dfs() {
        std::set<Node const *> visited_nodes;
        std::stack<Node *> node_stack;
        visited_nodes.insert(_ptr);
        node_stack.push(_ptr);
        while (!node_stack.empty()) {
            Node *curr_node = node_stack.top();
            node_stack.pop();
            __node_list.push_back(curr_node);
            std::vector<Node *> &children = curr_node->getChildren();
            for (int i = children.size() - 1; i >= 0; --i) {
                Node *child = children[static_cast<std::size_t>(i)];
                if (visited_nodes.count(child) == 0) {
                    visited_nodes.insert(child);
                    node_stack.push(child);
                }
            }
        }
    }

    Iterator &PreorderIterator::operator++() {
        ++__index;
        if (__index == __node_list.size()) { _ptr = nullptr; }
        else { _ptr = __node_list[__index]; }
        return *this;
    }

}