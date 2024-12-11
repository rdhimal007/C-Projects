#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"


TEST(grid, defaultConstructor) {
  cout << "Hello" << endl;

//   Grid <int > test1;
//   ASSERT_EQ (test1.numrows(), 4);
//   Grid <char > test2;
//  ASSERT_EQ (test2.numrows(), 4);
//   Grid <double > test3;
//   ASSERT_EQ (test3.numrows(), 4);
//   Grid <float > test4;
//   ASSERT_EQ (test4.numrows(), 4);
//   Grid <string > test5;
//   ASSERT_EQ (test5.numrows(), 4);
//   //TO DO:  Write 100s of asserts per member function.


//   cout << "Using parameter " << endl;
//    Grid <int > ptest1(5, 1);
// //    ptest1(5, 4);
//   ASSERT_EQ (ptest1.numrows(), 5);

//   cout << "testing 2 of parameter" << endl;
//    Grid <int > ptest2(4, 4);
// // //    ptest2;
// //   ASSERT_EQ (ptest2.numrows(), 4);
// //   ASSERT_EQ (ptest2.numcols(4), 4);
// //   ASSERT_EQ (ptest2.size(), 16);
// //   cout << ptest2(1, 4) << endl;
//   ASSERT_EQ(ptest2(1,3), 0);
//   cout << "ok" << endl;


}

// TEST(grid, paraConstructor) {
//   Grid <int > test1;
//   ASSERT_EQ (test1.numrows(), 4);
//   cout << "Using parameter " << endl;
//   Grid <int > ptest1(5, 4);
//   test1 = ptest1;
//   ASSERT_EQ (test1.numrows(), 5);
//   cout << "testing out put" << endl;
//   test1._output();


//   Grid <int > test3(1, 1);
//   test3._output();





// }

// TEST(grid, copyTest) {
//     cout << "Using copytest " << endl;
//     Grid <int > g1(5,4);
//     Grid <int > g2(g1);
//     ASSERT_EQ (g2.numrows(), 5);
//  }


// TEST(grid, deepTest) {
//   cout << "Going Deep Test" << endl;
// //   Grid <int > g1;
//   Grid <int > g1(10,5);
//   size_t x = g1.numrows();
//   size_t y = g1.numcols(3);
//   size_t z = g1.size();
//   int a = g1(5,1);
//   g1(0,3) = 57;
//   Grid<int> g2(g1);
//   Grid<int> g3; g3 = g1;
//   g1._output();
//   g2._output();


// }






// TO DO:  Write many TESTs, at least one for, if not more,
// for each member function.  Each tests should have 100s of assertions.






// TO DO:  As you get to each milestone, you can comment out these provided
// tests.  They currently use grid.h and will segfault until you implement
// grid correctly.


// // //// Provided Test: sample maze from handout, make lots more yourself!
// TEST(maze, basic) {
//    vector<string> textMaze;

//    textMaze.push_back("* *-W *");
//    textMaze.push_back("| |   |");
//    textMaze.push_back("*-* * *");
//    textMaze.push_back("  | | |");
//    textMaze.push_back("S *-*-*");
//    textMaze.push_back("|   | |");
//    textMaze.push_back("*-*-* P");

//    Maze m(textMaze);

//    MazeCell* start = m.getStart(2, 2);

//    /* These paths are the ones in the handout. They all work. */
//    EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
//    EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
//    EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

//    /* These paths don't work, since they don't pick up all items. */
//    EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
//    EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
//    EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

//    /* These paths don't work, since they aren't legal paths. */
//    EXPECT_FALSE(isPathToFreedom(start, "WW"));
//    EXPECT_FALSE(isPathToFreedom(start, "NN"));
//    EXPECT_FALSE(isPathToFreedom(start, "EE"));
//    EXPECT_FALSE(isPathToFreedom(start, "SS"));
// }

// Provided Test: don't allow going through walls
// TEST(maze, tryingToGoThroughWalls) {
//    vector<string> textMaze;

//    textMaze.push_back("* S *");
//    textMaze.push_back("     ");
//    textMaze.push_back("W * P");
//    textMaze.push_back( "     ");
//    textMaze.push_back( "* * *");

//    Maze m(textMaze);
//   cout << "d"

//    MazeCell* start = m.getStart(1, 1);

//    EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
//    EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
//    EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
//    EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
// }

// // Provided Test: Works when starting on an item
// TEST(maze, startOnItem) {
//    vector<string> textMaze;

//    textMaze.push_back("P-S-W");

//    Maze m(textMaze);
//    MazeCell* start = m.getStart(0, 0);

//    EXPECT_TRUE(isPathToFreedom(start, "EE"));
//    start = m.getStart(0, 1);
//    EXPECT_TRUE(isPathToFreedom(start, "WEE"));
//    start = m.getStart(0, 2);
//    EXPECT_TRUE(isPathToFreedom(start, "WW"));

// }

// // Provided Test: Reports errors if given illegal characters.
// TEST(maze, invalidChar) {
//    vector<string> textMaze;

//    textMaze.push_back("* *-W *");
//    textMaze.push_back("| |   |");
//    textMaze.push_back("*-* * *");
//    textMaze.push_back("  | | |");
//    textMaze.push_back("S *-*-*");
//    textMaze.push_back("|   | |");
//    textMaze.push_back("*-*-* P");

//    Maze m(textMaze);
//    MazeCell* start = m.getStart(0, 0);

//    /* These paths contain characters that aren't even close to permissible. */
//    EXPECT_FALSE(isPathToFreedom(start, "Q"));
//    EXPECT_FALSE(isPathToFreedom(start, "X"));
//    EXPECT_FALSE(isPathToFreedom(start, "!"));
//    EXPECT_FALSE(isPathToFreedom(start, "?"));

//    EXPECT_FALSE(isPathToFreedom(start, "n"));
//    EXPECT_FALSE(isPathToFreedom(start, "s"));
//    EXPECT_FALSE(isPathToFreedom(start, "e"));
//    EXPECT_FALSE(isPathToFreedom(start, "w"));

//    ///* These are tricky - they're legal paths that happen to have an unexpected
//    // * character at the end.
//    start = m.getStart(2, 2);
//    EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
//    EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
//    EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));

// }

// // Provided Test: This tests your personalized regular maze to see if you were
// // able to escape.
// TEST(maze, escapeRegularMaze) {
//    Maze m(4, 4);
//    MazeCell* start = m.mazeFor(kYourName);
//    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
// }

// // Provided Test: This tests your personalized twisty maze to see if you were
// // able to escape.
// TEST(maze, escapeTwistyMaze) {
//    Maze m(4, 4);
//    MazeCell* start = m.twistyMazeFor(kYourName);
//    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
// }
