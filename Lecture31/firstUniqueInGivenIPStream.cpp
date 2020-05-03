#include <bits/stdc++.h>
using namespace  std;

void firstUnique() {

	int freq[26] = {0};
	queue<char> q;
	char ch;
	cin >> ch;

	while (ch != '0')
	{

		freq[ch - 'a']++;

		if (freq[ch - 'a'] > 1) { //repeated char
			while (!q.empty() and freq[q.front() - 'a'] > 1) {
				q.pop();
			}
		}
		else { //unique char
			q.push(ch);
		}

		if (!q.empty()) {
			cout << q.front() << endl;
		}
		else {
			cout << "-1" << endl;
		}

		cin >> ch;

	}
}

int main(int argc, char const *argv[])
{

	string str = "aabcdbghcbk";
	firstUnique();

	return 0;
}