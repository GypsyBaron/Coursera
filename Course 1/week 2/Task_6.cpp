#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


int fibonacci_correct(long long n) {
	int sumOfFirst60Numbers = 0;
	int sumOfRemainder = 0;
	long long result;

	vector<int> vect;
	vect.push_back(0);
	vect.push_back(1);

	for (int i = 2; i < 60; i++) {
		vect.push_back((vect[i - 1] + vect[i -2]) % 10);
	}

	long long k = n / 60;
	int remainder = n % 60;

	if (k > 0) {
		for (int i = 0; i < 60; i++) {
			sumOfFirst60Numbers+= vect[i];
		}

		sumOfFirst60Numbers %= 10;
	} 

	for (int i = 0; i <= remainder; i++) {
		sumOfRemainder+= vect[i];
	}

	sumOfRemainder %= 10;
	result = ((sumOfFirst60Numbers * k) + sumOfRemainder) % 10; 
	
	return result;
} 

int main() {
	int result;
	long long n;
	cin >> n;
	result = fibonacci_correct(n);
	cout << result << endl;
    return 0;
}
