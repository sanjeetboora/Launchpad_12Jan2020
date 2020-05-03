#include <bits/stdc++.h>
using namespace  std;

char firstUnique(string str) {

	int freq[26] = {0};
	queue<char> q;

	for (int i = 0; i < str.length(); ++i)
	{
		char ch = str[i];
		freq[ch - 'a']++;

		if (freq[ch - 'a'] > 1) { //repeated char
			while (!q.empty() and freq[q.front() - 'a'] > 1) {
				q.pop();
			}
		}
		else { //unique char
			q.push(ch);
		}
	}
	return q.front();
}

int main(int argc, char const *argv[])
{

	string str = "aabcdbghcbk";
	cout << firstUnique(str) << endl;

	return 0;
}