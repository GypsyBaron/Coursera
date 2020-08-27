#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

int main() {
	int n, m, k;

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

	cin >> k;
	int arr3[k];

	for (int i = 0; i < k; i++) {
		cin >> arr3[i];
	}

	int arr[n + 1][m + 1][k + 1];

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1; j++) {
			for (int l = 0; l < k + 1; l++) {
				if (i == 0 || j == 0 || l == 0) {
					arr[i][j][l] = 0;
				} else if (arr1[i - 1] == arr2[j - 1] && arr1[i - 1] == arr3[l - 1]){
					arr[i][j][l] = arr[i - 1][j - 1][l - 1] + 1;
				} else {
					arr[i][j][l] = max(max(arr[i - 1][j][l], arr[i][j - 1][l]), arr[i][j][l - 1]);
				}
			}
		}
	}

	cout << arr[n][m][k];
}