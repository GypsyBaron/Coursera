#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n, W, temp;
	vector<int> vect;

	cin >> W >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp <= W) {
			vect.push_back(temp);
		}
	}

	sort(vect.begin(), vect.end());

	int arr[vect.size() + 1][W + 1];

	for (int i = 0; i <= vect.size(); i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) {
				arr[i][j] = 0;
			} else if (j >= vect[i-1]) {
					arr[i][j] = max(vect[i-1] + arr[i-1][j-vect[i-1]], arr[i-1][j]);
			} else {
				arr[i][j] = arr[i - 1][j];
			}
		}
	}

	cout << arr[vect.size()][W] << endl;
}