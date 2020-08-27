#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
stack<int> s;

void DFS(int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			DFS(graph[v][i]);
		}
	}
	s.push(v);
}

int main() {
	int v, e, temp1, temp2;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		visited[i] = false; 
	}

	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
	}

	for (int i = 1; i <= v; i++) {
		if (visited[i] == 0) {
			DFS(i);
		}
	}

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}