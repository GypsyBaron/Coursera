#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[100001];
int distances[100001];
queue<int> q;

int BFS(int start, int end) {
	int top;
	q.push(start);
	distances[start] = 0;

	while(!q.empty()) {
		top = q.front();
		q.pop();

		for (int i = 0; i < graph[top].size(); i++) {
			if (distances[graph[top][i]] == -1) {
				q.push(graph[top][i]);
				distances[graph[top][i]] = distances[top] + 1;
			}
		}
	}

	return distances[end];
}

int main() {
	int v, e, temp1, temp2;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		distances[i] = -1;
	}

	for (int i = 1; i <= e; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	cin >> temp1 >> temp2;

	cout << BFS(temp1, temp2);

	return 0;
}