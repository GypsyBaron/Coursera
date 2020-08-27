#include <iostream>
#include <vector>

using namespace std;

int minStops(int d, int m, int n, vector<int> stops) {
	int numberOfRefills = 0;
	int currentRefillPosition = 0;
	int lastRefillPosition = 0;

	while (currentRefillPosition <= n) {
		lastRefillPosition = currentRefillPosition;

		while(currentRefillPosition <= n && stops[currentRefillPosition + 1] - stops[lastRefillPosition] <= m) {
			currentRefillPosition++;
		}

		if (currentRefillPosition  == lastRefillPosition) {
			return -1;
		}

		if (currentRefillPosition <= n) {
			numberOfRefills++;
		}
	}

	return numberOfRefills;
}

int main() {
	int d, m, n, temp;
	vector<int> stops;
	cin >> d >> m >> n;

	stops.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		stops.push_back(temp);
	}
	stops.push_back(d);
	
	cout << minStops(d, m, n, stops) << endl;
}