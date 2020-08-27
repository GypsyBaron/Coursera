#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> SortCharacters(string S) {
	int alphabetSize = 55;
	vector<int> order(S.length());
	vector<int> count(alphabetSize);

	for (int i = 0; i < alphabetSize; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < S.length(); i++) {
		//Char to int and increase by one
		count[S[i] - '$']++;
	}

	for (int i = 1; i < alphabetSize; i++) {
		count[i] = count[i] + count[i - 1];
	}

	for (int i = S.length() - 1; i >= 0; i--) {
		int c = S[i] - '$';
		count[c] = count[c] - 1;
		order[count[c]] = i;
	}

	return order;
}

vector<int> ComputeCharClasses(string S, vector<int> order) {
	vector<int> charClass(S.length());
	charClass[order[0]] = 0;

	for (int i = 1; i < S.length(); i++) {
		if (S[order[i]] != S[order[i - 1]]) {
			charClass[order[i]] = charClass[order[i - 1]] + 1;
		} else {
			charClass[order[i]] = charClass[order[i - 1]];
		}
	}

	return charClass;
}

vector<int> SortDoubled(string S, int L, vector<int> order, vector<int> charClass) {
	vector<int> count(S.length());
	vector<int> newOrder(S.length());

	for (int i = 0; i < count.size(); i++) {
		count[i] = 0;
	}

	for (int i  = 0; i < S.length(); i++) {
		count[charClass[i]] = count[charClass[i]] + 1;
	}

	for (int i = 1; i < S.length(); i++) {
		count[i] = count[i] + count[i - 1];
	}

	for (int i = S.length() - 1; i >= 0; i--) {
		int start = (order[i] - L + S.length()) % S.length();
		int cl = charClass[start];
		count[cl] = count[cl] - 1;
		newOrder[count[cl]] = start;
	}

	return newOrder;
}

vector<int> UpdateClasses(vector<int> newOrder, vector<int> charClass, int L) {
	int n = newOrder.size();
	vector<int> newClass(n);
	newClass[newOrder[0]] = 0;

	for (int i = 1; i < n; i++) {
		int cur = newOrder[i];
		int prev = newOrder[i - 1];
		int mid = (cur + L) % n;
		int midPrev = (prev + L) % n;

		if (charClass[cur] != charClass[prev] || charClass[mid] != charClass[midPrev]) {
			newClass[cur] = newClass[prev] + 1;
		}
		else {
			newClass[cur] = newClass[prev];
		}
	}

	return newClass;
}
int main() {

	int L = 1;
	string S;
	cin >> S;

	vector<int> order;
	vector<int> charClass;

	order = SortCharacters(S);
	charClass = ComputeCharClasses(S, order);

	while (L < S.length()) {
		order = SortDoubled(S, L, order, charClass);
		charClass = UpdateClasses(order, charClass, L);
		L = L * 2;
	}

	for (int i = 0; i < order.size(); i++) {
		cout << order[i] << " ";
	}
}