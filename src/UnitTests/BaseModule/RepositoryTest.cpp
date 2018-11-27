//
//  RepositoryTest.c
//  UnitTests
//
//  Created by Daniel Almeida on 27/11/2018.
//

#include <stdio.h>
#include "catch.hpp"
#include "Repository.h"

#include <string>
#include <iostream>

using namespace std;

class TestClass {
    string value;
public:
    string getValue() {
        return value;
    }
    
    void setValue(string _value) {
        value = _value;
    }
};

TEST_CASE( "Repository should traverse all records and apply a lambda to each entity", "[forEach]" ) {
    
    Orange::Base::Repository<TestClass> repo;
    
    std::vector<string> inputValues = {"a", "b", "c", "d"};
    string stringCat;
    
    for(string value:inputValues) {
        TestClass obj;
        obj.setValue(value);
        repo.add(obj);
    }
    
    repo.forEach([&stringCat](TestClass obj) mutable {
        stringCat += obj.getValue();
    });
    
    REQUIRE(stringCat == "abcd");
}
