#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

long long polyHash(string line, int n) {
	long long hash = 0, x = 263, p = 1000000007;

	for (int i = line.length() - 1; i >= 0; i--) {
		hash = (hash * x + line[i]) % p;
	}

	return hash % n;
}

int main() {
	int n, k, number;
	long long hash;
	string command, word;
	cin >> n >> k;
	vector<string> arr[n];

	for (int i = 0; i < k; i++) {
		cin >> command;
		
		if (command == "add") {
			//cout << "Add command " << endl; 
			cin >> word;
			hash = polyHash(word, n);
			if(find(arr[hash].begin(), arr[hash].end(), word) == arr[hash].end()) {
				arr[hash].push_back(word);
			}
		} else if (command == "check") {
			//cout << "Check command " << endl; 
			cin >> number;

			if (arr[number].empty()) {
				cout << endl;
			} else {
				for (int i = arr[number].size() - 1; i >= 0; i--) {
					cout << arr[number][i] << " ";
				}
				cout << endl;
			}
		} else if (command == "del") {
			//cout << "Del command " << endl; 
			cin >> word;
			hash = polyHash(word, n);
			arr[hash].erase(std::remove(arr[hash].begin(), arr[hash].end(), word), arr[hash].end());
		} else {
			//cout << "Find command " << endl; 			
			cin >> word;
			hash = polyHash(word, n);
			if(find(arr[hash].begin(), arr[hash].end(), word) != arr[hash].end()) {
				cout << "yes" << endl;
			} else {
				cout << "no" << endl;
			}
		}
	}
}