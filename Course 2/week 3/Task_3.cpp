#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool areEqual(string p, string t, int position) {
	
	long long index = 0;

	for (int i = position; i < position + p.length(); i++) {
		//cout << p[index] << " " << t[i] << endl;
		if (p[index] != t[i]) {
			return false;
		}
		index++;
	}

	return true;
}
void rabinKarp(string p, string t, long long prime) {

	long long a = 1, pHash = 0, tHash = 0;

	for (int i = 0; i < p.length() - 1; i++) {
		a = (a * 256) % prime;
	}

	for (int i = 0; i < p.length(); i++) {
		pHash = (pHash * 256 + int(p[i])) % prime;
		tHash = (tHash * 256 + int(t[i])) % prime;  
	}

	for (int i = 0; i <= t.length() - p.length(); i++) {

		if (pHash == tHash) {
			if (areEqual(p, t, i)) {
				cout << i << " ";
			}
		}

		if (i < t.length() - p.length()) {
			tHash = (256*(tHash - t[i] * a) + t[p.length() + i]) % prime;

			if (tHash < 0) {
				tHash += prime;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	string t, p;
	long long prime = 101;
	vector<int> vect;
	cin >> p >> t;

	rabinKarp(p, t, prime);
}