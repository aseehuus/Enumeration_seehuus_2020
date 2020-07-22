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

//function to remove leadind and trailing zeroes from a vector
void Rzeros(vector<ZZ>& vect);

//function to get divisors upto a bound
void Rbound(vector<ZZ>& vect, ZZ bound);

