#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int stringCompare(string& a, string& b, int size){
    for (int i = 0, n = 1 + a.size()-size; i < n; ++i)
        if(strncmp(b.c_str(), a.c_str() + i, a.size() - i) == 0)
            return a.size() - i;
    return 0;
}

int main (){

	int readCounter = 1618, index = 0;
	string genom, firstRead, currentRead = "";
    vector<string> read(readCounter);

    for(int i = 0; i < readCounter; i++){
		cin >> read[i];
    }

    genom += read[0];
	firstRead = read[0];
	
    while(read.size() > 1) {

        currentRead = read[index];
        read.erase(read.begin() + index);

        int max = -1;

        for(int j = 0; j < read.size(); j++) {
            int overlap = stringCompare(currentRead, read[j], 12);
            if (overlap > max) {
				max = overlap, 
				index = j;
			}
        }

        genom += read[index].substr(max);
    }

    genom.erase(0, stringCompare(read[0], firstRead,  12));

	cout << genom;

    return 0;
}
