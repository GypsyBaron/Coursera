#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
	int value, weight;

	Item(int value, int weight) : value(value), weight(weight){}
};

bool compareValue(struct Item a, struct Item b) {	
	double a1 = (double) a.value / a.weight;
	double a2 = (double) b.value / b.weight;
	return a1 > a2;
}
double maximumFractional(int W, vector<Item> items) {
	sort(items.begin(), items.end(), compareValue);

	double value = 0.0;

	for (int i = 0; i < items.size(); i++) {
		if (items[i].weight <= W) {
			value += items[i].value;
			W-= items[i].weight;
		} else {
			value+= W * (double)items[i].value / (double)items[i].weight;
			break;
		} 
	}

	return value;
}

int main() {
	int n, W, value, weight;
	cin >> n >> W;
	
	vector<Item> items;

	Item c = {value, weight};
	for (int i = 0; i < n; i++) {
		cin >> value >> weight;
		Item item = {value, weight};
		items.push_back(item);
	}

	cout << fixed << setprecision(4) << maximumFractional(W, items) ;
}