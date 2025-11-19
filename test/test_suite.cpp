#include <iostream>
#include <memory>
#include "person.h"
#include "acutest.h"

void test_person(void) {
    Person p1("Alice", 30);
    Person p2("Bob", 25);

    TEST_CHECK(p1.greet() == 0);
    TEST_CHECK(p2.greet() == 0);
}

TEST_LIST = {
    { "Testing something basic", test_person },
    { NULL, NULL }  // terminador
};
