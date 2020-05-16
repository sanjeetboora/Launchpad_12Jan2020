#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class node {
public:
	char data;
	bool isTerminated;
	int visited;
	unordered_map<char, node*> children;

	node(char ch) {
		data = ch;
		isTerminated = false;
		visited = 0;
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
			temp->visited = temp->visited  + 1;
		}
		temp->isTerminated = true;
	}

	void uniquePrefixes(node* currNode, string prefix) {
		if (currNode == NULL) {
			return;
		}

		if (currNode->visited == 1) {
			cout << prefix << endl;
			return;
		}

		for (auto child : currNode->children) {
			char ch = child.first;
			uniquePrefixes(child.second, prefix + ch);
		}
	}

};


int main(int argc, char const *argv[])
{
	trie t;

	int n = 7;
	string arr[10] = {"app", "mango", "apple", "ape", "agent", "apply", "man"};

	for (int i = 0; i < n; ++i)
	{
		t.insert(arr[i]);
	}

	t.uniquePrefixes(t.root, "");

	return 0;
}














