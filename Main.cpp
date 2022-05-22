#include <iostream>
#include <string>
#include "sources/OrgChart.hpp"

using namespace ariel;
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::string;

void insertRoot(OrgChart &c);

void insertChild(OrgChart &c);

void resetChart(OrgChart &c);

// To compile program run: clang++-9 -std=c++2a sources/*.cpp Main.cpp -Isources -o main -g
int main() {
    OrgChart chart;
    int mode;
    while (cin) {
        cout << "To insert root node enter 1\n"
                "To insert child node enter 2\n"
                "To print current chart enter 3\n"
                "To reset default chart insert 4\n"
                "To clear chart insert 5\n"
                "Enter any other character to exit" << endl;
        cin >> mode;
        if (mode == 1) {
            insertRoot(chart);
        } else if (mode == 2) {
            insertChild(chart);
        } else if (mode == 3) {
            cout << "Current chart is:\n" << chart << endl;
        } else if (mode == 4) {
            resetChart(chart);
        } else if (mode == 5) {
            chart = std::move(OrgChart{});
        } else {
            cout << "Exiting program...\n";
            return 0;
        }
    }
    return 0;
}

void insertRoot(OrgChart &c) {
    try {
        string str;
        cout << "Insert root name\n";
        cin >> str;
        c.add_root(str);
    }
    catch (exception &ex) {
        cout << "Invalid input: " << ex.what() << endl;
    }
}

void insertChild(OrgChart &c) {
    try {
        string parent;
        string child;
        cout << "Insert parent name\n";
        cin >> parent;
        cout << "Insert child name\n";
        cin >> child;
        c.add_sub(parent, child);
    }
    catch (exception &ex) {
        cout << "Invalid input: " << ex.what() << endl;
    }
}

void resetChart(OrgChart &c) {
    try {
        OrgChart new_chart;
        new_chart.add_root("CEO")
                .add_sub("CEO", "CTO")
                .add_sub("CEO", "CFO")
                .add_sub("CEO", "COO")
                .add_sub("CTO", "VP_SW")
                .add_sub("COO", "VP_BI");
        c = std::move(new_chart);
    } catch (exception &ex) {
        cout << "Invalid input: " << ex.what() << endl;
    }
}