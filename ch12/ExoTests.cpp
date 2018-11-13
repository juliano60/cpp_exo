#include "catch.hpp"
#include "Scores.hpp"
#include "SortAlgo.hpp"
#include "SList.hpp"
#include <iterator>

TEST_CASE ("canAddEntries") {
    Scores sc(3);

    sc.add({"A", 10});
    sc.add({"B", 20});
    sc.add({"C", 5});

    REQUIRE(sc.get(0).score == 20);
    REQUIRE(sc.get(1).score == 10);
    REQUIRE(sc.get(2).score == 5);
}

TEST_CASE ("canRemoveEntries") {
    Scores sc(3);

    sc.add({"A", 10});
    sc.add({"B", 20});
    sc.add({"C", 5});

    sc.remove(0);
    REQUIRE(sc.get(0).score == 10);
    REQUIRE(sc.get(1).score == 5);
}

TEST_CASE ("testInsertionSort") {
    int arr[] = {8,5,10,2};

    sort(&arr[0], &arr[0]+std::size(arr));
    //print_arr(arr);

    REQUIRE(arr[0] == 2);
    REQUIRE(arr[1] == 5);
}

TEST_CASE ("testSinglyLinkedList") {
    SLinkedList sl;

    sl.addFront("Joe");
    sl.addFront("Jane");
    sl.addFront("Debbie");

    std::cout << sl << "\n";

    REQUIRE(sl.front() == "Debbie");
    sl.removeFront();
    REQUIRE(sl.front() == "Jane");
}



