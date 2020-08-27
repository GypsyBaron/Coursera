#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int getIndex(pair<int, int> &a, vector<pair<int, int>> &position) {
	int ats;

	for (int i = 0; i < position.size(); i++) {
		if (a == position[i]) {
			return i;
		}
	}
	return 0;
}

int find(int parent[], int v) {
	if (parent[v] == v) {
		return v;
	}

	return find(parent, parent[v]);
}

double calculateDistance(pair<int, int> a, pair<int, int> b) {
	return sqrt(pow(abs(a.first - b.first), 2) + pow(abs(a.second - b.second), 2));
}

bool sortByWeight(tuple<double, pair<int, int>, pair<int, int>> a, tuple<double, pair<int, int>, pair<int, int>> b) {
	return get<0>(a) < get<0>(b);
}

void Kruskal(vector<tuple<double, pair<int, int>, pair<int, int>>> graph, vector<pair<int, int>> position, int n) {

	int parent[n];
	double distance = 0;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int count = 0, i = 0;
	int sourceIndex, destinationIndex, sourceParent, destinationParent;

	while(count + 1 != n) {
	
		sourceIndex = getIndex(get<1>(graph[i]), position);
		destinationIndex = getIndex(get<2>(graph[i]), position);

		sourceParent = find(parent, sourceIndex);
		destinationParent = find(parent, destinationIndex);

		if (sourceParent != destinationParent) {
			parent[sourceParent] = destinationParent;
			distance+= get<0>(graph[i]);
			count++;
		}

		i++;
	}

	cout << fixed << setprecision(9) << distance;
}

int main() {
	int n, temp1, temp2;
	double distance;
	cin >> n;

	vector<pair<int, int>> position;
	vector<tuple<double, pair<int, int>, pair<int, int>>> graph;

	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		position.push_back({temp1, temp2});
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			distance = calculateDistance(position[i], position[j]);
			graph.push_back(make_tuple(distance, position[i], position[j]));
		}
	}

	sort(graph.begin(), graph.end(), sortByWeight);

	Kruskal(graph, position, n);

	return 0;
 }