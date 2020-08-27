#include <iostream>

using namespace std;

int main() {
	int n, result = 0;
	cin >> n;

	result += n / 10;
	n %= 10;
	result += n / 5;
	n %= 5;
	result += n / 1;

	cout << result << endl;
}