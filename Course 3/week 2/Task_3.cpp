#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[100001];
bool visited[100001];
vector<int> reverseGraph[100001];
bool reverseVisited[100001];
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

void reverseDFS(int v) {
	reverseVisited[v] = true;
	for (int i = 0; i < reverseGraph[v].size(); i++) {
		if (!reverseVisited[reverseGraph[v][i]]) {;
			reverseDFS(reverseGraph[v][i]);
		}
	}
}

int main() {
	int v, e, temp1, temp2, counter = 0;
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		visited[i] = false; 
		reverseVisited[i] = false;
	}

	for (int i = 0; i < e; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		reverseGraph[temp2].push_back(temp1);
	}

	for (int i = 1; i <= v; i++) {
		if (visited[i] == 0) {
			DFS(i);
		}
	}

	while(!s.empty()) {
		if (!reverseVisited[s.top()]) {
			reverseDFS(s.top());
			counter++;
		}
		s.pop();
	}

	cout << counter;
	return 0;
}