#include <iostream>
#include <vector>
#include <limits>
#include <math.h>

using namespace std;

vector< pair<int, int>> graph[1001];

void BellmanFord(int v, int start) {
	int distances[v + 1];
	int compareDistances[v + 1];
	int compareDistances2[v + 1];

	for (int i = 1; i <= v; i++) {
		distances[i] = numeric_limits<int>::max() / 10000;
	}

	distances[start] = 0;
	for (int k = 1; k <= v + 1; k++) {
		//cout << "K - " << k << endl;
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
		
		if (k == v - 1) {
			//cout << "Suveike copy paste" << endl;
			for (int p = 1; p <= v; p++) {
				compareDistances[p] = distances[p];
			}
		}

		if (k == v) {
			//cout << "Suveike copy paste" << endl;
			for (int p = 1; p <= v; p++) {
				compareDistances2[p] = distances[p];
			}
		}


	}
	
	for (int i = 1; i <= v; i++) {
		if (compareDistances[i] == compareDistances2[i] && compareDistances[i] == distances[i] && compareDistances[i] == 214748) {
			cout << "*" << endl;
		} else if (compareDistances[i] == compareDistances2[i] && compareDistances[i] == distances[i] && compareDistances[i] != 214748) {
			cout << distances[i] << endl;
		} else {
			cout << "-" << endl;
		}
	}
}

int main() {
	int v, e, temp1, temp2, weight;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2 >> weight;
		graph[temp1].push_back(make_pair(temp2, weight));
	}

	cin >> temp1;

	BellmanFord(v, temp1);
}