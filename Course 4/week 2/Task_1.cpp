#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	char lastSymbol;

	cin >> s;
	vector<string> vect(s.length());

	for (int i = 0; i < s.length(); i++) {
		lastSymbol = s[s.length() - 1];
		s.pop_back();
		s = lastSymbol + s;
		vect[i] = s;
	}

	sort(vect.begin(), vect.end());

	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i][s.length() - 1];
	}
	return 0;
}