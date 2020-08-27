#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	long long temp;
	vector<long long> vect;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		vect.push_back(temp);
	}

	int counter = 1;
	int majorityElement = vect[0];

	for (int i = 0; i < n; i++) {
		if (vect[i] == majorityElement) {
			counter++;
		} else {
			if (counter > 1) {
				counter--;
			} else {
				majorityElement = vect[i];
			}
		}
	}

	counter = 0;
	for (int i = 0; i < n; i++) {
		if (majorityElement == vect[i]) {
			counter++;
		}
 	}

	if (counter > n / 2) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	
	return 0;
}