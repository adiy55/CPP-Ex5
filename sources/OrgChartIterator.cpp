#include "OrgChartIterator.hpp"

namespace ariel {

    using Reference = OrgChartIterator::Reference;
    using Pointer = OrgChartIterator::Pointer;
    using Iterator = OrgChartIterator::Iterator;

    OrgChartIterator::OrgChartIterator(Pointer ptr) : _ptr{ptr} {}

    Reference OrgChartIterator::operator*() { return *_ptr; }

    Pointer OrgChartIterator::operator->() { return _ptr; }

    Iterator &OrgChartIterator::operator++() { return *this; }

    Iterator OrgChartIterator::operator++(int) { return Iterator{nullptr}; }

    Iterator &OrgChartIterator::operator--() { return *this; }

    Iterator OrgChartIterator::operator--(int) { return Iterator{nullptr}; }

    bool OrgChartIterator::operator==(const Iterator &other) const { return _ptr == other._ptr; }

    bool OrgChartIterator::operator!=(const Iterator &other) const { return !this->operator==(other); }

}