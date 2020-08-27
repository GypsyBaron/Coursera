#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	vector< pair<char, int> > vect;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			vect.push_back( make_pair(str[i], i) );
		} else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (vect.empty()) {
				cout << i + 1 << endl;
				return 0;
			} else if (str[i] == ')' && vect.back().first == '(') {
				vect.pop_back();
			} else if (str[i] == ']' && vect.back().first == '[') {
				vect.pop_back();
			} else if (str[i] == '}' && vect.back().first == '{') {
				vect.pop_back();
			} else {
				cout << i + 1 << endl;
				return 0;
			}
		}
	}

	if (!vect.empty()) {
		cout << vect.front().second + 1 << endl;
	} else {
		cout << "Success" << endl;
	}

	return 0;
}