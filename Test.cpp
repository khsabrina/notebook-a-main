
#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;
#include <string>
#include <algorithm>
using namespace std;


TEST_CASE("Good Input"){
    ariel::Notebook notebook;
    notebook.write(0,0,0,Direction::Vertical,"Hey");
    CHECK(notebook.read(0,0,0,Direction::Vertical,3)=="Hey");
    notebook.write(0,0,1,Direction::Vertical,"Hello");
    CHECK(notebook.read(0,0,1,Direction::Vertical,5)=="Hello");
     notebook.write(2,0,0,Direction::Horizontal,"blablablablabla");
    CHECK(notebook.read(2,0,0,Direction::Horizontal,15)=="blablablablabla");
    string test= "test";
    for(int i=10; i<20; i++){
        notebook.write(i,0,i,Direction::Vertical,test);
        CHECK(notebook.read(i,0,i,Direction::Vertical,4)==test);
    }
    for(int i=20; i<30; i++){
        notebook.write(i,0,i,Direction::Horizontal,test);
        CHECK(notebook.read(i,0,i,Direction::Horizontal,4)==test);
    }
}

TEST_CASE("Bad Inputs"){
    ariel::Notebook notebook;
     string test= "test";
    for(int i=0; i<10; i++){
        notebook.write(i,0,0,Direction::Vertical,test);
        CHECK_THROWS(notebook.write(i,0,0,Direction::Vertical,test));
    }
    for(int i=10; i<20; i++){
        notebook.write(i,0,0,Direction::Horizontal,test);
        CHECK_THROWS(notebook.write(i,0,0,Direction::Horizontal,test));
    }

}

TEST_CASE("Bad input of Strings"){
    ariel::Notebook notebook;
    for(int i=10; i<20; i++){
        string test;
        char c =rand() % 34;
        test += c;
        CHECK_THROWS(notebook.write(0,i,0,Direction::Horizontal,test));
        CHECK_THROWS(notebook.write(i,0,0,Direction::Vertical,test));   
    }
}

TEST_CASE("Negative Numbers"){
    ariel::Notebook notebook;
    for(int i=-10; i<0; i++){
        CHECK_THROWS(notebook.write(i,0,0,Direction::Horizontal,"test")); 
        CHECK_THROWS(notebook.read(0,i,0,Direction::Horizontal,4));
        CHECK_THROWS(notebook.erase(0,0,i,Direction::Horizontal,4));  
    }
}
