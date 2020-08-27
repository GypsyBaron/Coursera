#include <iostream>
#include <algorithm>

using namespace std;

int Find(int i, int parent[]) {
	while (i != parent[i]) {
		i = parent[i];
	}

	return i;
}

int Union(int i, int j, int rank[], int parent[], int max) {
	int i_id = Find(i, parent);
	int j_id = Find(j, parent);

	if (i_id == j_id) {
		return max;
	}

	int sizeI = rank[i_id];
	int sizeJ = rank[j_id];

	if (rank[i_id] > rank[j_id]) {
		parent[j_id] = i_id;
		rank[i_id] += sizeJ;
	} else {
		parent[i_id] = j_id;
		rank[j_id] += sizeI;
	}

	if (sizeI + sizeJ > max) {
		max = sizeI + sizeJ;
	}

	return max;
}

int main() {
	int n, m, max = 0;
	cin >> n >> m;

	int rank[n];
	int parent[n];

	for (int i = 0; i < n; i++) {
		parent[i] = i;
		cin >> rank[i];
	}

	max = *max_element(rank, rank + n);

	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		max = Union(temp1 - 1, temp2 - 1, rank, parent, max);
		cout << max << endl;
	}

	return 0;
}