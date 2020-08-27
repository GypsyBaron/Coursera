#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
long long graph[101][101];

long long MaxFlow(long long n) {
	
	queue<long long> q;
	vector<long long> path;
	long long parent[101];
	bool visited[101];
	bool sinkReached = true;
	long long current;
	long long flow = 0, maxFlow = 0;

	while(sinkReached) {

		//Setting values to zero
		sinkReached = false;
		for (long long i = 1; i <= n; i++) {
			parent[i] = 0;
			visited[i] = false;
		}

		path.clear();
		q.push(1);

		while (!q.empty()) {
			current = q.front();
			visited[current] = true;
			q.pop();

			for (long long i = 1; i <= n; i++) {

				if (graph[current][i] > 0 && !visited[i]) {

					if (i == n) {
						
						sinkReached = true;
						parent[n] = current;

						//Finding path
						current = n;
						while (current != 1) {
							path.push_back(current);
							current = parent[current];
						}
						path.push_back(current);

						// cout << "Path" << endl;
						// for (int j = 0; j < path.size(); j++) {
						// 	cout << path[j] << " ";
						// }
						//Finding minimum path value
						flow = numeric_limits<long long>::max();
						for (long long j = 0; j < path.size() - 1; j++) {
							flow = min(flow, graph[path[j + 1]][path[j]]);
						}

						maxFlow += flow;

					
						//Assignging new capacities 
						for (long long j = 0; j < path.size() - 1; j++) {
							graph[path[j]][path[j + 1]]	+= flow;
							graph[path[j + 1]][path[j]] -= flow;
						}

						break;
						
					} else {
						q.push(i);
						parent[i] = current;
					}
				}
			}

			if (sinkReached) {
				while(!q.empty()) q.pop();
			}
		}
	}
	
	return maxFlow;
}

int main() {
	long long n, m, u, v, cap;
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			graph[i][j] = 0;
		}
	}

	for (long long i = 0; i < m; i++) {
		cin >> u >> v >> cap;
		graph[u][v] += cap;
	}

	long long result = MaxFlow(n);
	cout << result;
}