#include <iostream>
#include <vector>

using namespace std;

vector <int> graph[1001];

bool visited[1001];

void DFS(int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			DFS(graph[v][i]);	
		}	
	}
}

int main() {
	int k, n, temp1, temp2;
	cin >> k >> n;

	for (int i = 1; i <= k; i++) {
		visited[i] = false;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	cin >> temp1 >> temp2;

	DFS(temp1);

	if (visited[temp2]) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}