#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

long long gcd(int a, int b) {
	long long temp;

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}

int main() {
	long long a, b, result;
	cin >> a >> b;
	result = lcm(a, b);
	cout << result << endl;
    return 0;
}
