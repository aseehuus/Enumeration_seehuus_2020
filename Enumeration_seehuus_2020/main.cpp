#include <iostream>
#include <algorithm>
#include <vector>
#include "enumeration.h"
#include "factorization.h"
#include "NTL/ZZ.h"

using namespace std;
using namespace NTL;


int main() {

	Factorization f1; vector<ZZ> p; vector<ZZ> pow;
	p.push_back(to_ZZ(2));
	p.push_back(to_ZZ(3));
	p.push_back(to_ZZ(5));

	pow.push_back(to_ZZ(2));
	pow.push_back(to_ZZ(1));
	pow.push_back(to_ZZ(1));


	f1 = Factorization(p, pow);

	ZZ b = conv<ZZ>(5);
	
	vector<ZZ> result = enumerate(f1, b);

	print(result);





}