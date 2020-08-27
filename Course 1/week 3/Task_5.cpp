#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

struct Pair {
	long long start;
	long long end;
};

using namespace std;

long long findMinimumRightPosition(vector<Pair> vect) {
	long long min = pow(10, 9) + 1;
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i].end < min) {
			min = vect[i].end;
		}
	}
	return min;
}

int main() {
	int n;
	long long temp1, temp2;
	vector<Pair> vect;
	vector<long long> result;
	cin >> n;
	long long arr[n];

	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		Pair temp = {temp1, temp2};
		vect.push_back(temp);
	}
	
	while (vect.size() > 0) {
		long long minimumRight = findMinimumRightPosition(vect);
		result.push_back(minimumRight);

		for (int i = 0; i < vect.size(); i++) {
			if (vect[i].start <= minimumRight && vect[i].end >= minimumRight) {
				vect.erase(vect.begin() + i);
				i--;
			}
		}
	}

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}