#include "OrgChart.hpp"
#include <queue>

namespace ariel {

    OrgChart::OrgChart() : _root{nullptr} {}

    OrgChart::OrgChart(const OrgChart &chart) {

    }

    OrgChart::OrgChart(OrgChart &&chart) noexcept {

    }

    OrgChart::~OrgChart() {}

    OrgChart &OrgChart::operator=(const OrgChart &chart) {
        return *this;
    }

    OrgChart &OrgChart::operator=(OrgChart &&chart) noexcept {
        return *this;
    }

    OrgChart &OrgChart::add_root(const std::string &root) {
        return *this;
    }

    OrgChart &OrgChart::add_sub(const std::string &parent, const std::string &child) {
        return *this;
    }

    std::ostream &operator<<(std::ostream &out, const OrgChart &chart) {
        return out;
    }

    Iterator OrgChart::begin_level_order() {
        return Iterator{_root};
    }

    Iterator OrgChart::end_level_order() {
        return Iterator{};
    }

    Iterator OrgChart::begin_reverse_order() {
        return Iterator{_root};
    }

    Iterator OrgChart::reverse_order() {
        return Iterator{};
    }

    Iterator OrgChart::begin_preorder() {
        return Iterator{_root};
    }

    Iterator OrgChart::end_preorder() {
        return Iterator{};
    }

    Iterator OrgChart::begin() {
        return Iterator{_root};
    }

    Iterator OrgChart::end() {
        return Iterator{};
    }

}