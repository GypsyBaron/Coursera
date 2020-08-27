#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, temp, height = 0;
	queue<int> q;

	cin >> n;

	vector< vector<int> > vect(n);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == -1) {
			q.push(i);
		} else {
			vect[temp].push_back(i);
		}
	}

	while (!q.empty()) {

		int size = q.size();
		height++;

		for (int i = 0; i < size; i++) {

			for (int j = 0; j < vect[q.front()].size(); j++) {
				q.push(vect[q.front()][j]);
			}
			q.pop();
		}
	}

	cout << height;
	return 0;
}