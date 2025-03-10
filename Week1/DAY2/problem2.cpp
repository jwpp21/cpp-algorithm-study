#include <iostream>
#include <string>;
using namespace std;

int main() {
	string s;
	cin >> s;
	int res[26];
	for (int i = 0;i < 26;i++) {
		res[i] = -1;
	}
	string abc = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0;i < s.length();i++) {
		for(int j=0;j< abc.length();j++){
			if (s[i] == abc[j]) {
				if(res[j] == -1)
					res[j] = i;
			}
		}
			
	}
	for (int i = 0;i < 26;i++) {
		cout << res[i] << " ";
	}
}
