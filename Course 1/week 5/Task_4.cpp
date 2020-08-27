#include <iostream>
#include <string> 

using namespace std;

int main() {
	int n, m;
	cin >> n;
	int arr1[n];

	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	cin >> m;
	int arr2[m];

	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	int arr[n + 1][m + 1];

	for (int i = 0; i < m + 1; i++) {
		arr[0][i] = 0;
	}

	for (int i = 0; i < n + 1; i++) {
		arr[i][0] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (arr1[i - 1] == arr2[j - 1]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			} else {
				arr[i][j] = max(arr[i][j-1], arr[i - 1][j]);
			}
		}
	}

	cout << arr[n][m];
}