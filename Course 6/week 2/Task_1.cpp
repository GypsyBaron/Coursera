#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int n = 5;
	vector<string> grid[n * n];
	vector<string> answer[n * n];
	int position[n * n];
	bool visited[n * n];
	string text, color = "";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			position[i * n + j] = 0;
			visited[i * n + j] = false;
			cin >> text;

			for (int k = 1; k < text.length(); k++) {

				if (text[k] == ',' || text[k] == ')') {
					int index = (i * n) + j;
					grid[index].push_back(color);
					color = "";
				} else {
					color += text[k];
				}

			}
		}
	}
	// 0  1    2    3
	// UP LEFT DOWN RIGHT 
	int lastCell = 0;
	//int counter = 0;
	int indexX = 0, indexY = 0;
	for (int i = 0; i < n * n; i++) {

		//counter++;
		indexY = abs(i / n);
		indexX = abs(i % n);

		//cout << "Indeksai - "  << indexY << " " << indexX << endl;
		//cout << "I - " << i << endl;
		for (int j = position[i]; j < n * n; j++) {
			visited[j] = false;
			lastCell = j;
			// Upper left corner
			if (indexX == 0 && indexY == 0) {
				//cout << "Tikriname kairi virsutini kampa " << endl;
				if (grid[j][0] == "black" && grid[j][1] == "black" && !visited[j]) {
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}
			
			// Upper right corner
			if (indexX == n - 1 && indexY == 0) {
				//cout << "Tikriname desini virsutini kampa " << endl;
				if (grid[j][0] == "black" && grid[j][3] == "black" && !visited[j]) {
					//cout << "Wtf?" << endl;
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}

			// Bottom left corner
			if (indexX == 0 && indexY == n - 1) {
				//cout << "Tikriname kairi apatini kampa " << endl;
				if (grid[j][1] == "black" && grid[j][2] == "black" && !visited[j]) {
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}
			
			// Bottom right corner
			if (indexX == n - 1 && indexY == n - 1) {
				//cout << "Tikriname desinis apatini kampa " << endl;
				if (grid[j][2] == "black" && grid[j][3] == "black" && !visited[j]) {
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}

			// Top
			if (indexX != 0 && indexX != n - 1 && indexY == 0) {
				//cout << "Tikriname virsu " << endl;
				if (grid[j][0] == "black" && grid[j][1] == answer[i - 1][3] && !visited[j]) {
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}

			// Left
			if (indexY != 0 && indexY != n - 1  && indexX == 0) {
				//cout << "Tikriname kaire " << endl;
				if (grid[j][1] == "black" && grid[j][0] == answer[indexY * n - n + indexX][2] && !visited[j]) {
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}

			// Bottom
			if (indexX != 0 && indexX != n - 1 && indexY == n - 1) {
				//cout << "Tikriname apacia " << endl;
				if (grid[j][2] == "black" && grid[j][1] == answer[i - 1][3] && grid[j][0] == answer[indexY * n - n + indexX][2] && !visited[j]) {
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}

			// Right
			if (indexY != 0 && indexY != n - 1 && indexX == n - 1) {
				//cout << "Tikriname desini " << endl;
				if (grid[j][3] == "black" && grid[j][0] == answer[indexY * n - n + indexX][2] && grid[j][1] == answer[i - 1][3] && !visited[j] ) {
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}

			// What's left
			if (indexX != 0 && indexX != n - 1 && indexY != 0 && indexY != n - 1) {
				//cout << "Tikriname viduri " << endl;
				if (grid[j][0] == answer[indexY * n - n + indexX][2] && grid[j][1] == answer[i - 1][3] && !visited[j]) {
					visited[j] = true;
					answer[i] = grid[j];
					position[i]++;
					break;
				}
			}

			position[i]++;
		}

		// if (counter == 20) {
		// 	break;
		// }

		if (position[i] == n * n) {
			if (!visited[lastCell]) {
				position[i] = 0;
				i-= 2;
			}
		}
	}

	for (int i = 0; i < n * n; i++) {
		//cout << "I - " << i << endl;
		cout << "(";
		for (int j = 0; j < 4; j++) {
			if (j + 1 == 4) {
				cout << answer[i][j];
			} else {
				cout << answer[i][j] << ",";
			}
		}
		cout << ")";

		if ((i + 1) % n == 0) {
			cout << endl;
		} else {
			cout << ";";
		}
	}
}