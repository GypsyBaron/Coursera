#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(){
	
	ios::sync_with_stdio(0), cin.tie(0);


	int left = 2, right = 99, middle = 0, answer = 0;
	string prefix, suffix;
	bool correct;

    vector<string> read(400);

    for (string& s: read) {
		cin >> s;
	}

    while(left <= right){

        middle = left + (right - left) / 2;

        map<string, string> connection;
        unordered_map<string, int> first, second;
        unordered_set<string> set;
		
        for(string& s : read){

            for(int i = 0; i <= s.size() - middle; i++){

                prefix = s.substr(i, middle - 1);
                suffix = s.substr(i+1, middle - 1);
                if(connection[prefix] != suffix){
                    first[suffix]++;
                    second[prefix]++;
                    set.insert(prefix);
                    set.insert(suffix);
                    connection[prefix] = suffix;
                }

            }

        }

        correct = true;

        for(auto& i : set){
            if (first[i] != second[i]){
                correct = false;
                break;
            }
        }

        if (correct) {
            answer = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
