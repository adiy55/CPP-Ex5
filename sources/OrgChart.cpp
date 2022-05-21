#include "OrgChart.hpp"
#include <queue>
#include <iostream>

namespace ariel {

    OrgChart::OrgChart() : _root{nullptr} {}

    OrgChart::OrgChart(const OrgChart &chart) {
        _root = nullptr;
        std::queue<Node *> node_queue;
        Node *curr_node = nullptr;
        if (chart._root != nullptr) {
            this->add_root(chart._root->getName());
            node_queue.push(chart._root);
            while (!node_queue.empty()) {
                curr_node = node_queue.front();
                node_queue.pop();
                for (Node *child: curr_node->getChildren()) {
                    node_queue.push(child);
                    this->add_sub(curr_node->getName(), child->getName());
                }
            }
        }
    }

    OrgChart::OrgChart(OrgChart &&chart) noexcept {
        // ignore
    }

    OrgChart::~OrgChart() {
        if (_root == nullptr) return;
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

    OrgChart &OrgChart::operator=(const OrgChart &chart) {
        OrgChart new_chart{chart};
        Node *tmp = new_chart._root;
        new_chart._root = _root;
        _root = tmp;
//        std::swap(*this, new_chart);
        return *this;
    }

    OrgChart &OrgChart::operator=(OrgChart &&chart) noexcept {
        return *this;
    }

    OrgChart &OrgChart::add_root(const std::string &root) { // todo
        if (_root == nullptr) {
            _root = new Node{root};
            _node_map[root] = _root;
        } else {
            _node_map.erase(root);
            _root->setName(root);
        }
        return *this;
    }

    OrgChart &OrgChart::add_sub(const std::string &parent, const std::string &child) {
        bool found = false;
        // https://stackoverflow.com/questions/6897737/using-the-operator-efficiently-with-c-unordered-map
//        Node* curr_parent = _node_map[parent];

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
        if (chart._root != nullptr) {
            OrgChart::print_chart(out, 0, chart._root);
        }
        return out;
    }

    void OrgChart::print_chart(std::ostream &out, unsigned int depth, Node *node) {
        std::string spaces(depth * 3, ' ');
        if (depth == 0) {
            out << *node << '\n';
        } else {
            out << spaces << "|--" << *node << '\n';
        }
        std::vector<Node *> curr_children = node->getChildren();
        for (Node *child: curr_children) {
            print_chart(out, depth + 1, child);
        }

    }

    LevelOrderIterator OrgChart::begin_level_order() {
        return LevelOrderIterator{_root};
    }

    LevelOrderIterator OrgChart::end_level_order() {
        return LevelOrderIterator{}; // default is nullptr
    }

    RLevelOrderIterator OrgChart::begin_reverse_order() {
        return RLevelOrderIterator{_root};
    }

    RLevelOrderIterator OrgChart::reverse_order() {
        return RLevelOrderIterator{};
    }

    PreorderIterator OrgChart::begin_preorder() {
        return PreorderIterator{_root};
    }

    PreorderIterator OrgChart::end_preorder() {
        return PreorderIterator{};
    }

    LevelOrderIterator OrgChart::begin() {
        return LevelOrderIterator{_root};
    }

    LevelOrderIterator OrgChart::end() {
        return LevelOrderIterator{};
    }

}