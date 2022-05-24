#ifndef CPP_EX5_NODE_HPP
#define CPP_EX5_NODE_HPP

#include <string>
#include <vector>

namespace ariel {

    class Node {
    private:

        std::string _name;
        std::vector<Node *> _children;

        static void validateName(const std::string &name);

    public:

        Node(const std::string &name);

        void addChild(Node *child);

        std::vector<Node *> &getChildren();

        void setName(const std::string &name);

        std::string &getName();

        friend std::ostream &operator<<(std::ostream &out, const Node &node);

    };

}

#endif //CPP_EX5_NODE_HPP
