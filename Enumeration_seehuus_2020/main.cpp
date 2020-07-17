#include <iostream>
#include <algorithm>
#include <vector>
#include "enumeration.h"
#include "factorization.h"
#include "NTL/ZZ.h"

using namespace std;
using namespace NTL;

vector<ZZ> enumerate(Factorization factors);

void print(vector<ZZ> to_print);

int main() {

	Factorization f1; vector<ZZ> p; vector<ZZ> pow;
	p.push_back(to_ZZ(3));
	pow.push_back(to_ZZ(3));
	f1 = Factorization(p, pow);
	
	vector<ZZ> result = enumerate(f1);

	print(result);





}