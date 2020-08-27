#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n;
	cin >> n;

	long long lastDigitValues[60];
	long long sumFibonacci[90];

	long long k = n % 60;

	lastDigitValues[0] = 0;
	lastDigitValues[1] = 1;
	sumFibonacci[0] = 0;
	sumFibonacci[1] = 1;

	long long sum = 1;

	if (k < 2) {
		cout << sumFibonacci[k] << endl;
	} else {
		for (int i = 2; i <= k; i++) {
			lastDigitValues[i] = (lastDigitValues[i-1] + lastDigitValues[i-2]) % 10;
			sumFibonacci[i] = (lastDigitValues[i] * lastDigitValues[i]) % 10;
			sum += sumFibonacci[i];
		}

		cout << sum % 10 << endl;
	}

	return 0;
}