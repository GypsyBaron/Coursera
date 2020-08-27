#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> A, int low, int high, int key) {
	if (high < low) {
		return -1;
	}

	int mid = ((high - low) / 2);
	if (key == A[mid]) {
		return mid;
	} else if (key < A[mid]) {
		return BinarySearch(A, low, mid - 1, key);
	} else {
		return BinarySearch(A, mid + 1, high, key);
	}
}

int IterativeBinarySearch(vector<int> A, int key) {
	int mid, low = 0, high = A.size() - 1;

	while(low <= high) {
		mid = (low + high) / 2;
		if (A[mid] > key) {
			high = mid - 1;
		} else if (A[mid] < key) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}

int main() {
	int n, k, temp;
	vector<int> sortedVector;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sortedVector.push_back(temp);
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		//cout << BinarySearch(sortedVector, 0, k - 1, temp) << " ";
		cout << IterativeBinarySearch(sortedVector, temp) << " ";
	}

}