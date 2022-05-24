#include "OrgChart.hpp"
#include <queue>

namespace ariel {

    OrgChart::OrgChart()
            : _root{nullptr} {}

    /**
     * Copy constructor. Copies nodes from given chart using BFS order.
     */
    OrgChart::OrgChart(const OrgChart &chart)
            : _root{nullptr} {
        if (chart._root != nullptr) { // check if chart is empty
            std::queue<Node *> node_queue;
            Node *curr_node = nullptr;
            this->add_root(chart._root->getName()); // allocate root: using add_root method
            node_queue.push(chart._root);
            while (!node_queue.empty()) {
                curr_node = node_queue.front();
                node_queue.pop();
                for (Node *child: curr_node->getChildren()) { // allocate children: using add_sub method
                    node_queue.push(child);
                    this->add_sub(curr_node->getName(), child->getName());
                }
            }
        }
    }

    /*
     * https://stackoverflow.com/questions/9249781/are-move-constructors-required-to-be-noexcept
     * https://en.cppreference.com/w/cpp/language/noexcept_spec
     * Marked with noexcept specifier. Method could throw but should not throw exceptions
     * (no function calls, memory allocation, simply moving pointers and object references)
     */
    OrgChart::OrgChart(OrgChart &&chart) noexcept
            : _root{chart._root}, _node_map{std::move(chart._node_map)} {
        chart._root = nullptr; // nullptr to avoid accidentally deleting the chart
    }

    OrgChart::~OrgChart() {
        this->deleteChart();
    }

    /**
     * Helper function- deletes allocated nodes using iterative BFS traversal.
     */
    void OrgChart::deleteChart() const {
        if (_root != nullptr) { // if root is nullptr no nodes were allocated
            std::queue<Node *> node_queue;
            Node *curr_node = nullptr;
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

    /*
     * unordered map: https://en.cppreference.com/w/cpp/container/unordered_map/swap2
     * swaps container contents.
     */
    OrgChart &OrgChart::operator=(const OrgChart &chart) {
        if (this != &chart) { // check if this == this (chart)
            OrgChart new_chart{chart};
            std::swap(_root, new_chart._root); // swap _root class member (swap pointers)
            std::swap(_node_map, new_chart._node_map);
        }
        return *this;
    }

    /*
     * std::move: https://en.cppreference.com/w/cpp/utility/move
     */
    OrgChart &OrgChart::operator=(OrgChart &&chart) noexcept {
        this->deleteChart(); // delete current chart (may contain allocated nodes)
        _root = chart._root;
        chart._root = nullptr;  // nullptr to avoid accidentally deleting the chart
        _node_map = std::move(chart._node_map); // cast to a rvalue-reference to allow moving it
        return *this;
    }

    /*
     * unordered map- erase: https://en.cppreference.com/w/cpp/container/unordered_map/erase
     * "Removes the element (if one exists) with the key equivalent to key."
     * "Return value: Number of elements removed (0 or 1)."
     */
    /**
     * Add new root if nullptr or overwrite exiting root.
     */
    OrgChart &OrgChart::add_root(const std::string &root) {
        if (_root == nullptr) {
            _root = new Node{root};
            _node_map[root] = _root;
        } else {
            _node_map.erase(_root->getName());
            _node_map[root] = _root;
            _root->setName(root);
        }
        return *this;
    }

    /**
     * Find parent node and add new child node.
     * Repetitive names are considered as new nodes.
     */
    OrgChart &OrgChart::add_sub(const std::string &parent, const std::string &child) {
        // https://stackoverflow.com/questions/6897737/using-the-operator-efficiently-with-c-unordered-map
        Node *curr_parent = _node_map[parent]; // hashes parent string, if not found value is NULL
        if (curr_parent == nullptr) { throw std::runtime_error{"Could not find parent node!"}; }
        Node *new_child = new Node(child);
        curr_parent->addChild(new_child);
        _node_map[child] = new_child; // overwrites if key exists
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const OrgChart &chart) {
        if (chart._root != nullptr) { // check if graph is empty
            OrgChart::printChart(out, 0, chart._root);
        }
        return out;
    }

    /**
     * Helper function- Print chart recursively in depth order.
     * Recursion stops whenever leaf node is reached (continues to other children until all nodes are reached).
     */
    void OrgChart::printChart(std::ostream &out, unsigned int depth, Node *node) {
        if (depth == 0) {
            out << "\033[1;34m" << (*node) << "\033[0m\n";
        } else {
            std::string spaces(depth * 3, ' '); // 3 spaces per depth number
            out << spaces << "+--" << (*node) << '\n';
        }
        for (Node *child: node->getChildren()) {
            printChart(out, depth + 1, child); // add depth to next level
        }
    }

    LevelOrderIterator OrgChart::begin_level_order() {
        this->validateIterator();
        return LevelOrderIterator{_root};
    }

    LevelOrderIterator OrgChart::end_level_order() {
        this->validateIterator();
        return LevelOrderIterator{}; // default is nullptr
    }

    RLevelOrderIterator OrgChart::begin_reverse_order() {
        this->validateIterator();
        return RLevelOrderIterator{_root};
    }

    RLevelOrderIterator OrgChart::reverse_order() {
        this->validateIterator();
        return RLevelOrderIterator{}; // default is nullptr
    }

    PreorderIterator OrgChart::begin_preorder() {
        this->validateIterator();
        return PreorderIterator{_root};
    }

    PreorderIterator OrgChart::end_preorder() {
        this->validateIterator();
        return PreorderIterator{}; // default is nullptr
    }

    LevelOrderIterator OrgChart::begin() {
        this->validateIterator();
        return LevelOrderIterator{_root};
    }

    LevelOrderIterator OrgChart::end() {
        this->validateIterator();
        return LevelOrderIterator{}; // default is nullptr
    }

    void OrgChart::validateIterator() const { if (_root == nullptr) { throw std::runtime_error{"chart is empty!"}; }}

}