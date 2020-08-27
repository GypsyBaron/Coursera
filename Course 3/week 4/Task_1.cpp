#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<pair<int, int>> graph[10001];

int minDistance(int v, int distances[], bool fullyVisited[]) {
	int minValue = numeric_limits<int>::max(), minIndex;

	for (int i = 1; i <= v; i++) {
		if (!fullyVisited[i] && distances[i] <= minValue) {
			minValue = distances[i];
			minIndex = i;
		}
	}

	return minIndex;
}

int Djikstra(int v, int start, int end) {
	int min;
	int distances[v + 1];
	bool fullyVisited[v + 1];

	for (int i = 0; i < v; i++) {
		distances[i + 1] = numeric_limits<int>::max();
		fullyVisited[i + 1] = false;
	}

	distances[start] = 0;

	//cout << "Pirmas - " << distances[1] << endl;

	for (int i = 1; i <= v; i++) {
		//cout << "I - " << i << endl;
		min = minDistance(v, distances, fullyVisited);
		//cout << "Min distance - " << min << endl;
		fullyVisited[min] = true;

		//cout << "Graph size - " << graph[min].size() << endl;
		for (int j = 0; j < graph[min].size(); j++) {
			//cout << "Einame link - " << graph[min][j].first << endl;
			if (!fullyVisited[graph[min][j].first] && distances[min] + graph[min][j].second < distances[graph[min][j].first]) {
				//cout << "Pakeiciame reiksme. Previous value - " << distances[graph[min][j].first] << endl;

				distances[graph[min][j].first] = distances[min] + graph[min][j].second;

				//cout << "Pakeista reiksme. Post value - " << distances[graph[min][j].first] << endl;

			}
		}
	}

	return distances[end];
}

int main() {
	int v, e, temp1, temp2, weight, answer;
	//cout << "Insert first" << endl;

	cin >> v >> e;

	//cout << "Insert seconds" << endl;

	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2 >> weight;
		graph[temp1].push_back(make_pair(temp2, weight));
	} 
	//cout << "Insert thirds" << endl;

	cin >> temp1 >> temp2;
	//cout << "Insert forth" << endl;

	answer = Djikstra(v, temp1, temp2);

	if (answer != numeric_limits<int>::max()) {
		cout << answer;
	} else {
		cout << -1;
	}

	
	return 0;
}