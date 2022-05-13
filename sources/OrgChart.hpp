#ifndef CPP_EX5_ORGCHART_HPP
#define CPP_EX5_ORGCHART_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include "Node.hpp"
#include "OrgChartIterator.hpp"

namespace ariel {


    class OrgChartIterator;

    class OrgChart {

    public:

        using Iterator = OrgChartIterator;

    private:

        Node *_root;
        std::unordered_map<std::string, std::reference_wrapper<Node>> _node_map;

    public:

        OrgChart();

        OrgChart(const OrgChart& chart);

        ~OrgChart();

        OrgChart &add_root(const std::string &root);

        OrgChart &add_sub(const std::string &upper, const std::string &lower);

        Iterator begin_level_order();

        Iterator end_level_order();

        Iterator begin_reverse_order();

        Iterator reverse_order();

        Iterator begin_preorder();

        Iterator end_preorder();

        Iterator begin();

        Iterator end();

        friend std::ostream &operator<<(std::ostream &out, const OrgChart &chart);

    };

}

#endif //CPP_EX5_ORGCHART_HPP
