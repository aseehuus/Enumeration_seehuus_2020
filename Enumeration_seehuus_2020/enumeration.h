/*Enumerating function
Alex Seehuus, 2020*/
#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include "factorization.h"
using namespace std;
using namespace NTL;


//a function used to enumerate all divisors given the prime factors
vector<ZZ> enumerate(Factorization factors, ZZ bound);

//print function
void print(vector<ZZ> to_print);

