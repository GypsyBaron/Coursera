#include <iostream>
#include <vector>

using namespace std;

bool visited[10001];
vector<pair<int, char>> graph[500002];

void DFS(int v) {
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		cout << v << "->" << graph[v][i].first << ":" << graph[v][i].second << endl;
		DFS(graph[v][i].first);
	}
}

void PrefixTrie(string text) {
	char startSymbol;
	int counter, root;
	bool wasFound;

	for (int i = 0; i < text.length(); i++) {
		root = 0;
		startSymbol = text[i];
		counter = i;

		while(1) {

			if (graph[root].size() == 0) {
				cout << i << " ";
				break;
			} 

			wasFound = false;
			for (int j = 0; j < graph[root].size(); j++) {
				if (startSymbol == graph[root][j].second) {
					startSymbol = text[counter + 1];
					root = graph[root][j].first;
					counter++;
					wasFound = true;
					break;
				}
			}

			if (!wasFound) {
				break;
			}
		}
	}
}

int main() {
	int n, root, counter = 1;
	string pattern, text;
	char currentSymbol;
	bool wasFound;
	
	cin >> text;
	cin >> n;

	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	for (int i = 0; i < n; i++) {
		cin >> pattern;
		root = 0;

		for (int j = 0; j < pattern.length(); j++) {
			currentSymbol = pattern[j];
			wasFound = false;
			for (int k = 0; k < graph[root].size(); k++) {
				if (graph[root][k].second == currentSymbol) {
					wasFound = true;
					root = graph[root][k].first;
					break;
				}
			}

			if (!wasFound) {
				graph[root].push_back(make_pair(counter, currentSymbol));
				root = counter;
				counter++;
			}
		}
	}

	//DFS(0);
	PrefixTrie(text);

	return 0;
}