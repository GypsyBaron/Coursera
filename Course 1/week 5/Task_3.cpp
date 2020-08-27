#include <iostream>
#include <string> 

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;

	int arr[a.length() + 1][b.length() + 1];

	for (int i = 0; i < b.length() + 1; i++) {
		arr[0][i] = i;
	}

	for (int i = 0; i < a.length() + 1; i++) {
		arr[i][0] = i;
	}

	for (int i = 1; i < a.length() + 1; i++) {
		for (int j = 1; j < b.length() + 1; j++) {
			if (b[j - 1] == a[i - 1]) {
				//arr[i][j] = min(min(arr[i][j-1], arr[i - 1][j]), arr[i - 1][j - 1]);
				arr[i][j] = arr[i - 1][j - 1];
			} else {
				arr[i][j] = min(min(arr[i][j-1], arr[i - 1][j]), arr[i - 1][j - 1]) + 1;
			}
		}
	}

	cout << arr[a.length()][b.length()];
}