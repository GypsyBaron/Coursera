#include <iostream>
#include <string>
#include <stack>
#include <limits>

using namespace std;

int main() {
	int n, max, temp;
	string command;
	stack<int> stack;

	cin >> n; 
	max = numeric_limits<int>::min();

	for (int i = 0; i < n; i++) {
		cin >> command;

		if (command == "push") {
			cin >> temp;
			if (stack.empty()) {
				max = temp;
				stack.push(max);
			} else if (stack.top() > temp) {
				stack.push(max);
			} else {
				max = temp;
				stack.push(max);
			}
		} else if (command == "pop") {
			if (!stack.empty()) {
				stack.pop();
			}
		} else {
			cout << stack.top() << endl;
		}
	}

	return 0;
}