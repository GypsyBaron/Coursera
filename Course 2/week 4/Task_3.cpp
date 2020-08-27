#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector< array<int, 3> > vect;
vector<int> answer;
bool leftBranchEqual = false;

void inOrderTraversal(array<int, 3> arr) {

	if (arr[1] != -1) {
		if (arr[0] == vect[arr[1]][0]) {
			leftBranchEqual = true;
		}
		inOrderTraversal(vect[arr[1]]);
	}

	answer.push_back(arr[0]);

	if (arr[2] != -1) {
		inOrderTraversal(vect[arr[2]]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, key, leftChild, rightChild;
	cin >> n;

	if (n == 0) {
		cout << "CORRECT";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> key;
		cin >> leftChild;
		cin >> rightChild;
		vect.push_back({key, leftChild, rightChild});
	}

	inOrderTraversal(vect[0]);
	if (leftBranchEqual) {
		cout << "INCORRECT";
		return 0;
	}
	
	for (int i = 0; i < answer.size() - 1; i++) {
		if (answer[i] > answer[i+1]) {
			cout << "INCORRECT";
			return 0;
		}
	}

	cout << "CORRECT";
	return 0;
}