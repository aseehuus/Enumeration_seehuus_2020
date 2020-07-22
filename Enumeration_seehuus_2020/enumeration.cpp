/* Enumerating divisors given prime factors
Summer 2020
Alex Seehuus */

#include <iostream>
#include <vector>
#include <algorithm>
#include "enumeration.h"
#include "factorization.h"
#include "NTL/ZZ.h"
using namespace std;
using namespace NTL;


//a function used to enumerate all divisors given the prime factors
//the way to use set_union is based on code by Ali Khatai
vector<ZZ> enumerate(Factorization factors, ZZ bound) {

	//return vector with results
	vector<ZZ> divisors;

	//de-reference to access elements of primes and powers
	vector<ZZ>* pr = factors.getPrimes();
	vector<ZZ>* pw = factors.getPowers();

	//base case: if size of powers is 1 and the number is 1, the only prime factor is the number
	//so the divisors are 1 and the number
	ZZ n = to_ZZ(1);
	if (pw->size() == n && pw->at(0) == n) {
		divisors.push_back(n);
		divisors.push_back((pr->at(0)));
		return divisors;
	}

	else {

		//create vector head, which will either be a new prime,
		//or the same prime as the previous step
		ZZ head = pr->back();

		//erase the last element or subtract 1 from the power 
		if (pw->back() > 1) {
			// subtract 1 from the power
			pw->back()--;
		}
		else {
			// otherwise remove the power and prime
			pw->pop_back();
			pr->pop_back();
		}


		//multiply tail with head to generate all divisors
		//create vector div that contains all divisors
		//create Factorization f with de-referenced primes and powers
		vector <ZZ> div;
		Factorization f(*pr, *pw);
		vector<ZZ> tail = enumerate(f, bound);
		for (long x = 0; x < tail.size(); ++x) {
			ZZ y = head * tail.at(x);
	
			if (y < bound) {
				div.push_back(y);
			}
			else {
				break;
			}
		} 

		//sort the vectors
		sort(tail.begin(), tail.end());
		sort(div.begin(), div.end());

		divisors.resize(div.size() + tail.size());

		//union the vectors to remove repeated divisors
		set_union(tail.begin(), tail.end(), div.begin(), div.end(), divisors.begin());

		Rzeros(divisors);

		Rbound(divisors, bound);

		return divisors;
		
	}

}

//print function
void print(vector<ZZ> to_print) {
	for (int i = 0; i < to_print.size(); ++i) {
		cout << to_print.at(i) << " ";
	}
	cout << "\n";
}


//function to remove leading and trailing zeroes from a vector
//code by Ali Khatai
void Rzeros(vector<ZZ>& vect) {
	auto it = vect.begin();
	ZZ y = to_ZZ(0);
	while (it != vect.end()) {
		if (*it == 0) {

			it = vect.erase(it);
		}
		else {
			it++;
		}

	}

}

//function to get divisors upto a bound
//code by Ali Khatai
void Rbound(vector<ZZ>& vect, ZZ bound) {
	auto it = vect.begin();
	ZZ  product = to_ZZ(1);
	while (it != vect.end()) {
		product = product * (*it);
		if (product >= bound) {
			it = vect.erase(it);
		}
		else {
			it++;
		}
	}
}