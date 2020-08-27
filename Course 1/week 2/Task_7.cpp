#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


int fibonacci_correct(long long n, long long m) {
	long long sumOfRemainder = 0;

	vector<int> vect;
	vect.push_back(0);
	vect.push_back(1);

	for (int i = 2; i < 60; i++) {
		vect.push_back((vect[i - 1] + vect[i -2]) % 10);
	}

	int mRemainder, nRemainder;
	mRemainder = m % 60;
	nRemainder = n % 60;

	//cout << "Liekanos. " << nRemainder << " " << mRemainder << endl;
	if (n / 60 == m / 60) {
		for (int i = n % 60; i <= mRemainder; i++) {
			sumOfRemainder+= vect[i];
		}
	} else {
		//cout << "mRemainder - " << mRemainder << endl;
		for (int i = 0; i <= mRemainder; i++) {
			//cout << vect[i];
			sumOfRemainder+= vect[i];
		}

		//cout << "Suma pirmu skaiciu - " << sumOfRemainder << endl;

		// << "nRemainder - " << nRemainder << endl;
		for (int i = nRemainder; i <= 60; i++) {
			//cout << vect[i];
			sumOfRemainder+= vect[i];
		}

		//cout << "Suma paskutiniu skaiciu - " << sumOfRemainder << endl;
	}
	return sumOfRemainder % 10;
} 

int main() {
	int result;
	long long n, m;
	cin >> n >> m;
	result = fibonacci_correct(n, m);
	cout << result << endl;
    return 0;
}
