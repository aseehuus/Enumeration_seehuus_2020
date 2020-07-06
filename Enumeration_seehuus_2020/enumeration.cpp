/* Enumerating divisors given prime factors
Summer 2020
Alex Seehuus */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//a function used to enumerate all divisors given the prime factors
//the way to use set_union is based on code by Ali Khatai
vector<long> enumerate(vector<long> prime_factors) {

	//return vector with results
	vector<long> divisors;

	//base case: if size of prime_factors is 1, the only prime factor is the number
	//so the divisors are 1 and the number
	if (prime_factors.size() == 1) {
		divisors.push_back(1);
		divisors.push_back(prime_factors.at(0));
		return divisors;
	}
	else {

		//create vector head, which is last element of prime_factors
		vector<long> head;
		head.push_back(prime_factors.back());

		//create vector tail, which is every element of prime_factors
		//EXCEPT the last

		//use .erase(.back()) instead of loop
		//in factorization, erase the last element or lower the power
		vector<long> tail;
		for (int i = 0; i < prime_factors.size() - 1; ++i) {
			tail.push_back(prime_factors.at(i));
		}

		//multiply tail with head to generate all divisors
		//create vector div that contains all divisors
		vector<long> div;
		for (int x = 0; x < tail.size(); ++x) {
			int y = head.front() * tail.at(x);

			div.push_back(y);
		}

		enumerate(tail);

		//sort the vectors
		sort(tail.begin(), tail.end());
		sort(div.begin(), div.end());

		//union the vectors to remove repeated divisors
		set_union(tail.begin(), tail.end(), div.begin(), div.end(), divisors.begin());

		return divisors;

	}


}

//print function
void print(vector<long> to_print) {
	for (int i = 0; i < to_print.size(); ++i) {
		cout << to_print.at(i) << " ";
	}
	cout << "\n"; 
}

//need multiple 

