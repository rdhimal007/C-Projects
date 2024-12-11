// Name: roshan dhimal, UIN: 661652338
// Class: CS 251; Fall 2021
// Assignment: Project 3 - Animated Bar Chart
// Professor: Joe Hummel, PhD

// barchart.h
// Allocates the space on the heap and stores the one entire frame
// of the animation inside as C-array bar objects
// private class contains the cstyle array of bars , size, capacity and frame
// public functions use for contstructing, assigning, outputing and destryoing

#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h" // used in autograder, do not remove
#include "bar.h"


using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// // Color codes for Codio (light/dark mode)
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array of bars
    int capacity;
    int size;
    string frame;  // variables frame is setup to store the year

 public:
    // default constructor: initalizes the c-style of bars to nullptr,
    //set default capacity to 4, size to 0 and frame for the year to empty
    BarChart() {
      this-> bars = nullptr;
      this-> capacity = 4;
      this-> size = 0;
      this-> frame = "";
    }

    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars
    BarChart(int n) {
      this-> bars = new Bar[n];
      this-> capacity = n;
      this-> size = 0;
      this-> frame = "";
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.
    // when passing BarChart as a parameter by value.
    BarChart(const BarChart& other) {
      this-> bars = new Bar[other.capacity];
      this-> capacity = other.capacity;
      this-> size = other.size;
      this-> frame = other.frame;
      // iterates until the size of the barcahrt
      for (int i = 0; i < other.size; ++i) {
        this-> bars[i] = other.bars[i];
      }
    }
    //
    // copy operator =
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
      // if block checks if the current pointer to bar is equal to other,
      // then returns if they point the same address
      if (this == &other) {
          return *this;
      }
      delete[] bars;   // deletes the previous bar array
      // allocate this array with same capacity, size, frame as the other:
      this->bars = new Bar[other.capacity];
      this->size = other.size;
      this->capacity = other.capacity;
      this-> frame = other.frame;
      for (int i = 0; i < other.size; ++i) {
        this-> bars[i] = other.bars[i];
      }
      return *this;
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
      delete[] bars;
      this->bars = nullptr ;
      this-> capacity = 4;
      this-> size = 0;
      this-> frame = "";
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    virtual ~BarChart() {
      if (bars != nullptr){
        delete[] bars;
      }
    }

    // setFrame function sets the frame i.e is the year for the barchart
    void setFrame(string frame) {
      this->frame = frame;
    }

    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() {
        return this->frame;
    }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
      if (this->capacity == this-> size){
        return false;
      }
      else{
        Bar bc(name, value, category);
        this->bars[size] = bc;
        size++;
        }
      return true;
    }

    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() {
        return this->size;
    }

    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
        if (i < 0 || i >= size)
        {
          throw out_of_range("BarChart: i out of bounds");
        }
        return this->bars[i];
    }

    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes. output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
      sort(bars, bars + size, greater<Bar>());   // sorts in descending order
      output << "frame: "<< this->frame << endl;
      for (int i = 0; i < (this->size); i++) {
        output <<this->bars[i].getName() << " ";
        output << this->bars[i].getValue() << " ";
        output << this->bars[i].getCategory();
        output << endl;
      }
    }

    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // number of BOXs printed for the top bar (max value)
      sort(bars, bars + size, greater<Bar>());   // sorts in descending order
      string color;  // variable for assigning color for the bars
      int varMaxTop = this->bars[0].getValue();   // gets the highest order
      int num = 0;
      double boxLenght = 0;   // varaible for calcaulating box

      for (int i = 0; i < top; ++i) {
        num = this->bars[i].getValue();
        boxLenght = ((double) num/varMaxTop);
        boxLenght = floor(boxLenght * lenMax);   // gets the highest integer value
        string barstr = "";                      //  varaible for taking boxes and printing.

        // iterates until the lenth of the bar and assgins the box to barstr
        for (int i = 0; i < boxLenght; i++) {
            barstr += BOX;
        }

        // checks for colorMap if key is present assign color,
        // if not assgins black color and assgin default color to black
        if (colorMap.count(this->bars[i].getCategory()) > 0) {
          color = colorMap[this->bars[i].getCategory()];
        }
        else {
          colorMap[this->bars[i].getCategory()] = BLACK;
          color = colorMap[this->bars[i].getCategory()];
        }
        output << color << barstr << " " << this->bars[i].getName() << " " << this->bars[i].getValue() << endl;
        color = BLACK;
      }
    }
};
