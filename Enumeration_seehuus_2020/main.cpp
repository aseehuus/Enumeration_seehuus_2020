#include <iostream>
#include <algorithm>
#include <vector>
#include "enumeration.h"
#include "factorization.h"
#include "NTL/ZZ.h"

using namespace std;
using namespace NTL;


int main() {

	Factorization f1; 
	vector<ZZ> p, pow;
	p.push_back(to_ZZ(3));
	p.push_back(to_ZZ(5));
	p.push_back(to_ZZ(7));
	
	pow.push_back(to_ZZ(1));
	pow.push_back(to_ZZ(1));
	pow.push_back(to_ZZ(1));

	f1 = Factorization(p, pow);

	ZZ b = conv<ZZ>(999999999);
	
	print(enumerate(f1, b));






}