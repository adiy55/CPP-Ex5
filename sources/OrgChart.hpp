#ifndef CPP_EX5_ORGCHART_HPP
#define CPP_EX5_ORGCHART_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "Node.hpp"

namespace ariel {

    class OrgChart {

    private:

        Node *_root;
        std::unordered_map<std::string, Node *> _node_map;

    public:

        OrgChart();

        OrgChart(const OrgChart &chart);

        ~OrgChart();

        OrgChart &add_node(const std::string &root);

        OrgChart &add_sub(const std::string &parent, const std::string &child);

        friend std::ostream &operator<<(std::ostream &out, const OrgChart &chart);

    };

}

#endif //CPP_EX5_ORGCHART_HPP
