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

        Node(const std::string &name);

        std::size_t size() const;

        friend std::ostream &operator<<(std::ostream &out, const Node &node);

    };

}

#endif //CPP_EX5_NODE_HPP