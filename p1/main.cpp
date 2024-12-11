//
//  Project 1 Starter Code - DNA Profiling
//  Name: roshan dhimal, UIN: 661652338
//  Class: Cs 251 Fall 2021.
//  Profesor: Joe Hummel, Fall 2021

#include "ourvector.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
// Struct creation that store the Names of the patient and the vecor containers,
// that stores the STRs of the individuals
struct identity {
    string Names;
    ourvector<int> V2;
};
// parsing through the infile into the vector
void parsefirst(string& name, ourvector<ourvector<char>>& stuff1){
    stringstream sline(name);
    string data;
    getline(sline, data, ',');

    while (getline(sline, data, ',')){
        ourvector<char> data1;
        for (char c : data){
            data1.push_back(c);
        }
        stuff1.push_back(data1);
    }
}
// parsing the second line of the struct with the STR number of the individuals
void parseSecond(string& lines, ourvector<identity>& People){
    stringstream sline(lines);
    string name;
    getline(sline, name, ',');
    identity id;
    id.Names = name;
    while (getline(sline, name, ',')){
        id.V2.push_back(stoi(name));
    }
    People.push_back(id);
}
// Milestone #1 � Load in the database � load_db
void loadData(ourvector<ourvector<char>>& stuff1, string& fileName, ourvector<identity>& People) {
    cout << "Loading database..." << endl;
    ifstream infile(fileName);
    if (!infile.good()) {
        cout << "Error: unable to open '" << fileName << "'" << endl;
        return;
    }
    People.clear();
    string lines;
    getline(infile, lines, '\n');
    parsefirst(lines, stuff1);
    while (getline(infile, lines, '\n')){
        parseSecond(lines, People);
    }
}

//returning the numers of the matched number froom the stored vector
int gettingNum(ourvector<int>& numStor){
  int a = 0;
  for(int i : numStor){
    a = i;
    break;
  }
  return a;
}
// Milestone #2 � Display your data -- display

void displayFunc(ourvector<identity>& People, ourvector<char>&Dna, ourvector<int>& numStor, ourvector<ourvector<char>>& Strs){
    if (People.size() > 0){
        cout << "Database loaded: " << endl;
        for (identity pep : People){
            cout << pep.Names;
            for (int a : pep.V2){
                cout << " " << a ;
            }
            cout << endl;
        }
        cout << endl;
    }
    if (People.size() <= 0){
      cout << "No database loaded." << endl;
    }
    if (Dna.size() > 0){
        cout << "DNA loaded: " << endl;
        for (char i : Dna){
            cout << i;
        }
        cout << endl;
        cout << endl;
    }
    if (Dna.size() <= 0){
        cout << "No DNA loaded." << endl;
        cout <<endl;
    }
    if (numStor.size() > 0){
      cout << "DNA processed, STR counts: " << endl;
      int i =0;
      for (ourvector<char> v : Strs){
        for (int i =0; i < v.size(); i++){
          cout << v[i];
        }
        if (i < numStor.size()){
          cout << ": " << numStor[i] << endl;;
          i++;
        }
      }
      cout << endl;
    }
    if (numStor.size() <= 0){
      cout << "No DNA has been processed." << endl;
    }
}
// Milestone #3  Load in the dna  load_dna
void loadDnafunc(ourvector<char>& dnaVector, string& fileName){
    cout << "Loading DNA..." << endl;
    ifstream infile(fileName);
    if (!infile.good()){
        cout << "Error: unable to open '" << fileName << "'" << endl;
        return;
    }
    dnaVector.clear();
    string dnaLines;
    while (getline(infile, dnaLines, '\n')){
        for (char c : dnaLines){
            dnaVector.push_back(c);
        }
    }
}
// mathchig to find the vector string
bool matchFunc(ourvector<char> Strs, ourvector<char> dnaVector, int i){
  for(int j = 0; j < Strs.size(); j++){
    if (i >= dnaVector.size()){
      return false;
    }
    if (Strs[j] != dnaVector[i]){
      return false;
    }
    if(Strs[j] == dnaVector[i]) {
      i++;
    }
  }
  return true;
}
// searching for each char in the 2D vector containers of the Srs
char eachStrSearch(ourvector<char>& Strs){
  char i;
    for (char g: Strs){
      i= g;
      break;
    }
    return i;
}
// Milestone #4  Process the DNA process
int processOneStr(ourvector<char>& Strs,ourvector<char>& dnaVector){
   int i = 0;
   int count = 0;
   cout << St
    while (i < dnaVector.size()){
      if (dnaVector[i] == eachStrSearch(Strs)){
        if (matchFunc(Strs, dnaVector, i) == true){
          count++;
          i = i + Strs.size();
        }
        else{
          i++;
        }
      }
      else{
        i++;
      }
    }
    return count;
}
// milestone 4: Process Dna first part.
void processDna(ourvector<ourvector<char>>& Strs, ourvector<char>& dnaVector,ourvector<int>& numStor ){

  if ((Strs.size() > 0) && (dnaVector.size() > 0)){
    for (ourvector<char> content: Strs){
        numStor.push_back(processOneStr(content, dnaVector));
      }
      cout << "Processing DNA..." << endl;
  }
  if (Strs.size() <= 0){
    cout << "No database loaded." << endl;
    return;
  }
  if (dnaVector.size() <= 0){
    cout << "No DNA loaded." << endl;
    return;
  }
}

// Milestone #5 Search the database search
void seracFunc(ourvector<int> numStor, ourvector<identity> People, ourvector<ourvector<char>> Strs, ourvector<char>Dnas){
  if (Strs.size() <= 0){
    cout << "No database loaded." << endl;
    return;
  }
  if (Dnas.size() <= 0){
    cout << "No DNA loaded." << endl;
    return;
  }
  if (numStor.size() <= 0){
    cout << "No DNA processed." << endl;
    return;
  }
  cout << "Searching database..." << endl;
  string name = "no";
  if (Dnas.size() > 0 && numStor.size() > 0){
    for (int i = 0; i < People.size(); i++ ){
      int count = 0;
      for (int j =0; j < People[i].V2.size(); j++){
        if (numStor[j] == People[i].V2[j]){
          count++;
        }
      }
      if (count == People[i].V2.size()) {
        name = People[i].Names;
      }
    }
  }
  if (name == "no"){
    cout << "Not found in database" << endl;
  }
  else{
    cout << "Found in database! " << " DNA matches: ";
    cout << name << endl;
  }
}
// Milestone #6 Creative component
int main() {
    cout << "Welcome to the DNA Profiling Application." << endl;
    // declaring the variables for the keybaord entry
    string commd, fileName;
    cout << "Enter command or # to exit: ";
    cin >> commd;
    ourvector<ourvector<char>> Strs;  // container for the STR
    ourvector<identity> People;   // container of vector of structs that store names and vector container of integer.
    ourvector<char>Dnas;    // container for containnig dna files
    ourvector<int> numStor; // container foe stroing the Strs count


  // Dedicated while loop that stops  the profiling program when the users enters '#' key
  // Also process the various desgniated input
    while (commd != "#") {
        if (commd == "load_db"){                      // loads thhe database of the STrs into the 2D vector container
          cin >> fileName;
          loadData(Strs, fileName, People);
        }
        else if (commd == "display") {
            displayFunc(People, Dnas, numStor, Strs);  // ouputs the display of the program
        }
        else if (commd == "load_dna"){                  //  loads the DNA databse into the DNA vector container
            cin >> fileName;
            loadDnafunc(Dnas, fileName);
        }
        else if (commd == "process"){                  // process the counting STRs content into the DNA vector container
            processDna(Strs, Dnas, numStor);
        }
        else if (commd == "search"){                   // search function designed to find the matching content of the DNA and Str content and ouptut the name.

          seracFunc(numStor,People,Strs, Dnas);
        }
        else if (commd == "repeat"){

        }
        cout << "Enter command or # to exit: ";
        cin >> commd;
    }
    return 0;
}
