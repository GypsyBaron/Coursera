#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector< pair<int, int>> graph[1001];

bool BellmanFord(int v) {
	int distances[v + 1];
	for (int i = 1; i <= v; i++) {
		distances[i] = numeric_limits<int>::max() / 10000;
	}

	distances[1] = 0;
	for (int k = 1; k < v; k++) {
		for (int i = 1; i <= v; i++) {
		//cout << "I - " << i << " Grafo dydis - " << graph[i].size() << endl;
			for (int j = 0; j < graph[i].size(); j++) {
		//cout << "Left: " << distances[i] + graph[i][j].second << " .Right: " << distances[graph[i][j].first] << endl;

				if (distances[i] + graph[i][j].second < distances[graph[i][j].first]) {
					//cout << "If is working" << endl;
					distances[graph[i][j].first] = distances[i] + graph[i][j].second;
				}
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			if (distances[i] + graph[i][j].second < distances[graph[i][j].first]) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	int v, e, temp1, temp2, weight;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2 >> weight;
		graph[temp1].push_back(make_pair(temp2, weight));
	}

	if (BellmanFord(v)) {
		cout << 1;
	} else {
		cout << 0;
	}
}