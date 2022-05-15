#ifndef CPP_EX5_ORGCHART_HPP
#define CPP_EX5_ORGCHART_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "Node.hpp"
#include "Iterator.hpp"

namespace ariel {

    class OrgChart {

    private:

        Node *_root;

    public:

        OrgChart();

        OrgChart(const OrgChart &chart);

        ~OrgChart();

        OrgChart &add_root(const std::string &root);

        OrgChart &add_sub(const std::string &parent, const std::string &child);

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
