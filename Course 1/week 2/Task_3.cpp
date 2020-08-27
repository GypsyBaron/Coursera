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

int main() {
	long long a, b, result;
	cin >> a >> b;
	result = gcd(a, b);
	cout << result << endl;
    return 0;
}
