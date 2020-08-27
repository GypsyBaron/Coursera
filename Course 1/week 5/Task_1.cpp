#include <iostream>
#include <limits>

using namespace std;

int moneyChange(int money, int coins[]) {
	int minNumberCoins[money + 1];
	minNumberCoins[0] = 0;

	for (int i = 1; i <= money; i++) {
		minNumberCoins[i] = numeric_limits<int>::max();
		for (int j = 0; j < 3; j++) {
			if (i >= coins[j]) {
				int minCoins = minNumberCoins[i - coins[j]] + 1;
				if (minCoins < minNumberCoins[i]) {
					minNumberCoins[i] = minCoins;
				}
			}
		}
	}

	return minNumberCoins[money];
}

int main() {
	int n;
	int coins[3] = {1, 3, 4};
	cin >> n;

	int result = moneyChange(n, coins);
	cout << result;

	return 0;
}