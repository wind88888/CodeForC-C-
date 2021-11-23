#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
using namespace std;

    int maxProduct(vector<string>& words) {
        int length = words.size();
		int masks[length];
//		memset(masks, 0, sizeof(masks));
        for (int i = 0; i < length; i++) {
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
	}
        

int main(void) {
	string word = "abc";
	int masks = 0;
	for (int i = 0; i < word.size(); i++) {
		int ma = (word[i] - 'a');
		int maa = 1 << ma;
		masks |= maa;
	}
	
	cout << masks << endl;
	
	int das = 1 << 0;
	cout << "das == " << das << endl;
	
	vector<string> words;
	words.push_back("abcw");
	words.push_back("baz");
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("xtfn");
	words.push_back("abcdef");
	int res = maxProduct(words);
	
	cout << res << endl;
	
	char* tret = "fhtgdg";
	cout << "addr====" << &tret << endl;
	cout << sizeof(tret) << endl;
//	cout << strlen(tret) << endl;
	cout << sizeof(char) << endl;
	bool arr[38];
	cout << sizeof(arr) << endl;
	
	int fwre[] = {1,2,3,5};
	cout << sizeof(fwre) << endl;

    int ma[5];
    memset(ma, 1, sizeof(ma));
	string s = "ab";
	string goal = "ba";
	
	int k = s.compare(goal);

	bool ddsa = 1;
	bool ddsads = -1;
	bool ddsadas = 0;

	cout << ddsa << ddsads << ddsadas << endl;

    int ds = 2314l;
	// getchar();
	return 0;
} 