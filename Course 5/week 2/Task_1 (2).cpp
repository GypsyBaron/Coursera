#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int n;
	double matrix[21][21];
	double temp;

	cin >> n;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> matrix[i][j];
		}
	}

	// cout << "Matrica -" << endl;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << matrix[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//cout << matrix[i][i] << " " << matrix[j][i] << endl;
			if (fabs(matrix[i][i]) < fabs(matrix[j][i])) {
				// << "Suveike. I - " << i << " J - " << j << endl;
				for (int k = 0; k <= n; k++)
                {
                    temp = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
			}
		}     
		//cout << "-------------------" << endl;
	}               

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				temp = matrix[j][i] / matrix[i][i];
				for (int k = 0; k <= n; k++) {
					matrix[j][k] -= temp * matrix[i][k];  
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << fixed << setprecision(6) << matrix[i][n] / matrix[i][i] << " ";
	}

   return(0);
}