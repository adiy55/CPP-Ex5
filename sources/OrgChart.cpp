#include "OrgChart.hpp"
#include <queue>
#include <iostream>

namespace ariel {

    OrgChart::OrgChart() : _root{nullptr} {}

    OrgChart::OrgChart(const OrgChart &chart)
            : _root{nullptr} {
//        std::cout << "Copy ctor\n";
        if (chart._root != nullptr) {
            std::queue<Node *> node_queue;
            Node *curr_node; // todo: nullptr?
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

    /*
     * https://stackoverflow.com/questions/9249781/are-move-constructors-required-to-be-noexcept
     * https://en.cppreference.com/w/cpp/language/noexcept_spec
     */
    OrgChart::OrgChart(OrgChart &&chart) noexcept
            : _root{chart._root}, _node_map{std::move(chart._node_map)} {
//        std::cout << "Rvalue ctor\n";
        chart._root = nullptr;
//        chart._node_map = std::unordered_map<std::string, Node *>();
    }

    OrgChart::~OrgChart() {
//        std::cout << "Destroyed\n";
        if (_root != nullptr) {
            std::queue<Node *> node_queue;
            Node *curr_node;
            node_queue.push(_root);
            while (!node_queue.empty()) {
                curr_node = node_queue.front();
                node_queue.pop();
                for (Node *child: curr_node->getChildren()) {
                    node_queue.push(child);
                }
                delete curr_node;
            }
        }
    }

    OrgChart &OrgChart::operator=(const OrgChart &chart) {
        if (this != &chart) { // check if this == this (chart)
            OrgChart new_chart{chart};
            std::swap(_root, new_chart._root);
            std::swap(_node_map, new_chart._node_map);
        }
        return *this;
    }

    OrgChart &OrgChart::operator=(OrgChart &&chart) noexcept {
        _root = chart._root;
        chart._root = nullptr;
        _node_map = std::move(chart._node_map);
        return *this;
    }

    OrgChart &OrgChart::add_root(const std::string &root) {
        if (_root == nullptr) {
            _root = new Node{root};
            _node_map[root] = _root;
        } else {
            _node_map.erase(root); // todo
            _node_map[root] = _root;
            _root->setName(root);
        }
        return *this;
    }

    OrgChart &OrgChart::add_sub(const std::string &parent, const std::string &child) {
        // https://stackoverflow.com/questions/6897737/using-the-operator-efficiently-with-c-unordered-map
        Node *curr_parent = _node_map[parent]; // hashes parent string, if not found value is NULL
        if (curr_parent == nullptr) { throw std::runtime_error{"Could not find parent node!"}; }
        Node *new_child = new Node(child);
        curr_parent->addChild(new_child);
        _node_map[child] = new_child;
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