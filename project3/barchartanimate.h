// Name: roshan dhimal, UIN: 661652338
// Class: CS 251; Fall 2021
// Assignment: Project 3 - Animated Bar Chart
// Professor: Joe Hummel, PhD

// barchartanimate.h
// The the Bar Chart Animation functionality is carried out
// in this abstraction the private member stores the c-style array
// of barcharrts, size, capacity, map of color,
// the public function uses this member to produce the graph,
// add frame, ttile, comstructs and destroys after the inilaization

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unistd.h>
#include "myrandom.h"    // used in autograder, do not remove
#include "barchart.h"

using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.

    //private members for assignning category for bars,
    //  maps of color, title, label and the source of the data;
    BarChart* barcharts;   // pointer to a C-style array of barcharts
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    int count;  // variables to track vector of colors

 public:
    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    // assign size 0, title, label and source as parameterized
    BarChartAnimate(string title, string xlabel, string source) {
      this-> barcharts = new BarChart[4];
      this-> capacity = 4;
      this-> size = 0;
      this -> title = title;
      this -> xlabel = xlabel;
      this -> source = source;
      this -> count = 0;
    }
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    virtual ~BarChartAnimate() {
      if (barcharts != nullptr) {
        delete[] barcharts;
      }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity
    // creates the new barchart pointer with the double the capacity
    // infiles all the txt data to frame and assigs them color
    void addFrame(ifstream &file) {
      if (this->size == this->capacity) {
        int newCapacity = (this->capacity * 2);
        BarChart* newChart = new BarChart[newCapacity];
        for (int i = 0; i < this->size ; i++) {
          newChart[i] = this-> barcharts[i];
        }
        delete[] this->barcharts;
        this->barcharts = newChart;
        this->capacity = newCapacity;
      }

      // declaration of varables of year, name, country,
      // value and category respectively
      string takeIternum, yearFrame, takeName, takeCountry, takeValue, takeCategory;
      getline(file, takeIternum);   // gets the black space
      getline(file, takeIternum);   // gets the number
      int numIter = 0;   // variable for iterating number of lines

      // if the infile contenet is not empty string
      // takes it and converts the string into numbers, else returns
      if (takeIternum != "") {
        numIter = stoi(takeIternum);
      }
      else {
        return;
      }
      // creates the barchart with the number of iterating lines from txt files
      BarChart bcFrame(numIter);
      // iterates until it gets year, name, country, value and category
      for (int j = 0; j < numIter;  j++) {
        getline(file, yearFrame, ',');
        getline(file, takeName, ',');
        getline(file, takeCountry, ',');
        getline(file, takeValue, ',');
        int convValue = stoi(takeValue);   // converting to integer
        getline(file, takeCategory);
        bcFrame.addBar(takeName, convValue, takeCategory);
        bcFrame.setFrame(yearFrame);
        // assigns the vectors of color into the map of key and color
        if (this->colorMap.count(takeCategory) == 0) {
          if (count == COLORS.size()) {
            count = 0;
          }
          string newCountColor = COLORS.at(count);
          this->colorMap[takeCategory] = newCountColor;
          count++;
          // this->colorMap[takeCategory] = COLORS[(count++)% COLORS.size()];
        }
      }
      // assgins the updaated bar to the barchart
      this->barcharts[size] = bcFrame;
      size++;      // increses the sizes of the barchart
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.
    // refreshes the frmaes with each interation and outputs the grapgh,
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50090;     // frames refresh rate
    string barstr = "";
    // if the end value is less the 0, it takes the size of the filled barchart
    if (endIter < 0) {
      endIter = this->size;
    }

    // interates until the given endvalue if not negative
    for (int i = 0; i < endIter; i++) {
      usleep(3 * microsecond);   // refresh speed
      output << CLEARCONSOLE;   // clears the screen
      output << BLACK <<  this->title << "\n" << this->source << endl;
      this->barcharts[i].graph(output, this->colorMap, top);
      output << BLACK << this-> xlabel << endl;
      output << BLACK << "Frame: " << this->barcharts[i].getFrame() << endl;
    }
	}

// cretaive portion of the barchart
// takes the speed varable and outputs the graph
void animate(ostream &output, int top, int endIter, int speed) {
  unsigned int microsecond = speed;              // frames refresh rate
  string barstr = "";
  // if the end value is less the 0, it takes the size of the filled barchart
  if (endIter < 0) {
    endIter = this->size;
  }

  double a = 1.00;  // varaible for calcaulating percentage
  int movement = 0;  // variable for animation
  for (int i = 0; i < endIter; i++) {
    double prcProgress = ((double)( a/ (double) endIter));
    a++;
    double cs = prcProgress * 100;
    usleep(3 * microsecond);    // refresh speed
    output << CLEARCONSOLE;    // clears the screen
    output << BLACK <<  this->title << "\n" << this->source << endl;
    this->barcharts[i].graph(output, this->colorMap, top);
    output << BLACK << this-> xlabel << endl;
    output << BLACK << "Frame: " << this->barcharts[i].getFrame() << endl;
    output << BLACK << "Progress: " << round(cs) << endl;

    //  if block for printing arraw animation
    if (movement == 0 && round(cs) != 100) {
      output << BLUE << "  \\" << endl;
      output << BLUE << "===>>" << endl;
      output << BLUE << "  /" << endl;
      movement++;
    }
    else {
      output << BLUE << "           \\" << endl;
      output << BLUE << "       =====>>" << endl;
      output << BLUE << "           /" << endl;;
      movement--;
    }
  }
}
    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize() {
        return this->size;
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i) {
      if (i < 0 || i >= size) {
        throw out_of_range("BarChartAnimate: i out of bounds");
      }
      return this->barcharts[i];
    }
};
