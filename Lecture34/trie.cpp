#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class node {
public:
	char data;
	bool isTerminated;
	unordered_map<char, node*> children;

	node(char ch) {
		data = ch;
		isTerminated = false;
	}
};


class trie
{
public:
	node* root;
	trie() {
		root = new node('\0');
	}

	void insert(string word) {
		node* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			char ch = word[i];
			if (!temp->children.count(ch)) { //when ch doesn't exist
				node* child = new node(ch);
				temp->children[ch] = child;
			}
			temp = temp->children[ch];
		}
		temp->isTerminated = true;
	}

	bool search(string word) {
		node* temp = root;
		for (int i = 0; i < word.length(); ++i)
		{
			char ch = word[i];
			if (!temp->children.count(ch)) { //when ch doesn't exist
				return false;
			}
			temp = temp->children[ch];
		}

		return temp->isTerminated;
	}

};


int main(int argc, char const *argv[])
{
	trie t;

	int n;
	cin >> n;

	while (n--) {
		string word;
		cin >> word;
		t.insert(word);
	}

	int q;
	cin >> q;

	while (q--) {
		string word;
		cin >> word;

		if (t.search(word)) {
			cout << word << " found" << endl;
		}
		else {
			cout << word << " not found" << endl;
		}
	}

	return 0;
}














