#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getRank(char a) {

	switch(a) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}

	return 4;
}

int getIndex(int rank[], pair<char, int> a) {
	switch(a.first) {
		case 'A':  {
			return a.second + 1;
		} 
		case 'C':  {
			return rank[0] + a.second + 1;
		}
		case 'G':  {
			return rank[0] + rank[1] + a.second + 1;
		} 
		case 'T':  {
			return rank[0] + rank[1] + rank[2] +a.second + 1;
		} 
	}

	return 0;
}

int main() {
	int charRank, row = 0;
	int rank[5] = {0, 0, 0, 0, 0};
	string transform, answer;

	cin >> transform;

	vector<pair<char, int>> F(transform.length());
	vector<pair<char, int>> L(transform.length());

	for (int i = 0; i < transform.length(); i++) {
		charRank = getRank(transform[i]);
		L[i] = make_pair(transform[i], rank[charRank]);
		rank[charRank]++;
	}

	F = L;
	sort(F.begin(), F.end());

	for (int i = 0; i < transform.length() - 1; i++) {
		answer.push_back(L[row].first);
		row = getIndex(rank, L[row]);
	}

	reverse(answer.begin(), answer.end());
	answer.push_back('$');
	cout <<  answer << endl;

 	return 0;
}