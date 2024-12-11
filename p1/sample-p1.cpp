//
//  Project 1 Starter Code - DNA Profiling
//  TODO:  Put your header info here.  Update line above.
//  Name: roshan dhimal, UIN: 661652338
//  Class: Cs 251
//  Profesor: Joe Hummel, Fall 2021

#include "ourvector.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;




// creating the struct
struct identity{
    string Names;
    ourvector<int> V2;
};
//funtions for the program

// bool keyCheck(string keyEnter)
// {
//     if (keyEnter == "load_db" || keyEnter == "load_dna")
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }

// }

void parsefirst(string name, ourvector<ourvector<char>> &stuff1)
{
    stringstream sline(name);
    string data;
    getline(sline, data, ',');

    while (getline(sline, data, ','))
    {
        ourvector<char> data1;
        for(char c: data)
        {
            data1.push_back(c);
        }
        stuff1.push_back(data1);
    }

}

void parseSecond(string lines, ourvector<identity> &People)
{
    stringstream sline(lines);
    string name;
    getline(sline, name, ',');
    identity id;
    id.Names = name;
    while(getline(sline, name, ','))
    {
        id.V2.push_back(stoi(name));
    }
    People.push_back(id);
}

// Milestone #1 – Load in the database – load_db
void loadData(ourvector<ourvector<char>> &stuff1, string &fileName, ourvector<identity> &People){
    ifstream infile(fileName);
    if (!infile.good()) {
        cout << "Error: unable to open '" << fileName << "'"<< endl;
        return;
    }
    cout << "Loading database..." << endl;
    string lines;
    getline(infile, lines, '\n');
    parsefirst(lines, stuff1);

    while (getline(infile, lines, '\n'))
    {
        parseSecond(lines, People);
    }


    //  for (identity pep: People)
    //  {
    //      cout << pep.Names <<  " ";
    //      for (int  a: pep.V2)
    //      {
    //          cout << a << " ";
    //      }
    //      cout << endl;
    //  }

    // for(ourvector<char> g : stuff1)
    // {
    //     for(char e : g)
    //     {
    //         cout << e;
    //     }
    //     cout << endl;
    // }


}


// Milestone #2 – Display your data -- display

void displayFunc(ourvector<identity> People, ourvector<char>Dna )
{
    if (People.size() > 0)
    {
     for (identity pep: People)
     {
         cout << pep.Names <<  " ";
         for (int  a: pep.V2)
         {
             cout << a << " ";
         }
         cout << endl;

     }
     cout << endl;

    }
    if (Dna.size() > 0)
    {
        cout << "DNA loaded:" << endl;
        for (char i: Dna)
        {
            cout << i;
        }
        cout << endl;

    }

    else
    {
        cout << "No DNA loaded." << endl;
        cout << endl;
        cout << "No DNA has been processed." << endl;

    }


}


// Milestone #3 – Load in the dna – load_dna
 void loadDnafunc(ourvector<char> &dnaVector, string &fileName)
 {
    ifstream infile(fileName);
    if (!infile.good())
    {
        cout << "Error: unable to open '" << fileName << "'"<< endl;
        return;
    }
    cout << "loading DNA..." << endl;

    string dnaLines;

    while(getline(infile, dnaLines, '\n'))
    {
        for (char c: dnaLines)
        {
            dnaVector.push_back(c);
        }
    }


}


// mathchig to find the vector string
bool matchFUnc(urvector<ourvector<char>> &Strs, ourvector<char> &dnaVector, int i)
{

}

// Milestone #4 – Process the DNA – process
void processDna(ourvector<char> &dnaVector,ourvector<ourvector<char>> &Strs, ourvector<identity> &People)
{
    for (int i =0; i < dnaVector.size(); i++)
    {
        // if (matchFUnc(Strs, dnaVector, ))
    }

}


// Milestone #5 – Search the database– search
// Milestone #6 – Creative component





int main(){

    //TODO:  Write your code here.  You should have LOTS of function decomposition.
    cout << "Welcome to the DNA Profiling Application." << endl;

    // declaring the variables for the keybaord entry
    string commd, fileName;
    cout << "Enter command or # to exit: ";
    cin >> commd;

    ourvector<ourvector<char>> Strs;  // container for the STR
    ourvector<identity> People;   // container of vector of structs that store names and vector container of integer.
    ourvector<char>Dnas;    // container for containnig dna files

    while (commd != "#"){
        if (commd == "load_db")
        {
            cin >> fileName;
            loadData(Strs, fileName, People);

        }
        else if(commd == "display")
        {
            displayFunc(People, Dnas);
            cout << endl;
        }

        else if (commd == "load_dna")
        {
            cin >> fileName;
            loadDnafunc(Dnas, fileName);
        }
        else if(commd == "process")
        {
            processDna(Dnas, People, Strs);
        }


        cout << "Enter command or # to exit: ";
        cin >> commd;
    }





    // cout << "Database loaded:" << endl;
    // cout << "No DNA loaded." << endl;
    // cout << "No DNA has been processed." << endl;
    // cout << "Processing DNA..." << endl;
    // cout << "Searching database..." << endl;
    // cout << "Found in database!  DNA matches: ";






    return 0;
}
