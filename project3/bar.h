// Name: roshan dhimal, UIN: 661652338
// Class: CS 251; Fall 2021
// Assignment: Project 3 - Animated Bar Chart
// Professor: Joe Hummel, PhD

// bar.h
// the bar.h builds the required bar class that aggregates the information such as name, value and category for using in the bar chart object.
// the bar clasd contains the private members name , value and categorgy which the public function contstructs, compares, destructs, sets name, value and category aslo returns when called.

#include <iostream>
#include <string>
#include "myrandom.h" // used in autograder, do not remove
using namespace std;

//
// Bar
//
class Bar {
 private:
    // Private member variables for a Bar object for assignning name, value and category  for bars
    string Name;
    int value;
    string category;

 public:

    // default constructor: initalizes the name and category to empty string and value to 0, when the object is created
    Bar() {
      this->Name = "";
      this->value = 0;
      this->category = "";
    }

    //
    // a second constructor:
    //
    // Parameter passed in constructor Bar object.
    // assgins object contents according to the parameter
    Bar(string name, int value, string category) {
      this->Name = name;
      this->value = value;
      this->category = category;
    }

    // destructor: destroys after the content of the bar object to reset initial point as default contstructor
    virtual ~Bar() {
      this->Name = "";
      this->value = 0;
      this->category = "";
    }

    // getName: function returns the name of the  bar object
	string getName() {
        return this->Name;
	}

    // getValue: function return the valur of the bar object
	int getValue() {
        return this->value;
	}

    // getCategory: function return the category of the bar obect
	string getCategory() {
        return this->category;
	}

	// operators
  // this allows you to compare two Bar
  //  the following boolean operator function from line 71 to 93,
  // compares the two bar objects values at various cases and return true or false
	bool operator<(const Bar &other) const {
    if (this->value < other.value){
        return true;
    }
    return false;
	}

	bool operator<=(const Bar &other) const {
    if (this->value <= other.value)
        return true;
    return false;
	}

	bool operator>(const Bar &other) const {
    if (this->value > other.value)
        return true;
    return false;
	}

	bool operator>=(const Bar &other) const {
    if (this->value >= other.value)
        return true;
    return false;
	}
};
