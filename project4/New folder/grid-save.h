// Name: roshan dhimal, UIN: 661652338
// Class: CS 251; Fall 2021
// Assignment: Project 3 - Animated Bar Chart
// Professor: Joe Hummel, PhD

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct CELL {
    CELL* Next;
    T Val;
    size_t NumCols;  // total # of columns (0..NumCols-1)
    CELL(CELL* _Next = nullptr, T _Val = T(), size_t _NumCols = 0) {
      Next = _Next;
      Val = _Val;
      NumCols = _NumCols;
    }
  };

  size_t NumRows;  // total # of rows (0..NumRows-1)
  CELL** Rows;     // C array of linked lists
  // clear function for destruction of the each element and rows
  void clear() {
    for (int i = 0; i < NumRows; i++) {
      CELL* cur = Rows[i];
      CELL* prev = nullptr;
      while (cur != nullptr) {
        prev = cur;
        cur = cur->Next;
        delete prev;
      }
    }
    if (Rows != nullptr) {
      delete[] Rows;
      }
  }

public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 Grid.  All
  // elements are initialized to the default value of T.
  //
  Grid() {
    // initialize 4 rows
    Rows = new CELL*[4];
    NumRows = 4;
    // allocate the first cell of the linked list with default value:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r] = new CELL(nullptr, T(), 4);
      CELL* cur = Rows[r];
      // create the linked list for this row.
      for (size_t c = 1; c < Rows[r]->NumCols; ++c) {
        cur->Next = new CELL(nullptr, T());
        cur = cur->Next;
        }
    }
  }
  //
  // parameterized constructor:
  //
  // Called automatically by C++ to construct a Grid with R rows,
  // where each row has C columns. All elements are initialized to
  // the default value of T.
  //
  Grid(size_t R, size_t C) {
    Rows = new CELL*[R];
    NumRows = R;
    // allocate the first cell of the linked list with default value:
    for (size_t r = 0; r < NumRows; ++r) {
      Rows[r] = new CELL(nullptr, T(), C);
      CELL* cur = Rows[r];
      // create the linked list for this row.
      for (size_t c = 1; c < Rows[r]->NumCols; ++c) {
        cur->Next = new CELL(nullptr, T());
        cur = cur->Next;
        }
     }
  }
  //
  // destructor:
  //
  // Called automatically by C++ to free the memory associated by the vector.
  //
  virtual ~Grid() {
    for (int i = 0; i < NumRows; i++) {
      CELL* cur = Rows[i];
      CELL* prev = nullptr;
      while(cur != nullptr) {
        prev = cur;
        cur = cur->Next;
        delete prev;
     }
   }
   if (Rows != nullptr) {
     delete[] Rows;
     }
  }
  //
  // copy constructor:
  //
  // Called automatically by C++ to construct a Grid that contains a
  // copy of an existing Grid.  Example: this occurs when passing
  // Grid as a parameter by value
  //
  //   void somefunction(Grid<int> G2)  <--- G2 is a copy:
  //   { ... }
  //
  Grid(const Grid<T>& other) {
    Rows = new CELL*[other.NumRows];
    NumRows = other.NumRows;
    CELL* cur = nullptr;
    CELL* thisOther = nullptr;
    for (int i = 0; i < NumRows; i++) {
      Rows[i] = new CELL(nullptr, other.Rows[i]->Val, other.Rows[i]->NumCols);
      cur = Rows[i];
      thisOther = other.Rows[i];
      int num = thisOther->NumCols;
      thisOther = thisOther->Next;
      for (int j = 1; j < num; j++ ) {
        cur->Next = new CELL(nullptr, thisOther->Val, thisOther->Val);
        thisOther = thisOther->Next;
        cur = cur->Next;
      }
    }
  }
  //
  // copy operator=
  //
  // Called when you assign one vector into another, i.e. this = other;
  //
  Grid& operator=(const Grid& other) {
    if (this == &other) {
      return *this;
    }
    clear();
    Rows = new CELL*[other.NumRows];
    this-> NumRows = other.NumRows;
    CELL* cur = nullptr;
    CELL* thisOther = nullptr;
    for (int i = 0; i < NumRows; i++) {
      Rows[i] = new CELL(nullptr, other.Rows[i]->Val, other.Rows[i]->NumCols);
      cur = Rows[i];
      thisOther = other.Rows[i];
      int num = thisOther->NumCols;
      thisOther =thisOther->Next;
      for (int j = 1; j < num; j++ ) {
        cur->Next = new CELL(nullptr, thisOther->Val, thisOther->NumCols);
        thisOther = thisOther->Next;
        cur = cur->Next;
      }
    }
    return *this;
  }
  //
  // numrows
  //
  // Returns the # of rows in the Grid.  The indices for these rows
  // are 0..numrows-1.
  //
  size_t numrows() const {
    return this->NumRows;
  }
  //
  // numcols
  //
  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  For now, each row will have the same number of columns.
  //
  size_t numcols(size_t r) const {
      return this->Rows[0] -> NumCols;
  }
  //
  // size
  //
  // Returns the total # of elements in the grid.
  //
  size_t size() const {
    return this -> NumRows* Rows[0] -> NumCols;
  }
  //
  // ()
  //
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    grid(r, c) = ...
  //    cout << grid(r, c) << endl;
  //
  T& operator()(size_t r, size_t c) {
    if ((r < 0)|| (c < 0) || (r >= NumRows) || (c >= this->Rows[r]->NumCols) ) {
      throw runtime_error("Not in range");
    }
    CELL* cur = this->Rows[r];
    int i = 0;
    while (i < c) {
      cur = cur-> Next;
      i++;
    }
    return cur->Val;
  }
  //
  // _output
  //
  // Outputs the contents of the grid; for debugging purposes.  This is not
  // tested.
  //
  void _output() {
    cout << "*** OUTPUT START***" << endl;
    for (int i = 0; i < NumRows; i++) {
      CELL* cur = Rows[i];
      CELL* prev = nullptr;
      while (cur != nullptr) {
        prev = cur;
        cur = cur->Next;
        cout << prev->Val <<  "  ";
      }
      cout << endl;
    }
  }
};
