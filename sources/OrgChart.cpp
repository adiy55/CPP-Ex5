#include "OrgChart.hpp"
#include <queue>

namespace ariel {

    OrgChart::OrgChart() : _root{nullptr} {}

    OrgChart::~OrgChart() {
        std::queue<Node *> node_queue;
        node_queue.push(_root);
        while (!node_queue.empty()) {
            Node *curr_node = node_queue.front();
            node_queue.pop();
            for (Node *child: curr_node->getChildren()) {
                node_queue.push(child);
            }
            delete curr_node;
        }
    }

    OrgChart &OrgChart::add_root(const std::string &root) {
        _root = new Node{root};
        _node_map[root] = _root;
        return *this;
    }

    OrgChart &OrgChart::add_sub(const std::string &parent, const std::string &child) {
        bool found = false;
        for (auto &[key, value]: _node_map) {
            if (key == parent) {
                found = true;
                Node *new_child = new Node(child);
                value->addChild(new_child);
                _node_map[child] = new_child;
                break;
            }
        }
        if (!found) { throw std::runtime_error{"Could not find parent node!"}; }
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const OrgChart &chart) {
        return out;
    }

    LevelOrderIterator OrgChart::begin_level_order() {
        return LevelOrderIterator{_root};
    }

    Iterator OrgChart::end_level_order() {
        return Iterator{}; // default is nullptr
    }

    Iterator OrgChart::begin_reverse_order() {
        return Iterator{_root};
    }

    Iterator OrgChart::reverse_order() {
        return Iterator{};
    }

    Iterator OrgChart::begin_preorder() {
        return Iterator{_root};
    }

    Iterator OrgChart::end_preorder() {
        return Iterator{};
    }

}