#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
long long graph[203][203];

void MaxFlow(long long n, long long m) {
	
	queue<long long> q;
	vector<long long> path;
	long long parent[203];
	bool visited[203];
	bool sinkReached = true;
	long long current;
	long long flow = 0, maxFlow = 0;
	long long fly[n];

	for (int i = 0; i < n; i++) {
		fly[i] = -1;
	}

	while(sinkReached) {
		//Setting values to zero
		sinkReached = false;
		for (long long i = 0; i <= n + m + 1; i++) {
			parent[i] = 0;
			visited[i] = false;
		}

		path.clear();
		q.push(0);

		while (!q.empty()) {
			current = q.front();
			visited[current] = true;
			q.pop();

			for (long long i = 1; i <= n + m + 1; i++) {

				if (graph[current][i] > 0 && !visited[i]) {
					if (i == n + m + 1) {
						sinkReached = true;
						parent[n + m + 1] = current;

						//Finding path
						current = n + m + 1;
						while (current != 0) {
							path.push_back(current);
							current = parent[current];
						}
						path.push_back(current);

						//Path
						// cout << "Path" << endl;
						// for (int i = 0; i < path.size(); i++) {
						// 	cout << path[i] << " ";
						// }

						maxFlow += 1;

						for (int l = 2; l < path.size(); l+= 2) {
							fly[path[l] - 1] = path[l - 1] - n;
						}

						// cout << "Ats - " << endl;
						// for (int l = 0; l < 2; l++) {
						// 	cout << fly[l] << " ";
						// }
						// cout << endl;
						//Assignging new capacities 
						for (long long j = 0; j < path.size() - 1; j++) {
							graph[path[j]][path[j + 1]]	+= 1;
							graph[path[j + 1]][path[j]] -= 1;
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
	
	//cout << "Max flow - " << maxFlow << endl;
	for (int i = 0; i < n; i++) {
		cout << fly[i] << " ";
	}

}

int main() {
	long long n, m, k;
	cin >> n >> m;

	for (long long i = 1; i <= n + m + 1; i++) {
		for (long long j = 1; j <= n + m + 1; j++) {
			graph[i][j] = 0;
		}
	}

	// Source connections	
	for (long long i = 1; i <= n; i++) {
		graph[0][i] = 1;
	}

	for (long long i = 1; i <= n; i++) {
		for (long long j = n + 1; j <= n + m; j++) {
			cin >> k;
			graph[i][j] = k;
		}
	}

	// Sink connections
	for (long long i = n + 1; i <= n + m; i++) {
		graph[i][n + m + 1] = 1;
	}


	MaxFlow(n, m);

	return 0;
}