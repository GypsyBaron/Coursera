#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

bool hasPath(vector< vector<int> > graph) {
	int arr[graph.size() + 1];

	for (int i = 1; i <= graph.size(); i++) {
		arr[i] = 0;
	}

	for (int i = 1; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) {			
			arr[graph[i][j]]++;
		}
	}

	for (int i = 1; i < graph.size(); i++) {
		if (graph[i].size() != arr[i]) {
			return false;
		}
	}

	return true;
}

void eulerPath(vector< vector<int> > graph) { 

    unordered_map<int,int> countEdge; 
  
    for (int i=0; i < graph.size(); i++) { 
        countEdge[i] = graph[i].size(); 
    } 
   
    stack<int> currentPath; 
    vector<int> cycle; 
  
    int currentVertex = 1; 
    currentPath.push(currentVertex); 
  
    while (!currentPath.empty()) 
    { 
        if (countEdge[currentVertex]) 
        { 
            currentPath.push(currentVertex); 
            int nextVertex = graph[currentVertex].back();  
            countEdge[currentVertex]--; 
            graph[currentVertex].pop_back(); 
            currentVertex = nextVertex; 
        } else { 
            cycle.push_back(currentVertex); 
            currentVertex = currentPath.top(); 
            currentPath.pop(); 
        } 
    } 
	
	cout << "1" << endl;
    for (int i = cycle.size()-1; i > 0; i--) { 
        cout << cycle[i] << " "; 
    } 
} 
  
int main() 
{
	int n, m, temp1, temp2;
	cin >> n >> m;

    vector< vector<int> > graph; 
    graph.resize(n + 1); 

	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
	}

	if (hasPath(graph)) {
		eulerPath(graph);
	} else {
		cout << 0;
	}
  
    return 0; 
}