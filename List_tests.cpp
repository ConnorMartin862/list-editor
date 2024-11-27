#include "List.hpp"
#include "unit_test_framework.hpp"
#include <vector>
#include <string>


using namespace std;

// Add your test cases here

TEST(test_push_front) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(0);
    int index = 0;
    vector<int> values = {0, 3, 2, 1};
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++index) {
        ASSERT_EQUAL(*it, values[index]);
    }
}

TEST(test_push_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(0);
    int index = 0;
    vector<int> values = {1, 2, 3, 0};
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++index) {
        ASSERT_EQUAL(*it, values[index]);
    }
}

TEST(test_pop_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(0);
    list.pop_back();

    int index = 0;
    vector<int> values = {1, 2, 3};
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++index) {
        ASSERT_EQUAL(*it, values[index]);
    }
}

TEST (test_pop_front) {
    List<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(0);
    list.pop_front();

    int index = 0;
    vector<int> values = {3, 2, 1};
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++index) {
        ASSERT_EQUAL(*it, values[index]);
    }
}

TEST (test_begin_and_end) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    it = list.end();
    it--;
    ASSERT_EQUAL(*it, 4);
    list.push_back(5);
    it = list.end();
    it--;
    ASSERT_EQUAL(*it, 5);
    list.pop_front();
    it = list.begin();
    ASSERT_EQUAL(*it, 2);
}

TEST (test_insert) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator it = list.begin();
    it = list.insert(it, 5);
    it++;
    it++;
    it = list.insert(it, 6);
    while (it != list.end()) {
        ++it;
    }
    it = list.insert(it, 7);
    int index = 0;
    vector<int> values = {5, 1, 6, 2, 3, 4, 7};
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++index) {
        ASSERT_EQUAL(*it, values[index]);
    }
}

TEST (test_erase) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator it = list.begin();
    it++;
    it++;
    it = list.erase(it);
    int index = 0;
    vector<int> values = {1, 2, 4};
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++index) {
        ASSERT_EQUAL(*it, values[index]);
    }
    it = list.erase(it);
    values = {1, 2};
    index = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++index) {
        ASSERT_EQUAL(*it, values[index]);
    }
    it--;
    it--;
    it = list.erase(it);
    values = {2};
    index = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++index) {
        ASSERT_EQUAL(*it, values[index]);
    }
}

TEST (test_empty) {
    List<int> list;
    bool value = list.empty();
    ASSERT_TRUE(value);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    value = list.empty();
    ASSERT_FALSE(value);
}

TEST (test_size) {
    List<int> list;
    int value = list.size();
    ASSERT_EQUAL(0, value);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    value = list.size();
    ASSERT_EQUAL(4, value);
}

TEST (test_assignment) {
    List<int> listA;
    listA.push_back(1);
    listA.push_back(2);
    listA.push_back(3);
    listA.push_back(4);
    List<int> listB;
    listB.push_back(4);
    listB.push_back(3);
    listB.push_back(2);
    listB.push_back(1);
    listA = listB;
    ASSERT_EQUAL(listA.size(), listB.size());
    List<int>::Iterator itA = listA.begin();
    List<int>::Iterator itB = listB.begin();
    while (itA != listA.end() && itB != listB.end()) {
        ASSERT_EQUAL(*itA, *itB);
        ++itA;
        ++itB;
    }
}

TEST (test_assignment_two) {
    List<int> listA;
    listA.push_back(1);
    listA.push_back(2);
    List<int> listB;
    listB.push_back(4);
    listB.push_back(3);
    listB.push_back(2);
    listA = listB;
    ASSERT_EQUAL(listA.size(), listB.size());
    List<int>::Iterator itA = listA.begin();
    List<int>::Iterator itB = listB.begin();
    while (itA != listA.end() && itB != listB.end()) {
        ASSERT_EQUAL(*itA, *itB);
        ++itA;
        ++itB;
    }
    listB.pop_back();
    ASSERT_EQUAL(listA.size(), listB.size() + 1);
    List<int> listC;
    listA = listC;
    assert(listA.empty());
    assert(listA.size() == 0);
    listA = listB;
    ASSERT_EQUAL(listA.size(), listB.size());
    listA = listC;
    listC = listB;
    listB = listA;
    assert(listA.empty());
    assert(listB.empty());
    ASSERT_EQUAL(listC.size(), 2);
    listC = listC;
    ASSERT_EQUAL(listC.size(), 2);
}

TEST (test_it_equality) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator it = list.begin();
    List<int>::Iterator itt = list.begin();
    ASSERT_TRUE(it == itt);
    itt++;
    it++;
    ASSERT_TRUE(it == itt);
}

TEST (copy_ctor) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int> listB(list);
    List<int>::Iterator it = list.end();
    List<int>::Iterator itB = listB.end();
    it--;
    itB--;
    ASSERT_EQUAL(list.size(), listB.size());
    while (it != list.begin() && itB != listB.begin()) {
        ASSERT_EQUAL(*it, *itB);
        --it;
        --itB;
    }
    ASSERT_EQUAL(*it, *itB);
}

TEST (test_clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.clear();
    ASSERT_TRUE(list.empty());
}

TEST (test_it_prefix_postfix_add) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
    it = list.begin();
    ASSERT_EQUAL(*it, 1);
    List<int>::Iterator it_copy = it++;
    ASSERT_EQUAL(*it_copy, 1);
    ASSERT_EQUAL(*it, 2);
}

TEST (test_it_prefix_postfix_subtract) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator it = list.end();
    --it;
    ASSERT_EQUAL(*it, 4);
    --it;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 2);
    it = list.end();
    --it;
    ASSERT_EQUAL(*it, 4);
    List<int>::Iterator it_copy = it--;
    ASSERT_EQUAL(*it_copy, 4);
    ASSERT_EQUAL(*it, 3);
}

TEST (test_pointer_element) {
    List<string> list;
    list.push_back("Phantom Menace");
    list.push_back("Attack of The Clones");
    list.push_back("Revenge of The Sith");
    list.push_back("A New Hope");
    list.push_back("The Empire Strikes Back");
    list.push_back("Return of The Jedi");
    List<string>::Iterator it = list.begin();
    assert(it->size() == 14);
    assert(*it == "Phantom Menace");
    it++;
    assert(*it == "Attack of The Clones");
}

TEST (test_front_and_back){
    List<string> list;
    list.push_back("Phantom Menace");
    list.push_back("Attack of The Clones");
    list.push_back("Revenge of The Sith");
    list.push_back("A New Hope");
    list.push_back("The Empire Strikes Back");
    list.push_back("Return of The Jedi");
    ASSERT_EQUAL(list.front(), "Phantom Menace");
    ASSERT_EQUAL(list.back(), "Return of The Jedi");
}

TEST (test_inequality_operator) {
    List<string> listA;
    listA.push_back("Phantom Menace");
    listA.push_back("Attack of The Clones");
    listA.push_back("Revenge of The Sith");
    List<string> listB;
    listB.push_back("A New Hope");
    listB.push_back("The Empire Strikes Back");
    listB.push_back("Return of The Jedi");
    List<string>::Iterator itA = listA.begin();
    List<string>::Iterator itB = listB.begin();
    assert(*itA != *itB);
}

TEST_MAIN()
