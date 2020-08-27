#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	int n;
	long long temp;
	long long answer = 0;
	vector<long long> a;
	vector<long long> b;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		cin >> temp;
		b.push_back(temp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		answer += a[i] * b[i];
	}

	cout << answer << endl;
}