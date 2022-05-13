#ifndef CPP_EX5_NODE_HPP
#define CPP_EX5_NODE_HPP

#include <string>
#include <vector>

namespace ariel {

    struct Node {
    private:

        std::string _name;
        std::vector<Node *> _children;

    public:

        Node();

        Node(const std::string &name);

        void addChild(Node* child);

    };

}

#endif //CPP_EX5_NODE_HPP
