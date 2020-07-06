#include <iostream>
#include <algorithm>
#include "enumeration.h"

using namespace std;

int main() {

	vector<long> vect{ 3, 5, 7 };
	vector<long> vect1{ 3, 4, 5 };
	vector<long> vect2{ };
	vector<long> result{ 1 };

	result.resize(6);

	set_union(vect.begin(), vect.end(), vect1.begin(), vect1.end(), result.begin());

	print(result);

	//print(enumerate(vect));
	//print(enumerate(vect1));
	//print(enumerate(vect2));

}