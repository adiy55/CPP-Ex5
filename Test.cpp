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

                SUBCASE("Case 3- not alpha") {
                    CHECK_THROWS(organization.add_root("&*)("));
                    CHECK_THROWS(organization.add_root("$$$$"));
                    CHECK_THROWS(organization.add_root("24"));
                    CHECK_THROWS(organization.add_root("CE0")); // last char is zero
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
                    CHECK_THROWS(organization.add_sub("CEO", "S1GN"));
                    CHECK_THROWS(organization.add_sub("CEO", "-3.5"));
                    CHECK_THROWS(organization.add_sub("CEO", "C00")); // last char is zero
        }
                SUBCASE("No existing position in the organization") {
                    CHECK_THROWS(organization.add_sub("CTO", "VP_SW"));
                    CHECK_THROWS(organization.add_sub("COO", "COO"));
        }

                SUBCASE("Add subordinate to same position") {
                    CHECK_THROWS(organization.add_sub("CEO", "CEO"));
            organization.add_sub("CEO", "CTO");
                    CHECK_THROWS(organization.add_sub("CTO", "CTO"));
        }

                SUBCASE("Loop subordinates") {
            organization.add_sub("CEO", "CTO");
                    CHECK_THROWS(organization.add_sub("CTO", "CEO"));
        }

    }

}

TEST_CASE ("Empty OrgChart") {
    OrgChart organization;
    std::string str;

            SUBCASE("Check level order iterator") {
        for (auto &element: organization) {
            str.append(element + " ");
        }
                CHECK(str == "");
    }

            SUBCASE("Check reverse level order iterator") {
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
            str.append(*it + " ");
        }
                CHECK(str == "");
    }

            SUBCASE("Check preorder iterator") {
        for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it) {
            str.append(*it + " ");
        }
                CHECK(str == "");
    }

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


}