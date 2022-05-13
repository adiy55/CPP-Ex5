#ifndef CPP_EX5_NODE_HPP
#define CPP_EX5_NODE_HPP

#include <vector>
#include <iostream>

namespace ariel {

    class Node {

    private:
        std::string _name;
        std::vector<Node> _children;
        bool _visited{false};

    public:

        Node();

        Node(const std::string &name);

        std::size_t size() const;

        std::string getName() const;

        bool getVisited() const;

        void setVisited(bool val);

        std::vector<Node>& getChildren();

        friend std::ostream &operator<<(std::ostream &out, const Node &node);

//        Node(const std::string &name = std::string{}) : _name{name} {}
//
//        std::size_t size() const { return _children.size(); }
//
//        friend std::ostream &operator<<(std::ostream &out, const Node &node) { return out; }
//
//        std::string getName() const { return _name; }
//
        friend class OrgChart;

    };
}

#endif //CPP_EX5_NODE_HPP
