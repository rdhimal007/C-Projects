#include <gtest/gtest.h>
#include "mymap.h"
#include "myrandom.h"

TEST(mymap, default) {
  mymap<int, int> testMe;
  map<int, int> correct;
  testMe.put(2, 4);
  correct.emplace(pair<int, int>(2, 4));
  // check if key exists:
  EXPECT_EQ(true, testMe.contains(2));
  testMe[1];

  //    check the values:
  EXPECT_EQ(testMe.get(2), correct[2]);
  EXPECT_EQ(testMe[3], correct[4]);
  EXPECT_EQ(testMe[2], correct[2]);

  // another stress test
  mymap<int, int> testMe2;
  map<int, int> correct2;
  int Arr[1000];
  for (int i = 0; i < 1000; i++) {
    Arr[i] = i;
  }
  for (int i = 1000; i >= 0; i--) {
    testMe2.put(i, Arr[i]);
    correct2.emplace(pair<int, int>(i, Arr[i]));
  }
  cout << "Stress test" << endl;
  for (int i = 1000; i >= 0; i--) {
    EXPECT_EQ(testMe2[i], correct2[i]);
    EXPECT_EQ(testMe2[i], correct2[i]);
  }
}

TEST(casts, dfaultTest2) {
  cout << "Pattern Handout Test" << endl;
  mymap<int, int> map2;
  int arr[] = {2, 1, 3};
  for (int i = 0; i < 3; i++) {
    map2.put(arr[i], arr[i]);
    //     EXPECT_EQ(map2[i], i);
  }
  EXPECT_EQ(map2.Size(), 3);

  for (int j = 0; j < 3; j++) {
    EXPECT_TRUE(map2.contains(arr[j]));
  }

  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(map2.get(arr[i]), arr[i]);

    EXPECT_EQ(map2.Size(), 3);
  }
  string sol = "key: 1 value: 1\nkey: 2 value: 2\nkey: 3 value: 3\n";

  EXPECT_EQ(sol, map2.toString());
}

TEST(tm, teck) {
  // from project pdf:
  mymap<int, int> test;
  map<int, int> correct;
  int seed = 1000000;
  for (int i = 0; i < 1000; i++) {
    // randomize key and val
    int k = randomInteger(0, seed);
    int v = randomInteger(0, seed);
    test.put(k, v);
    correct[k] = v;
  }
  cout << test.Size() << " " << correct.size() << endl;
  EXPECT_EQ(test.Size(), correct.size());
  //   after this point test
  //   test inserts and string

  //   try to make this test
  //   repetitive using loops
}

TEST(currr, ms3) {

  mymap<int, int> map;

  int arr[] = {2, 1, 3, 5 , 7};

  int order[] = {1, 2, 3, 5, 7};

  for (int i = 0; i < 5; i++) {

     map.put(arr[i], arr[i]);

   }

  int i = 0;

  for (auto key : map) {

    EXPECT_EQ(order[i++], key);

  }
  cout << "Map clear " << endl;
//   map.clear();
//   EXPECT_EQ(map.Size(), 0);
  cout << "mini test copy and equal" << endl;

//   mymap<int, int> mapCopy;

//   mapCopy = map;
//  EXPECT_EQ(mapCopy.Size(), 3);
  	EXPECT_EQ(map.Size(), 5);
  cout << " here" << endl;
  mymap<int, int> mapi = map;
//   mymap<int, int> maps;
//   maps = map;
//   cout << maps.Size() << endl;
//    EXPECT_EQ(mapi.Size(), 5);
}
TEST(tee, copytest) {

}
