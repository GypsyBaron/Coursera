#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector< array<int, 3> > vect;

void inOrderTraversal(array<int, 3> arr) {
	if (arr[1] != -1) {
		inOrderTraversal(vect[arr[1]]);
	}

	cout << arr[0] << " ";

	if (arr[2] != -1) {
		inOrderTraversal(vect[arr[2]]);
	}
}

void preOrderTraversal(array<int, 3> arr) {
	
	cout << arr[0] << " ";

	if (arr[1] != -1) {
		preOrderTraversal(vect[arr[1]]);
	}

	if (arr[2] != -1) {
		preOrderTraversal(vect[arr[2]]);
	}
}

void postOrderTraversal(array<int, 3> arr) {
	if (arr[1] != -1) {
		postOrderTraversal(vect[arr[1]]);
	}

	if (arr[2] != -1) {
		postOrderTraversal(vect[arr[2]]);
	}

	cout << arr[0] << " ";

}

int main() {
	ios::sync_with_stdio(false);
	int n, key, leftChild, rightChild;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> key;
		cin >> leftChild;
		cin >> rightChild;
		vect.push_back({key, leftChild, rightChild});
	}

	inOrderTraversal(vect[0]);
	cout << "\n";
	preOrderTraversal(vect[0]);
	cout << "\n";
	postOrderTraversal(vect[0]);
	return 0;
}