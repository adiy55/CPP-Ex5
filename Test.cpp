#include "doctest.h"
#include "sources/OrgChart.hpp"
#include <string>

using namespace ariel;

TEST_CASE ("Basic functions") {
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");

            SUBCASE("Change root node") {
        std::string str;

                CHECK_NOTHROW(organization.add_root("Head_of_Org"));

                SUBCASE("Check level order iterator") {
            for (auto &element: organization) {
                str.append(element + " ");
            }
                    CHECK(str == "Head_of_Org CTO CFO COO VP_SW VP_BI ");
        }
    }

            SUBCASE("Add sub") {
        std::string str;

                CHECK_NOTHROW(organization.add_sub("COO", "VP_BII"));

                SUBCASE("Check level order iterator") {
            for (auto &element: organization) {
                str.append(element + " ");
            }
                    CHECK(str == "CEO CTO CFO COO VP_SW VP_BI VP_BII ");
        }

                SUBCASE("Check reverse level order iterator") {
            for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
                str.append(*it + " ");
            }
                    CHECK(str == "VP_SW VP_BI VP_BII CTO CFO COO CEO ");
        }

                SUBCASE("Check preorder iterator") {
            for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it) {
                str.append(*it + " ");
            }
                    CHECK(str == "CEO CTO VP_SW CFO COO VP_BI VP_BII ");
        }
    }

}


TEST_CASE ("Invalid names") {
    OrgChart organization;

            SUBCASE("Bad root") {
                SUBCASE("Case 1- spaces") {
                    CHECK_THROWS(organization.add_root(" "));
                    CHECK_THROWS(organization.add_root("     "));
                    CHECK_THROWS(organization.add_root(" $ $ $ $ "));
        }
                SUBCASE("Case 2- empty string") {
                    CHECK_THROWS(organization.add_root(""));
        }

                SUBCASE("Case 3- does not begin with alpha") {
                    CHECK_THROWS(organization.add_root("&*)("));
                    CHECK_THROWS(organization.add_root("$$$$"));
                    CHECK_THROWS(organization.add_root("24"));
        }
    }

            SUBCASE("Bad sub") {
        organization.add_root("CEO");

                SUBCASE("Case 1- spaces") {
                    CHECK_THROWS(organization.add_sub("CEO", " "));
                    CHECK_THROWS(organization.add_sub("CEO", "    "));
                    CHECK_THROWS(organization.add_sub("CEO", " a a a "));
        }
                SUBCASE("Case 2- empty string") {
                    CHECK_THROWS(organization.add_sub("CEO", ""));
        }

                SUBCASE("Case 3- not alpha") {
                    CHECK_THROWS(organization.add_sub("CEO", "-3.5"));
        }
                SUBCASE("No existing position in the organization") {
                    CHECK_THROWS(organization.add_sub("CTO", "VP_SW"));
                    CHECK_THROWS(organization.add_sub("COO", "COO"));
        }

                SUBCASE("Add subordinate to same position") {
                    CHECK_NOTHROW(organization.add_sub("CEO", "CEO"));
            organization.add_sub("CEO", "CTO");
                    CHECK_NOTHROW(organization.add_sub("CTO", "CTO"));
        }

    }

            SUBCASE("Not Printable") {
                CHECK_THROWS(organization.add_root("✡"));
                CHECK_THROWS(organization.add_sub("✡", "☞"));
                CHECK_THROWS(organization.add_sub("☞", "☜"));
                CHECK_THROWS(organization.add_root("⍺"));
                CHECK_THROWS(organization.add_root("♕"));
    }

}


TEST_CASE ("Empty OrgChart") {
    OrgChart organization;
            CHECK_THROWS(organization.begin_level_order());
            CHECK_THROWS(organization.begin_reverse_order());
            CHECK_THROWS(organization.begin_preorder());
            CHECK_THROWS(organization.begin());
}


TEST_CASE ("Add Sub- no parent node") {
    OrgChart chart;
            CHECK_THROWS(chart.add_sub("CEO", "CTO")); // sub before root
    chart.add_root("CEO");
            CHECK_THROWS(chart.add_sub("CTO", "COO")); // with root, no parent node
}


TEST_CASE ("Copy Assignment operator") {

            SUBCASE("Empty chart") {
        OrgChart chart1{};
        OrgChart chart2 = chart1;
                CHECK(&chart1 != &chart2); // compare addresses
    }

            SUBCASE("Change chart root after assignment") {
        OrgChart chart1{};
        chart1.add_root("CEO");
        OrgChart chart2 = chart1;
                CHECK(&chart1 != &chart2);
        for (auto it1 = chart1.begin(), it2 = chart2.begin();
             it1 != chart1.end() || it2 != chart2.end(); ++it1, ++it2) {
                    CHECK(*it1 == *it2); // compare addresses
        }
        chart2.add_root("Elon");
        for (auto it1 = chart1.begin(), it2 = chart2.begin();
             it1 != chart1.end() || it2 != chart2.end(); ++it1, ++it2) {
                    CHECK(*it1 != *it2); // compare addresses
        }
    }

}


TEST_CASE ("Linked List") {
    OrgChart chart1;

            SUBCASE("Copy Ctor") {
        chart1.add_root("A")
                .add_sub("A", "B")
                .add_sub("B", "C")
                .add_sub("C", "D");

        OrgChart chart2{chart1};
                CHECK(&chart1 != &chart2);
        for (auto it1 = chart1.begin(), it2 = chart2.begin();
             it1 != chart1.end() || it2 != chart2.end(); ++it1, ++it2) {
                    CHECK(*it1 == *it2); // compare addresses
        }
        for (auto it1 = chart1.begin_level_order(), it2 = chart2.begin_level_order();
             it1 != chart1.end_level_order() || it2 != chart2.end_level_order(); ++it1, ++it2) {
                    CHECK(*it1 == *it2); // compare addresses
        }
        for (auto it1 = chart1.begin_preorder(), it2 = chart2.begin_preorder();
             it1 != chart1.end_preorder() || it2 != chart2.end_preorder(); ++it1, ++it2) {
                    CHECK(*it1 == *it2); // compare addresses
        }
        for (auto it1 = chart1.begin_reverse_order(), it2 = chart2.begin_reverse_order();
             it1 != chart1.reverse_order() || it2 != chart2.reverse_order(); ++it1, ++it2) {
                    CHECK(*it1 == *it2); // compare addresses
        }
    }

            SUBCASE ("Arrow -> operator") {
        std::vector sizes{1, 2, 3, 4, 5};
        chart1.add_root("a")
                .add_sub("a", "ab")
                .add_sub("ab", "abc")
                .add_sub("abc", "abcd")
                .add_sub("abcd", "abcde");
        unsigned int idx = 0;
        for (auto &element: chart1) {
                    CHECK(element.size() == sizes[idx++]);
        }
    }

}