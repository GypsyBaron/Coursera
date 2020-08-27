#include <iostream>
#include <vector>

using namespace std;

bool visited[10001];
vector<pair<int, char>> graph[10001];

void DFS(int v) {
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		cout << v << "->" << graph[v][i].first << ":" << graph[v][i].second << endl;
		DFS(graph[v][i].first);
	}
}

int main() {
	int n, root, counter = 1;
	string pattern;
	char currentSymbol;
	bool wasFound;

	cin >> n;

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		cin >> pattern;
		root = 0;

		for (int j = 0; j < pattern.length(); j++) {
			currentSymbol = pattern[j];
			wasFound = false;
			for (int k = 0; k < graph[root].size(); k++) {
				if (graph[root][k].second == currentSymbol) {
					wasFound = true;
					root = graph[root][k].first;
					break;
				}
			}

			if (!wasFound) {
				graph[root].push_back(make_pair(counter, currentSymbol));
				root = counter;
				counter++;
			}
		}
	}

	DFS(0);
}