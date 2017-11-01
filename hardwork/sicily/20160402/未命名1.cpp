//1001. Break words.cpp
#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin>>n;
	if (n) {
	string s[n], seq="\0";
	//s[] is  used to store words, ser is used to store sequence
	for(int i = 0; i < n; i++) cin>>s[i];
	cin>>seq;
	for (int i = 0; i < n; i++) for (int j = 1; j < n; j++) {
		if (s[j].compare(s[j-1]) > 0) {
			string k = s[j];
			s[j] = s[j-1];
			s[j-1] = k;
		}
	}// sort the words
	int d = 0;
	while (d < seq.size()) {
		for(int i = 0; i < n; i++) {
			if (seq.find(s[i])==d) {  // if could find the word
				if(d) cout<<' ';
				cout<<s[i];
				d+=s[i].size();
				break;
			}
			if ((i == n-1) && seq.find(s[n-1])!=d) { // if could't find the word
				if(d) cout<<' ';
				cout<<seq[d];
				d+=1;
				break;
			}
		}
	}
	cout<<'\n';
	} else {     // if n==0
		string k="\0";
		cin>>k;
		for (int i = 0; i < k.size(); i++) {
			if (i) cout<<' ';
			cout<<k[i];
		}
		cout<<endl;
	}
	return 0;
}

