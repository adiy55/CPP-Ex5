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

void clearBuffer();

void printChart(OrgChart &c);

void executeIterator(Iterator &begin, Iterator &end);

// To compile program run: clang++-9 -std=c++2a sources/*.cpp Main.cpp -Isources -o main -g
int main() {
    OrgChart chart;
    int mode;
    while (cin) {
        cout << "To insert root node enter 1\n"
                "To insert child node enter 2\n"
                "To print current chart enter 3\n"
                "To reset default chart enter 4\n"
                "To clear chart enter 5\n"
                "Enter any other character to exit" << endl;
        cin >> mode;
        if (mode == 1) {
            insertRoot(chart);
        } else if (mode == 2) {
            insertChild(chart);
        } else if (mode == 3) {
            cout << "Current chart is:\n" << "\033[1;34m" << chart << "\033[0m\n";
            printChart(chart);
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
        clearBuffer();
        std::getline(cin, str);
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
        clearBuffer();
        std::getline(cin, parent);
        cout << "Insert child name\n";
        std::getline(cin, child);
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

void executeIterator(Iterator &begin, Iterator &end) {
    for (; begin != end; ++begin) {
        cout << "\033[1;31m" << (*begin) << "\033[0m" << " ";
    }
    cout << '\n';
}

void printChart(OrgChart &c) {
    try {
        cout << "Level Order:\n";
        LevelOrderIterator lvl_start = c.begin_level_order();
        LevelOrderIterator lvl_fin = c.end_level_order();
        executeIterator(lvl_start, lvl_fin);
        cout << "Preorder:\n";
        PreorderIterator pre_start = c.begin_preorder();
        PreorderIterator pre_fin = c.end_preorder();
        executeIterator(pre_start, pre_fin);
        cout << "Reverse Level Order:\n";
        RLevelOrderIterator rlvl_start = c.begin_reverse_order();
        RLevelOrderIterator rlvl_fin = c.reverse_order();
        executeIterator(rlvl_start, rlvl_fin);
        cout << '\n';
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
}

// clear buffer before taking new line
void clearBuffer() { cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }