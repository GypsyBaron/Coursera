#include <iostream>
#include <vector>


using namespace std;

vector<int> graph[31];
bool visited[31];
bool hasCycle = false;

void DFS(int k, int n, int visitCounter) {
	//cout << "K - " << k << " .Visit Counter - " << visitCounter << endl;
	//visited[k] = true;
    if(hasCycle)
        return;
	if (n - 1 == visitCounter) {
		//cout << "Suveikia " << endl;
		hasCycle = true;
        return;
	}
	// Bandyt? :D
    // 
	for (int i = 0; i < graph[k].size(); i++) {
		if (!visited[graph[k][i]]) {
			visitCounter++;
            visited[graph[k][i]] = true; 
			DFS(graph[k][i], n, visitCounter); 
            if(hasCycle)
                return;
			visited[graph[k][i]] = false;
			visitCounter--;
		}
	}
}

int main() {
	int n, m, temp1, temp2;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	for (int j = 1; j <= n; j++) {
		visited[j] = false;
	}

    for(int i = 1; i <= n; i++){
        visited[i] = true;
        DFS(i, n, 0);
        visited[i] = false;
        if(hasCycle) 
            break;
    }

	if (hasCycle) {
		cout << "1 1" << endl;
		cout << "1 -1 0" << endl;
	} else {
		cout << "2 1" << endl;
		cout << "1 0" << endl;
		cout << "-1 0" << endl;
	}

	return 0;
}