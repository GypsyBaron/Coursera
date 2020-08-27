#include <iostream>

using namespace std;

int main() {
	int border = 0;
	string text, pattern, S;
	cin >> pattern >> text;

	S = pattern + '$' + text;
	//cout << S << endl;
	int arr[pattern.length() + text.length() + 1];

	arr[0] = 0;

	for (int i = 1; i < S.length(); i++) {

		while (border > 0 && S[i] != S[border]) {
			//cout << "I - " << i << endl;
			border = arr[border - 1];
		}

		if (S[i] == S[border]) {
			border++;
		} else {
			border = 0;
		}

		arr[i] = border;
	}

	// for (int i = 0; i < S.length(); i++) {
	// 	cout << arr[i] << endl;
	// }

	for (int i = 0; i < S.length(); i++) {
		if (arr[i] == pattern.length()) {
			cout << i - 2 * pattern.length() << " ";
		}
	}
	return 0;
}