#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

long long fibonacci_correct(long long n, long long m) {
	int counter = 2;

	vector<int> vect;
	vect.push_back(0);
	vect.push_back(1);

	if (n < 2) {
		return 1;
	} else {
		while (true) {
			vect.push_back((vect[counter - 1] + vect[counter - 2]) % m);
			if (vect[counter] == 1 && vect[counter - 1] == 0) {
				break;
			}
			counter++;
		}

		vect.resize(vect.size() - 2);

		return vect[n % vect.size()];
	}

	return 1;
} 
int main() {
	long long n, m, result;
	cin >> n >> m;
	result = fibonacci_correct(n, m);
	cout << result << endl;
    return 0;
}
