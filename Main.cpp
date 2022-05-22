#include <iostream>
#include "sources/OrgChart.hpp"

using namespace ariel;

// To compile program run: clang++-9 -std=c++2a sources/*.cpp Main.cpp -Isources -o main -g
int main() {
//
    OrgChart chart;
    chart.add_root("CEO")
            .add_sub("CEO", "COO");

    LevelOrderIterator it = chart.begin_level_order();
    it++;
    return 0;
}