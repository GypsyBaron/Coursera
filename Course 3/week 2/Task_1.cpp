#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool hasCycle = false;
int color[1001];

// Color - 0 Not visited
// Color - 1 Visited, but has childer which are not visited
// Color - 2 Fully visited

void DFS(int v) {
	color[v] = 1;
	for (int i = 0; i < graph[v].size(); i++) {
		if (color[graph[v][i]] != 2) {
			if (color[graph[v][i]] == 0) {
				DFS(graph[v][i]);
			} else {
				hasCycle = true;
			}
		}
	}
	color[v] = 2;
}

int main() {
	int v, e, temp1, temp2;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		color[i] = 0; 
	}

	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
	}

	for (int i = 1; i <= v; i++) {
		if (color[i] == 0) {
			DFS(i);
		}
	}

	if (hasCycle) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}