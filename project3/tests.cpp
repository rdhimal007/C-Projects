#include <iostream>
#include "barchartanimate.h"
#include <cassert>

using namespace std;

// lines 8-98 tests the bar.h
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool tBarDefaultConstructor() {
	Bar b2;
    if (b2.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b2.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b2.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool tBarParamConstructor() {
	Bar b2("doll", 222, "USA");
    if (b2.getName() != "doll") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b2.getValue() != 222) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b2.getCategory() != "USA") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testOperators(int x, int y, int z, int h) {
	Bar b1("doll", x, "USA");
	Bar b2("doll", y, "USA");
	Bar b3("doll", z, "USA");
	// test between two bar of same value
	assert((b2 < b1) == false);
	assert((b2 <= b1) == true);
	assert((b2 > b1) == false);
	assert((b2 >= b1) == true);
	// similar bar test
	assert((b1 < b1) == false);
	assert((b1 <= b1) == true);
	assert((b1 > b1) == false);
	assert((b1 >= b1) == true);
	// similar bar test 2
	assert((b1 < b1) == false);
	assert((b1 <= b1) == true);
	assert((b1 > b1) == false);
	assert((b1 >= b1) == true);
	// test between different bar value
	assert((b3 < b1) == false);
	assert((b3 <= b1) == false);
	assert((b3 > b1) == true);
	assert((b3 >= b1) == true);
	cout << "All operators test: " << "Passed" << ", For test number: "<< h << endl;
	return true;
}


// lines 101 to  180 for BarChart.h functions
bool barchart1DefaultConstructor() {
	BarChart bc1;
	assert(bc1.getFrame() == "");
	assert(bc1.getSize() == 0);
	cout << "barchart1DefaultConstructor test: Passed" << endl;
	return true;
}
bool barchart2DefaultConstructor() {
	BarChart bc2;
	assert(bc2.getFrame() == "");
	assert(bc2.getSize() == 0);
	cout << "barchart2DefaultConstructor test: Passed" << endl;
	return true;
}

bool barchart1FunctionsTest() {
	BarChart bar1;
	BarChart bar2(5);
	BarChart bar3(10);

	bar2.setFrame("Test1");
	bar3.setFrame("Test2");

	bar2.addBar("Chicago", 1020, "US");
	bar2.addBar("Kathmandu", 1300, "Nepal");

	bar3.addBar("Dominque", 1306, "US");
	bar3.addBar("Toronto", 13001, "Canada");
	bar3.addBar("Kuito", 13001, "Japan");

	assert(bar3.addBar("Nine", 1306, "US") == true);
	assert(bar3.addBar("Dame", 13001, "Canada") == true);
	assert(bar3.addBar("thame", 13001, "Japan") == true);
	assert(bar2.addBar("hen", 1020, "US") == true);
	assert(bar2.addBar("cat", 1300, "Nepal") == true);

	assert(bar2.getFrame() == "Test1");
	assert(bar3.getFrame() == "Test2");

	assert(bar2.getSize() == 4);
	assert(bar3.getSize() == 6);
	// cout << bar2.getSize() << endl;

	assert(bar2[0].getName() == "Chicago");
	assert(bar2[1].getName() == "Kathmandu");

	assert(bar3[0].getName() == "Dominque");
	assert(bar3[1].getName() == "Toronto");
	assert(bar3[2].getName() == "Kuito");

	bar2.dump(cout);
	bar3.dump(cout);

// copying files
cout << endl;
	cout << "copied from bar2 to bar1" << endl;
	bar1 = bar2;
	bar2 = bar3;

	assert(bar1.getSize() == 4);
	assert(bar2.getSize() == 6);
	cout << endl;
	cout << "couting files of bar1 after copying" << endl;
	bar1.dump(cout);
	cout << endl;

	map<string, string> colorMap;
	colorMap["US"] = RED;
	colorMap["Nepal"] = BLUE;
	colorMap["Canada"] = GOLD;
	colorMap["Japan"] = RED;

	bar1.graph(cout, colorMap, 5);
	bar3.graph(cout, colorMap, 5);

	bar3.clear();
	bar2.clear();

	assert(bar3.getSize() == 0);
	assert(bar2.getSize() == 0);

	cout << "After using clear function no output" << endl;
	bar3.dump(cout);
	bar2.dump(cout);

	cout << endl;
	cout << "All barchart.h test: Passed" << endl;
	return true;
}

bool testAnimate() {
	string title, xlabel, source;

	BarChartAnimate alpha(title, xlabel, source);
	BarChartAnimate beta(title, xlabel, source);

	assert(alpha.getSize() == 0);
	assert(beta.getSize() == 0);
	cout << "testAnimate constructors: Passed" << endl;
	cout << endl;
	return true;
}

int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
  tBarDefaultConstructor();
  tBarParamConstructor();
	testOperators(222, 222, 342, 1);
	testOperators(300, 300, 400, 2);
	barchart1DefaultConstructor();
	barchart2DefaultConstructor();
	barchart1FunctionsTest();
	testAnimate();
  return 0;
}
