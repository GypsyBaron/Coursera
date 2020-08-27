#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

long long calculateLastFibonacciDigit(int n) {
	vector<int> vect;
	vect.push_back(0);
	vect.push_back(1);

	for (int i = 2; i <= n; i++) {
		vect.push_back(vect[i-1] + vect[i-2]);
		if (vect[i] >= 10) {
			vect[i] %= 10;
		}
	}

	return (long long)vect[n];
}

int main() {
	int n;
	long long result;
	cin >> n;
	result = calculateLastFibonacciDigit(n);
	cout << result << endl;
    return 0;
}
