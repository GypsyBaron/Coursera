#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
bool color[100001];
queue<int> q;

bool BFS(int start) {
	int top;
	q.push(start);
	color[start] = true;

	while(!q.empty()) {
		top = q.front();
		q.pop();
		visited[top] = true;

		for (int i = 0; i < graph[top].size(); i++) {
			if (!visited[graph[top][i]]) {
				if (color[top]) {
					color[graph[top][i]] = false;
				} else {
					color[graph[top][i]] = true;
				}
				q.push(graph[top][i]);
			} else {
				if (color[top] == color[graph[top][i]]) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	int v, e, temp1, temp2;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		visited[i] = false;
		color[i] = false;
	}

	for (int i = 1; i <= e; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			if (!BFS(i)) {
				cout << 0;
				return 0;
			}
		}
	}

	cout << 1;

	return 0;
}