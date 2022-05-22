#ifndef CPP_EX5_ORGCHART_HPP
#define CPP_EX5_ORGCHART_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Node.hpp"
#include "Iterator.hpp"
#include "LevelOrderIterator.hpp"
#include "PreorderIterator.hpp"
#include "RLevelOrderIterator.hpp"

namespace ariel {

    class OrgChart {

    private:

        Node *_root{};
        std::unordered_map<std::string, Node *> _node_map;

    public:

        static void printChart(std::ostream &out, unsigned int depth, Node *node);

        OrgChart();

        OrgChart(const OrgChart &chart);

        OrgChart(OrgChart &&chart) noexcept;

        ~OrgChart();

        OrgChart &operator=(const OrgChart &chart);

        OrgChart &operator=(OrgChart &&chart) noexcept;

        OrgChart &add_root(const std::string &root);

        OrgChart &add_sub(const std::string &parent, const std::string &child);

        LevelOrderIterator begin_level_order();

        LevelOrderIterator end_level_order();

        RLevelOrderIterator begin_reverse_order();

        RLevelOrderIterator reverse_order();

        PreorderIterator begin_preorder();

        PreorderIterator end_preorder();

        LevelOrderIterator begin();

        LevelOrderIterator end();

        friend std::ostream &operator<<(std::ostream &out, const OrgChart &chart);

    };

}

#endif //CPP_EX5_ORGCHART_HPP
