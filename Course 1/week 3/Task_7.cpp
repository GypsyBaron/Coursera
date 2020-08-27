#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string temp1, string temp2) {
	//Creating two string to compare them by changing their position
	string first, second;
	first = temp1 + temp2;
	second = temp2 + temp1;

	for (int i = 0; i < first.length(); i++) {
		if (first[i] != second[i]) {
			return first[i] > second[i];
		}
	}

	return false;
}

int main() {
	int n;
	string temp;
	cin >> n;
	vector<string> vect;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		vect.push_back(temp);
	}

	sort(vect.begin(), vect.end(), compare);
	
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i];
	}
}