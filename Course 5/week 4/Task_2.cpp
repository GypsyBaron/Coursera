#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;


int fun[100001];
vector<int> graph[100001];
vector<int> tree[100001];
long long D[100001];
bool visited[100001];

long long FunPartay(int k) {

	if (D[k] == numeric_limits<long long>::max()) {
		if (tree[k].size() == 0) {
			D[k] = fun[k];
		} else {

			long long m1 = fun[k];
			for (int i = 0; i < tree[k].size(); i++) {
				for (int j = 0; j < tree[tree[k][i]].size(); j++) {
					m1 += FunParty(tree[tree[k][i]][j]);
				}
			}
			
			long long m0 = 0;
			for (int i = 0; i < tree[k].size(); i++) {
				m0 += FunParty(tree[k][i]);
			}

			D[k] = max(m0, m1);
		}
				
	}
	
	return D[k];
}

int main() {
	long long n, temp1, temp2;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> fun[i];
		D[i] = numeric_limits<long long>::max();
		visited[i] = false;
	}


	for (int i = 0; i < n - 1; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	
	visited[1] = true;
	queue<int> q;
	q.push(1);

	while(!q.empty()) {
		int next = q.front();
		q.pop();

		for(int i = 0; i < graph[next].size(); i++) {
			if(!visited[graph[next][i]]) {
				tree[next].push_back(graph[next][i]);
				q.push(graph[next][i]);
				visited[graph[next][i]] = true;
			}
		}
	}

	cout << FunParty(1);

	return 0;
}