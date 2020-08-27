#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void calculateMinOperations(int n) {
	int a, b, c;
	vector<int> vect;
	vector<int> operations;
	vector<int> result;

	vect.push_back(0);
	operations.push_back(0);

	for (int i = 2; i <= n; i++) {
		int a = numeric_limits<int>::max();
		int b = numeric_limits<int>::max();
		int c = numeric_limits<int>::max();

		if (i % 3 == 0) {
			a = vect[(i / 3) - 1] + 1;
		}

		if (i % 2 == 0) {
			b = vect[(i / 2) - 1] + 1;
		}

		c = vect[i-2] + 1;

		if (a <= b && a <= c) {
			vect.push_back(a);
			operations.push_back(3);
		} else if (b <= a && b <= c) {
			vect.push_back(b);
			operations.push_back(2);
		} else {
			vect.push_back(c);
			operations.push_back(1);
		}
	}
	int size = vect[n-1];

	for (int i = size; i >= 0; i--) {
		if (operations[n-1] == 3) {
			result.push_back(n);
			n /= 3;
		} else if (operations[n-1] == 2) {
			result.push_back(n);
			n /= 2;
		} else {
			result.push_back(n);
			n--;
		}
	}

	cout << size << endl;

	for (int i = result.size() - 1; i >=  0; i--) {
		cout << result[i] << " ";
	}

}

int main() {
	int n;
	cin >> n;

	calculateMinOperations(n);

	return 0;
}
