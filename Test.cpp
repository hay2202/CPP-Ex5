/**
 * AUTHORS: Hay Asa
 * Date: "2"0"2""1"-0"2"
 */


#include <BinaryTree.hpp>
using namespace ariel;

#include "doctest.h"
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;



TEST_CASE("TREE OF INTEGERS") {
    BinaryTree<int> tree;

    SUBCASE("regular methods + preorder"){
        CHECK_NOTHROW(tree.add_root(1));
        CHECK_NOTHROW(tree.add_left(1,2).add_left(2,3).add_right(1,4));
        CHECK_THROWS(tree.add_left(8,2));       //node 8 doesn't exist!
        CHECK_THROWS(tree.add_right(8,2));
        CHECK_THROWS(tree.add_left(8,2).add_left(3,4));
        CHECK_NOTHROW(tree.add_right(4,5));
        auto it = tree.begin_preorder();    // point on root
        int i = 1;
        while(it != tree.end_preorder()){            // check pre order
            CHECK(*it++ == i++);
        }
    }

    SUBCASE("change exist nodes + postorder"){
        CHECK_NOTHROW(tree.add_root(5));
        CHECK_NOTHROW(tree.add_left(5,2).add_left(2,1).add_right(5,4).add_right(4,3));
        auto it = tree.begin_postorder();
        int i = 1;
        while(it != tree.end_postorder()){            // check post order
            CHECK(*it++ == i++);
        }
    }

    SUBCASE("change exist nodes + inorder"){
        CHECK_NOTHROW(tree.add_root(3));
        CHECK_NOTHROW(tree.add_right(4,5));
        auto it = tree.begin_inorder();
        int i = 1;
        while(it != tree.end_inorder()){            // check in order
            CHECK(*it++ == i++);
        }
    }
    
}


TEST_CASE("TREE OF STRING") {
    BinaryTree<string> tree;

    SUBCASE("regular methods + preorder"){
        CHECK_NOTHROW(tree.add_root("1"));
        CHECK_NOTHROW(tree.add_left("1","2").add_left("2","3").add_right("1","4"));
        CHECK_THROWS(tree.add_left("8","2"));       //node "8" doesn't exist!
        CHECK_THROWS(tree.add_right("8","2"));
        CHECK_THROWS(tree.add_left("8","2").add_left("3","4"));
        CHECK_NOTHROW(tree.add_right("4","5"));
        auto it = tree.begin_preorder();    // point on root
        int i = 0;
        string arr[5] = {"1","2","3","4","5"};
        while(it != tree.end_preorder()){            // check pre order
            CHECK(*it++ == arr[i++]);
        }
    }

    SUBCASE("change exist nodes + postorder"){
        CHECK_NOTHROW(tree.add_root("5"));
        CHECK_NOTHROW(tree.add_left("5","2").add_left("2","1").add_right("5","4").add_right("4","3"));
        auto it = tree.begin_postorder();
        int i = 0;
        string arr[5] = {"1","2","3","4","5"};
        while(it != tree.end_postorder()){            // check post order
            CHECK(*it++ == arr[i++]);
        }
    }

    SUBCASE("change exist nodes + inorder"){
        CHECK_NOTHROW(tree.add_root("3"));
        CHECK_NOTHROW(tree.add_right("4","5"));
        auto it = tree.begin_inorder();
        int i = 0;
        string arr[5] = {"1","2","3","4","5"};
        while(it != tree.end_inorder()){            // check in order
            CHECK(*it++ == arr[i++]);
        }
    } 
}