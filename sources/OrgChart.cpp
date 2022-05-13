#include "OrgChart.hpp"
#include "Node.hpp"

namespace ariel {

    using Iterator = OrgChart::Iterator;

    OrgChart &OrgChart::add_root(const std::string &root) {
        _root = new Node{root};
        _node_map[root] = *_root;
        return *this;
    }

    OrgChart &OrgChart::add_sub(const std::string &upper, const std::string &lower) {
        for (auto &[key, value]: _node_map) {
            if (key == upper) {
                Node &father = value;
                father._children.emplace_back(Node{lower});
                std::size_t last_index = father._children.size() - 1;
                _node_map[lower] = father._children[last_index];
            }
        }
        return *this;
    }

    Iterator OrgChart::begin_level_order() { return Iterator{nullptr}; }

    Iterator OrgChart::end_level_order() { return Iterator{nullptr}; }

    Iterator OrgChart::begin_reverse_order() { return Iterator{nullptr}; }

    Iterator OrgChart::reverse_order() { return Iterator{nullptr}; }

    Iterator OrgChart::begin_preorder() { return Iterator{nullptr}; }

    Iterator OrgChart::end_preorder() { return Iterator{nullptr}; }

    Iterator OrgChart::begin() { return begin_level_order(); }

    Iterator OrgChart::end() { return end_level_order(); }

    std::ostream &operator<<(std::ostream &out, const OrgChart &chart) {
        for (const auto &[key, value]: chart._node_map)
            out << key << " ";
        return out;
    }

    OrgChart::~OrgChart() {
        delete _root;
    }

    OrgChart::OrgChart() : _root{nullptr}, _node_map{} {}

}