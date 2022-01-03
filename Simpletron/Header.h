#pragma once

#include <iostream> // cout, endl
#include <iomanip> // setfill, setw
#include <string>
#include <cmath>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::pow;

/*
sets the showpos format flag for the str stream
when showpos format flag is set, (+) sign precedes every non-negative 
numerical value inserted into the stream
*/
using std::showpos; // shows (+) signs
using std::noshowpos; // disable display of (+) signs
using std::setfill;
using std::setw;
using std::internal;
/*
for numbers w/ < 4 digits:
* format numbers w/ leading zeros between the sign and the value
* by using following statement before outputting the value:
	cout << setfill('0') << internal;
* stream manipulator "internal" indicates that fill characters should appear
* between the sign and the numeric value
* field width of fivve characters but does not have four digits (one position reserved for sign)
*/

using std::fstream;