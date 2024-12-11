#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"

// testing defalt constructor
TEST(grid, defaultConstructor) {
  cout << "Hello  Default" << endl;
  Grid <int > test1;
  ASSERT_EQ (test1.numrows(), 4);
  ASSERT_EQ (test1.numcols(1), 4);
  ASSERT_EQ (test1.numcols(2), 4);
  ASSERT_EQ (test1.numcols(3), 4);
  ASSERT_EQ (test1.numcols(4), 4);
  ASSERT_EQ (test1.numcols(4), 4);
  ASSERT_EQ (test1.size(), 16);
  test1._output();

  Grid <char > test2;
  ASSERT_EQ (test2.numrows(), 4);
  ASSERT_EQ (test2.numcols(1), 4);
  ASSERT_EQ (test2.numcols(2), 4);
  ASSERT_EQ (test2.numcols(3), 4);
  ASSERT_EQ (test2.numcols(4), 4);
  ASSERT_EQ (test2.numcols(4), 4);
  ASSERT_EQ (test2.size(), 16);
  test2._output();

  Grid <double > test3;
  ASSERT_EQ (test3.numrows(), 4);
  ASSERT_EQ (test3.numcols(1), 4);
  ASSERT_EQ (test3.numcols(2), 4);
  ASSERT_EQ (test3.numcols(3), 4);
  ASSERT_EQ (test3.numcols(4), 4);
  ASSERT_EQ (test3.numcols(4), 4);
  ASSERT_EQ (test3.size(), 16);
  test3._output();

  Grid <float > test4;

  ASSERT_EQ (test4.numrows(), 4);
  ASSERT_EQ (test4.numcols(1), 4);
  ASSERT_EQ (test4.numcols(2), 4);
  ASSERT_EQ (test4.numcols(3), 4);
  ASSERT_EQ (test4.numcols(4), 4);
  ASSERT_EQ (test4.numcols(4), 4);
  ASSERT_EQ (test4.size(), 16);
  test4._output();


  Grid <string > test5;
  ASSERT_EQ (test5.numrows(), 4);
  ASSERT_EQ (test5.numcols(1), 4);
  ASSERT_EQ (test5.numcols(2), 4);
  ASSERT_EQ (test5.numcols(3), 4);
  ASSERT_EQ (test5.numcols(4), 4);
  ASSERT_EQ (test5.numcols(4), 4);
  ASSERT_EQ (test5.size(), 16);
  test5._output();
  cout << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      test1(i, j) = i*j;
      test2(i, j) = '*';
      test3(i, j) = double(i*j);
      test5(i, j) = "ok";
    }
  }
  test1._output();
  test2._output();
  test3._output();
  test5._output();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(test1(i, j), i*j);
      ASSERT_EQ(test2(i, j), '*');
      ASSERT_EQ(test3(i, j),double(i*j));
      ASSERT_EQ(test5(i, j),"ok");
    }
  }

}
// testing parameterized constructor
TEST(grid, paraConstructor) {
  Grid <int > test1(5, 4);
  Grid <char > test2(4, 7);
  size_t x = test1.size();
  size_t y = test2.size();
  ASSERT_EQ (test1.size(), 20);
  ASSERT_EQ (test2.size(), 28);
  Grid <int > test6(x, y);
  ASSERT_EQ (test6.size(), 560);
// testing equal row and column
  for (int i = 1; i < 100; i++) {
    for (int j = 1; j < 100; j++) {
      Grid <int> test(i , j);
      Grid <char> test2(i , j);
      Grid <double> test3(i , j);
      Grid <char> test4(i , j);
      ASSERT_EQ(test.size(), i*j);
      ASSERT_EQ(test.numrows(), i);
      ASSERT_EQ(test.numcols(i), j);
      ASSERT_EQ(test2.size(), i*j);
      ASSERT_EQ(test2.numrows(), i);
      ASSERT_EQ(test2.numcols(i), j);
      ASSERT_EQ(test3.size(), i*j);
      ASSERT_EQ(test3.numrows(), i);
      ASSERT_EQ(test3.numcols(i), j);
      ASSERT_EQ(test4.size(), i*j);
      ASSERT_EQ(test4.numrows(), i);
      ASSERT_EQ(test4.numcols(i), j);
    }
  }
  // testing  uneven column
  for (int i = 1; i < 100; i++) {
    for (int j = 1; j < 60; j++) {
      Grid <int> test(i , j);
      Grid <char> test2(i , j);
      Grid <double> test3(i , j);
      Grid <char> test4(i , j);
      ASSERT_EQ(test.size(), i*j);
      ASSERT_EQ(test.numrows(), i);
      ASSERT_EQ(test.numcols(i), j);
      ASSERT_EQ(test2.size(), i*j);
      ASSERT_EQ(test2.numrows(), i);
      ASSERT_EQ(test2.numcols(i), j);
      ASSERT_EQ(test3.size(), i*j);
      ASSERT_EQ(test3.numrows(), i);
      ASSERT_EQ(test3.numcols(i), j);
      ASSERT_EQ(test4.size(), i*j);
      ASSERT_EQ(test4.numrows(), i);
      ASSERT_EQ(test4.numcols(i), j);
    }
  }
  // equal row and column
  for (int i = 1; i < 100; i++) {
    for (int j = 1; j < 100; j++) {
      Grid <int> test(i , j);
      Grid <char> test2(i , j);
      Grid <double> test3(i , j);
      Grid <char> test4(i , j);
      ASSERT_EQ(test.size(), i*j);
      ASSERT_EQ(test.numrows(), i);
      ASSERT_EQ(test.numcols(i), j);
      ASSERT_EQ(test2.size(), i*j);
      ASSERT_EQ(test2.numrows(), i);
      ASSERT_EQ(test2.numcols(i), j);
      ASSERT_EQ(test3.size(), i*j);
      ASSERT_EQ(test3.numrows(), i);
      ASSERT_EQ(test3.numcols(i), j);
      ASSERT_EQ(test4.size(), i*j);
      ASSERT_EQ(test4.numrows(), i);
      ASSERT_EQ(test4.numcols(i), j);
    }
  }
  //varaible column
  for (int i = 1; i < 100; i++) {
    for (int j = 1; j < 50; j++) {
      Grid <int> test(i , j);
      Grid <char> test2(i , j);
      Grid <double> test3(i , j);
      Grid <char> test4(i , j);
      ASSERT_EQ(test.size(), i*j);
      ASSERT_EQ(test.numrows(), i);
      ASSERT_EQ(test.numcols(i), j);
      ASSERT_EQ(test2.size(), i*j);
      ASSERT_EQ(test2.numrows(), i);
      ASSERT_EQ(test2.numcols(i), j);
      ASSERT_EQ(test3.size(), i*j);
      ASSERT_EQ(test3.numrows(), i);
      ASSERT_EQ(test3.numcols(i), j);
      ASSERT_EQ(test4.size(), i*j);
      ASSERT_EQ(test4.numrows(), i);
      ASSERT_EQ(test4.numcols(i), j);
    }
  }
  for (int i = 1; i < 100; i++) {
    for (int j = 100; j >0; j--) {
      Grid <int> test(i , j);
      Grid <char> test2(i , j);
      Grid <double> test3(i , j);
      Grid <char> test4(i , j);
      ASSERT_EQ(test.size(), i*j);
      ASSERT_EQ(test.numrows(), i);
      ASSERT_EQ(test.numcols(i), j);
      ASSERT_EQ(test2.size(), i*j);
      ASSERT_EQ(test2.numrows(), i);
      ASSERT_EQ(test2.numcols(i), j);
      ASSERT_EQ(test3.size(), i*j);
      ASSERT_EQ(test3.numrows(), i);
      ASSERT_EQ(test3.numcols(i), j);
      ASSERT_EQ(test4.size(), i*j);
      ASSERT_EQ(test4.numrows(), i);
      ASSERT_EQ(test4.numcols(i), j);
    }
  }
  // setting uo the grid size
  {
    Grid <int> alpha(100, 100);
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        ASSERT_EQ(alpha(i, j), 0);
      }
    }
  }

  {
    Grid <int> alpha(100, 100);
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        alpha(i, j) = i*j;
        ASSERT_EQ(alpha(i, j), i*j);
      }
    }
  }
  {
    Grid <int> alpha(20, 20);
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
        alpha(i, j) = i*j;
        ASSERT_EQ(alpha(i, j), i*j);
      }
    }
    alpha._output();
  }
  {
    Grid <int> alpha(50, 10);
    for (int i = 0; i < 50; i++) {
      for (int j = 0; j < 10; j++) {
        alpha(i, j) = i*j;
        ASSERT_EQ(alpha(i, j), i*j);
      }
    }
    alpha._output();
  }
}

TEST(grid, copyAndequalTest) {
    Grid <int > g1(5,4);
    Grid <int> g2(g1);
    Grid < Grid <int>> g3;
    Grid < Grid <int>> g34(1,1);
    for(int i = 0; i < 10; i++) {
      int j = 1;
      Grid <Grid <int>> g(i, j);
      j++;
    }
    {
      for(int i = 0; i < 10; i++) {
        int j = 1;
        Grid <int>g(i, j);
        Grid <int>g2(g);
        ASSERT_EQ(g.size(), g2.size());
        j++;
      }
    }
    {
      for(int i = 0; i < 30; i++) {
        int j = 1;
        Grid <int>g(i, j);
        Grid <int>g2(g);
        ASSERT_EQ(g.size(), g2.size());
        ASSERT_EQ(g2.numrows(), i);
        ASSERT_EQ(g2.numcols(i), j);
        j++;
      }
    }
    {
      Grid <int> g2;
      Grid <int> g3;
      Grid <char> g4;
      Grid <string> g5;
      for (int i = 1; i < 100; i++) {
        int j = 1;
          Grid <int> test(i , j);
          g2 = test;
          ASSERT_EQ(g2.size(), i*j);
          ASSERT_EQ(g2.numrows(), i);
          ASSERT_EQ(g2.numcols(i), j);
          j++;
      }
      for (int i = 1; i < 150; i++) {
        int j = 1;
          Grid <int> test(i , j);
          g3 = test;
          ASSERT_EQ(g3.size(), i*j);
          ASSERT_EQ(g3.numrows(), i);
          ASSERT_EQ(g3.numcols(i), j);
          j++;
      }
      for (int i = 1; i < 30; i++) {
        int j = 1;
          Grid <char> test(i , j);
          g4 = test;
          ASSERT_EQ(g4.size(), i*j);
          ASSERT_EQ(g4.numrows(), i);
          ASSERT_EQ(g4.numcols(i), j);
          j++;
      }
      for (int i = 1; i < 30; i++) {
        int j = 1;
          Grid <string> test(i , j);
          g5 = test;
          ASSERT_EQ(g5.size(), i*j);
          ASSERT_EQ(g5.numrows(), i);
          ASSERT_EQ(g5.numcols(i), j);
          j++;
      }
    }
}
//// Provided Test: sample maze from handout, make lots more yourself!
TEST(maze, basic) {
   vector<string> textMaze;

   textMaze.push_back("* *-W *");
   textMaze.push_back("| |   |");
   textMaze.push_back("*-* * *");
   textMaze.push_back("  | | |");
   textMaze.push_back("S *-*-*");
   textMaze.push_back("|   | |");
   textMaze.push_back("*-*-* P");

   Maze m(textMaze);

   MazeCell* start = m.getStart(2, 2);

   /* These paths are the ones in the handout. They all work. */
   EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
   EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
   EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

   /* These paths don't work, since they don't pick up all items. */
   EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
   EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
   EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

   /* These paths don't work, since they aren't legal paths. */
   EXPECT_FALSE(isPathToFreedom(start, "WW"));
   EXPECT_FALSE(isPathToFreedom(start, "NN"));
   EXPECT_FALSE(isPathToFreedom(start, "EE"));
   EXPECT_FALSE(isPathToFreedom(start, "SS"));
}
//
//// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
   vector<string> textMaze;

   textMaze.push_back("* S *");
   textMaze.push_back("     ");
   textMaze.push_back("W * P");
   textMaze.push_back( "     ");
   textMaze.push_back( "* * *");

   Maze m(textMaze);

   MazeCell* start = m.getStart(1, 1);

   EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
   EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
   EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
   EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}
//
//// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
   vector<string> textMaze;

   textMaze.push_back("P-S-W");

   Maze m(textMaze);
   MazeCell* start = m.getStart(0, 0);

   EXPECT_TRUE(isPathToFreedom(start, "EE"));
   start = m.getStart(0, 1);
   EXPECT_TRUE(isPathToFreedom(start, "WEE"));
   start = m.getStart(0, 2);
   EXPECT_TRUE(isPathToFreedom(start, "WW"));

}
//
//// Provided Test: Reports errors if given illegal characters.
TEST(maze, invalidChar) {
   vector<string> textMaze;

   textMaze.push_back("* *-W *");
   textMaze.push_back("| |   |");
   textMaze.push_back("*-* * *");
   textMaze.push_back("  | | |");
   textMaze.push_back("S *-*-*");
   textMaze.push_back("|   | |");
   textMaze.push_back("*-*-* P");

   Maze m(textMaze);
   MazeCell* start = m.getStart(0, 0);

   /* These paths contain characters that aren't even close to permissible. */
   EXPECT_FALSE(isPathToFreedom(start, "Q"));
   EXPECT_FALSE(isPathToFreedom(start, "X"));
   EXPECT_FALSE(isPathToFreedom(start, "!"));
   EXPECT_FALSE(isPathToFreedom(start, "?"));

   EXPECT_FALSE(isPathToFreedom(start, "n"));
   EXPECT_FALSE(isPathToFreedom(start, "s"));
   EXPECT_FALSE(isPathToFreedom(start, "e"));
   EXPECT_FALSE(isPathToFreedom(start, "w"));

   ///* These are tricky - they're legal paths that happen to have an unexpected
   // * character at the end.
   start = m.getStart(2, 2);
   EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
   EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
   EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));

}
//
//// Provided Test: This tests your personalized regular maze to see if you were
//// able to escape.
TEST(maze, escapeRegularMaze) {
   Maze m(4, 4);
   MazeCell* start = m.mazeFor(kYourName);
   EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}
//
//// Provided Test: This tests your personalized twisty maze to see if you were
//// able to escape.
TEST(maze, escapeTwistyMaze) {
   Maze m(4, 4);
   MazeCell* start = m.twistyMazeFor(kYourName);
   EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}
