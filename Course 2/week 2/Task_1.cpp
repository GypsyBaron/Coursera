#include <iostream>
#include <vector>

using namespace std;

vector< pair <int, int> > pairs;

void SiftDown(int i, vector<int> &vect) {
	int maxIndex = i, l, r, counter = 0;
	l = i * 2 + 1;

	if (l < vect.size() && vect[l] < vect[maxIndex]) {
		maxIndex = l;
	}

	r = i * 2 + 2;

	if (r < vect.size() && vect[r] < vect[maxIndex]) {
		maxIndex = r;
	}

	if (i != maxIndex) {
		pairs.push_back( make_pair(i, maxIndex) );
		swap(vect[i], vect[maxIndex]);
		SiftDown(maxIndex, vect);
	}
}

void BuildHeap(vector<int> &vect) {
	int size = vect.size();

	for (int i = vect.size() / 2; i >= 0; i--) {
		SiftDown(i, vect);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> vect(n);
	
	for (int i = 0; i < n; i++) {
		cin >> vect[i];
	}

	BuildHeap(vect);

	cout << pairs.size() << endl;
	for (int i = 0; i < pairs.size(); i++) {
		cout << pairs[i].first << " " << pairs[i].second << endl;
	}

	return 0;
}