#include <iostream>
#include <vector>
#include <algorithm>

// a program to find all the prime numbers between 1 and 100
// using the sieve of Erathosthene

std::vector<int> generate_primes(int n);
int count_primes(const std::vector<int>& values);

int main() {
	while (std::cin) {
		std::cout << "Enter max prime: ";
		int max_prime;

		if (std::cin >> max_prime) {
			std::vector<int> primes = generate_primes(max_prime);

			for (auto x: primes) {
				std::cout << x << " ";
			}
			std::cout << "\n";
		}
	}

	return 0;
}	

std::vector<int> generate_primes(int n) {
	if (n < 2) {
		throw std::invalid_argument("n must be greater than 2");
	}

	std::vector<int> isPrime(n+1, true);

	// cross out known multiples
	isPrime[0] = isPrime[1] = isPrime[2] = false;

	for(int i = 2; i != isPrime.size(); ++i) {
		if (isPrime[i]) {
			// cross out multiple of i
			for (int j = i*2; j < isPrime.size(); j += i) {
				isPrime[j] = false;
			}
		}
	}

	// gather result
	int total = count_primes(isPrime);

	std::vector<int> res;
	res.reserve(total);

	for (int i = 2, e = isPrime.size(); i != e; ++i) {
		if (isPrime[i]) {
			res.push_back(i);
		}
	}

	return res; 
}

int count_primes(const std::vector<int>& values) {
	return std::count(values.begin(), values.end(), true);			
}
