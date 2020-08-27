#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map<int, string> map;
	string command, name;
	int n, number;
	cin >> n;

	for (int i = 0; i < n; i++) {
		//cout << "I - " << i << endl;
		//cout << map.size() << endl;
		cin >> command;
		if (command == "add") {
			//cout << "Add" << endl;
			cin >> number;
			cin >> name;
			map.erase(number);
			map.insert( make_pair(number, name) );
		} else if (command == "del") {
			//cout << "Del" << endl;
			cin >> number;
			map.erase(number);
		} else {
			//cout << "Find" << endl;
			cin >> number;
			auto search = map.find(number);
			if (search != map.end()) {
				cout << search->second << endl;
			} else {
				cout << "not found"  << endl;
			}
		}
	}
	return 0;
}