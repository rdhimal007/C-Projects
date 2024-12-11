// mymap.h
// Name: roshan dhimal, UIN: 661652338
// Class: CS 251; Fall 2021
// Assignment: Project 5- mymap
// Professor: Joe Hummel, PhD

// TODO: write this file header comment.
#pragma once

#include <iostream>
#include <sstream>

using namespace std;

template<typename keyType, typename valueType>
class mymap {
 private:
    struct NODE {
        keyType key;  // used to build BST
        valueType value;  // stored data for the map
        NODE* left;  // links to left child
        NODE* right;  // links to right child
        int nL;  // number of nodes in left subtree
        int nR;  // number of nodes in right subtree
        bool isThreaded;
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of key/value pairs in the mymap

    //
    // iterator:
    // This iterator is used so that mymap will work with a foreach loop.
    //
    struct iterator {
     private:
        NODE* curr;  // points to current in-order node for begin/end

     public:
        iterator(NODE* node) {
            curr = node;
        }

        keyType operator *() {
            return curr -> key;
        }

        bool operator ==(const iterator& rhs) {
            return curr == rhs.curr;
        }

        bool operator !=(const iterator& rhs) {
            return curr != rhs.curr;
        }

        bool isDefault() {
            return !curr;
        }

        //
        // operator++:
        //
        // This function should advance curr to the next in-order node.
        // O(logN)
        //
        iterator operator++() {
          if ( curr-> isThreaded) {
            curr = curr -> right;
          }
          else {
            curr = curr->right;
            while(curr->left != nullptr) {
              curr = curr->left;
              }
            }

          return iterator(curr);
        }
    };

    // helper function adding thread
    NODE* goingLeft(NODE* cur) {
      return cur->left;
    }

    NODE* goingRight(NODE* cur) {
      if (cur == nullptr) {
      return nullptr;
      }
      else if (cur->isThreaded) {
        return nullptr;
      }
      else {
        return  cur->right;
      }
    }

    // delete the left than right
   void nodeDelete(NODE* node) {
     if (node == nullptr ) {
       return;
     }
     nodeDelete(goingLeft(node));
     nodeDelete(goingRight(node));
     delete node;
     this->size--;
   }


   // helper function for copying the node
//   NODE* copyNode(NODE* otherPointer) {
//     // check for null
//     if (otherPointer == nullptr) {
//       return otherPointer;
//     }
//     // create new node
//     NODE* newNode = new NODE();
//     newNode->left = otherPointer->left;
//     newNode->right = otherPointer->right;
//     // updating values and keys
//     newNode->key = otherPointer->key;
//     newNode->value = otherPointer->value;
//     newNode ->nL = otherPointer->nL;
//     newNode ->nR = otherPointer->nR;
//     newNode->isThreaded = otherPointer->isThreaded;

//     // left and then right
//     newNode->left = copyNode(otherPointer->left);   // left
//     newNode->right = copyNode(goingRight(otherPointer->right));  // right

//     // return the root
//     return newNode;

//   }
void copyNode(NODE* otherPointer) {
    if (otherPointer == nullptr) {
      return;
    }
    put(otherPointer->key, otherPointer->value);
    copyNode(otherPointer->left);   // left
    copyNode(goingRight(otherPointer->right));  // right
}

  // checking balance of the node

  // helper function for ouputing string
   void _buildString(NODE* node, ostream& out) {

    if ( node == nullptr) {
        return;
      }
      _buildString(goingLeft(node), out);
      out << "key: " << node -> key << " value: " << node -> value << endl;
      _buildString(goingRight(node), out);
    }

   // helper function for vector output string
   void _vectorString(NODE* node, vector<pair<keyType, valueType>>& toVector) {
			if ( node == nullptr) {
        return;
      }
      _vectorString(goingLeft(node), toVector);
			pair<keyType, valueType> pa(node -> key, node -> value);
      toVector.push_back(pa);
      _vectorString(goingRight(node), toVector);
    }


		// helprer function for the balance string output
		void _balanceTest(NODE* node, ostream& out) {
		if (node == nullptr) {
			return;
		}
		out << "key: " << node -> key << " nL: " << node -> nL << " nR: " << node -> nR  << endl;
		_balanceTest(goingLeft(node), out);
		_balanceTest(goingRight(node), out);
// 		out << "key: " << node -> key << " nL: " << node -> nL << " nR: " << node -> nR  << endl;

		}


 public:
    //
    // default constructor:
    //
    // Creates an empty mymap.
    // Time complexity: O(1)
    //
    mymap() {
      this-> root =  nullptr;
      this-> size = 0;
    }

    //
    // copy constructor:
    //
    // Constructs a new mymap which is a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(nlogn), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap(const mymap& other) {
      this->root = nullptr;

      this->size = 0;
      copyNode(other.root);
      this->size = other.size;
    }

    //
    // operator=:
    //
    // Clears "this" mymap and then makes a copy of the "other" mymap.
    // Sets all member variables appropriately.
    // Time complexity: O(nlogn), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    mymap& operator=(const mymap& other) {
//     cout << "here" << endl;
    if (this == &other)
      return *this;
//     NODE* cur = this->root;
//     nodeDelete(cur); // destroy the all the prevoius nodes
//     this->root = nullptr;
//     this->size = 0;
// destroy the all the prevoius nodes
    clear();
    copyNode(other.root);
//     this->size = 0;

     return *this;
    }

    // clear:
    //
    // Frees the memory associated with the mymap; can be used for testing.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    void clear() {
      NODE* cur = this->root;
      nodeDelete(cur);
      this-> size = 0;
      this->root = nullptr;

    }

    //
    // destructor:
    //
    // Frees the memory associated with the mymap.
    // Time complexity: O(n), where n is total number of nodes in threaded,
    // self-balancing BST.
    //
    ~mymap() {
      NODE* cur = this->root;
      nodeDelete(cur);
      this-> size = 0;
      this->root = nullptr;
    }

    //
    // put:
    //
    // Inserts the key/value into the threaded, self-balancing BST based on
    // the key.
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-tree that needs to be re-balanced.
    // Space complexity: O(1)
    //
    void put(keyType key, valueType value) {
      NODE* prev = nullptr;
      NODE* cur = this->root;
      // loop until the null pointer
      while (cur != nullptr) {
        // key is found return from the loop
        if ( key == cur->key) {
          cur->value = value;
          return;
        }
        else if (key < cur->key) {   // less the key move left
          cur->nL++;
          prev = cur;
          cur = goingLeft(cur);
        }
        else {    // move right
          cur->nR++;
          prev = cur;
          cur = goingRight(cur);
        }
      }

      // if not found creating new node and adding
      NODE* newNode = new NODE();
      newNode->left = nullptr;
      newNode->right = nullptr;
      // updating values and keys
      newNode->key = key;
      newNode->value = value;
      newNode ->nL = 0;
      newNode ->nR = 0;
      newNode->isThreaded = false;
      // adding in first
      if (prev == nullptr) {
       newNode->isThreaded = true;
        this->root = newNode;

      }

      else if (key < prev->key) {   // linking at left
      prev->left = newNode;
        newNode->right = prev;
        newNode->isThreaded = true;
      }
      else {     // linking to right
        newNode->right = prev->right;
        prev->right = newNode;
        newNode->isThreaded = true;
        prev->isThreaded = false;
      }
      this->size++;    // increase the size


    }

    //
    // contains:
    // Returns true if the key is in mymap, return false if not.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    bool contains(keyType key) {
      NODE* cur = this->root;
      while (cur != nullptr) {
        if (key == cur->key) {
          return true;
        }
        else if ( key < cur->key) {
          cur = goingLeft(cur);
        }
        else {
          cur = goingRight(cur);
        }
      }
       return false;
    }

    //
    // get:
    //
    // Returns the value for the given key; if the key is not found, the
    // default value, valueType(), is returned (but not added to mymap).
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    valueType get(keyType key) {
      NODE* cur = this->root;
      while (cur != nullptr) {
        if (key == cur->key) {
          return cur->value;
        }
        else if ( key < cur->key) {
          cur = goingLeft(cur);
        }
        else{
          cur = goingRight(cur);
        }
      }
       return valueType();
    }

    //
    // operator[]:
    //
    // Returns the value for the given key; if the key is not found,
    // the default value, valueType(), is returned (and the resulting new
    // key/value pair is inserted into the map).
    // Time complexity: O(logn + mlogm), where n is total number of nodes in the
    // threaded, self-balancing BST and m is the number of nodes in the
    // sub-trees that need to be re-balanced.
    // Space complexity: O(1)
    //
    valueType operator[](keyType key) {
      if (contains(key) == true)
        return get(key);
      put(key, valueType());
      return valueType();
    }

    //
    // Size:
    //
    // Returns the # of key/value pairs in the mymap, 0 if empty.
    // O(1)
    //
    int Size() {
      return this->size;
    }

    //
    // begin:
    //
    // returns an iterator to the first in order NODE.
    // Time complexity: O(logn), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    iterator begin() {
      NODE* cur = this-> root;
      if (cur == nullptr) {
        return iterator(cur);
      } else {
      while( cur->left !=  nullptr) {
        cur = cur->left;
        }
      }
      return iterator(cur);

    }

    //
    // end:
    //
    // returns an iterator to the last in order NODE.
    // this function is given to you.
    //
    // Time Complexity: O(1)
    //
    iterator end() {

      return iterator(nullptr);
    }

    //
    // toString:
    //
    // Returns a string of the entire mymap, in order.
    // Format for 8/80, 15/150, 20/200:
    // "key: 8 value: 80\nkey: 15 value: 150\nkey: 20 value: 200\n
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string toString() {
      stringstream ss;
      _buildString(root, ss);
      return ss.str();
    }


    //
    // toVector:
    //
    // Returns a vector of the entire map, in order.  For 8/80, 15/150, 20/200:
    // {{8, 80}, {15, 150}, {20, 200}}
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    vector<pair<keyType, valueType>> toVector() {
    NODE* cur = this->root;     // taking root node
		vector<pair<keyType, valueType>> vect;   // making vector
		_vectorString(cur, vect);

     return vect;  // returnnig vect
    }

    //
    // checkBalance:
    //
    // Returns a string of mymap that verifies that the tree is properly
    // balanced.  For example, if keys: 1, 2, 3 are inserted in that order,
    // function should return a string in this format (in pre-order):
    // "key: 2, nL: 1, nR: 1\nkey: 1, nL: 0, nR: 0\nkey: 3, nL: 0, nR: 0\n";
    // Time complexity: O(n), where n is total number of nodes in the
    // threaded, self-balancing BST
    //
    string checkBalance() {
		NODE* cur = this->root;
     stringstream ss;
     _balanceTest(cur, ss);
     return ss.str();
    }
};
