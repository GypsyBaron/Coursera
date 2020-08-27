#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> vect;
	cin >> n;

	while (n > 0) {

		if (vect.size() + 1 > n) {
			vect[vect.size()-1] = n + vect[vect.size() - 1];
			break;
		}

		vect.push_back(vect.size() + 1);
		n-= vect[vect.size() - 1];
	}

	cout << vect.size() << endl;

	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
 }