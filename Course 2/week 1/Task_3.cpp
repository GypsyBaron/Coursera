#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int S, n, k = 0;
	long long time = 0, endTime = 0;
	bool isSedondUsed;

	cin >> S >> n;

	int times[n];
	vector< pair<int, int> > vect;
	vector<long long> startTimes;
	queue< pair<int, int> > q;

	for (int i = 0; i < n; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		vect.push_back( make_pair(temp1, temp2) );
		times[i] = 0;
	}

	int index = 0;

	while (k < n) {

		//Reading loop
		for (int i = index; i < n; i++) {
			//cout << "First circle " << i << endl;
			if (vect[i].first == time) {
				if (q.size() < S) {
					if (q.empty()) {
						if (vect[i].second == 0) {
							k++;
						} else {
							endTime = time + vect[i].second;
							q.push(vect[i]);
						}
						startTimes.push_back(time);
					} else {
						q.push(vect[i]);
					}
				} else {
					times[i] = -1;
					k++;
				}
			} else {
				index = i;
				break;
			}
		}
	

		isSedondUsed = false;
		//Controll loop
		for (int i = 0; i < q.size(); i++) {
			//cout << "Second circle " << endl;
			if ((time + 1 == endTime) && isSedondUsed == false) {
				//cout << "Second 1" << endl;
				isSedondUsed = true;
				k++;
				q.pop();
				i--;

				//cout << q.size() << endl;
				if (!q.empty()) {
					//cout << "Second 1.1" << endl;
					startTimes.push_back(time + 1);
					endTime = time + q.front().second + 1;
				}
			} else if (time == endTime) {
				//cout << "Second 2" << endl;
				k++;
				q.pop();
				i--;

				if (!q.empty()) {
					startTimes.push_back(time);
					endTime = time + q.front().second;
				}
			} else {
				//cout << "Second 3" << endl;
				break;
			}
		}

		time++;
		//cout << "Time increment - " << time << endl;
	}

	//cout << "Loop ended." << endl;
	index = 0;
	for (int i = 0; i < n; i++) {
		//cout << "I - " << i << endl;
		if (times[i] == -1) {
			cout << -1 << endl;
		} else {
			cout << startTimes[index] << endl;
			index++;
		}
	}

	return 0;
}