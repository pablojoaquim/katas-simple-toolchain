#include <iostream>
#include <memory>
#include "person.h"
#include "animal.h"
#include "acutest.h"

void test_person(void) {
    Person p1("Alice", 30);
    Person p2("Bob", 25);

    TEST_CHECK(p1.greet() == 0);
    TEST_CHECK(p2.greet() == 0);
}

void test_animal(void) {
    TEST_CHECK(Dog_Walk() == 0);
}

TEST_LIST = {
    { "Testing something basic 1", test_person },
    { "Testing something basic 2", test_animal },
    { NULL, NULL }  // terminador
};
