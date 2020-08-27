#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

int main() {
	long long  minimum, maximum, a, b, c, d;
	string expression;
	vector<int> digits;
	vector<char> symbols;

	cin >> expression;

	long long M[expression.length() / 2 + 1][expression.length() / 2 + 1];
	long long m[expression.length() / 2 + 1][expression.length() / 2 + 1];

	for (int i = 0; i < expression.length(); i+= 2) {
		digits.push_back(expression[i] - '0');
		if (expression.length() != i - 1) {
			symbols.push_back(expression[i + 1]);
		}
	}

	for (int i = 0; i < digits.size(); i++) {
		for (int j = 0; j < digits.size(); j++) {
			if (i == j) {
				M[i][j] = digits[i];
				m[i][j] = digits[i];
			} else {
				M[i][j] = 0;
				m[i][j] = 0;
			}
		}
	}

	for (int s = 1; s < digits.size(); s++) {
		for (int i = 0; i < digits.size() - s; i++) {
			int j = i + s;
			
			minimum = numeric_limits<int>::max();
			maximum = numeric_limits<int>::min();
			//cout << "(" << i << "," << j << ")";

			for (int k = i; k < j; k++) {
				//cout << "I - " << i << " J - " << j << " K - " << k << endl;
				if (symbols[k] == '+') {
					//cout << "Daugyba" << endl;
					a = M[i][k] + M[k + 1][j];
					b = M[i][k] + m[k + 1][j];
					c = m[i][k] + M[k + 1][j];
					d = m[i][k] + m[k + 1][j];
				} else if (symbols[k] == '*') {
					//cout << "Sudetis" << endl;
					a = M[i][k] * M[k + 1][j];
					b = M[i][k] * m[k + 1][j];
					c = m[i][k] * M[k + 1][j];
					d = m[i][k] * m[k + 1][j];
				} else {
					//cout << "Atimtis" << endl;
					a = M[i][k] - M[k + 1][j];
					b = M[i][k] - m[k + 1][j];
					c = m[i][k] - M[k + 1][j];
					d = m[i][k] - m[k + 1][j];
				}

				minimum = min(minimum, min(a, min(b, min(c, d))));
				maximum = max(maximum, max(a, max(b, max(c, d))));
			}
			//cout << endl;
			M[i][j] = maximum;
			m[i][j] = minimum;
			//cout << M[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;

	// for (int i = 0; i < digits.size(); i++) {
	// 	for (int j = 0; j < digits.size(); j++) {
	// 		cout << M[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << M[0][digits.size() - 1];
}