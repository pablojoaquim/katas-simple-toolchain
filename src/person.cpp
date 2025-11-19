#include "Person.h"
#include <iostream>

Person::Person(const std::string& name, int age)
    : name(name), age(age) {}

int Person::greet() const {
    std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
    return 0;
}
