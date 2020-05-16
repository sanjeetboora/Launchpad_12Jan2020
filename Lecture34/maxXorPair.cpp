#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


class node
{
public:
	int data;
	node* zero;
	node* one;
	node(int d) {
		data = d;
		zero = one = NULL;
	}
};

class trie
{
public:
	node* root;
	trie() {
		root = new node('\0');
	}

	void insert(int num) {
		node* temp = root;

		for (int i = 31; i >= 0 ; i--) //no. of bits in num = 32
		{
			int currBit = (num >> i) & 1;
			if (currBit) { //currBit = 1
				if (temp->one == NULL) {
					node* bit = new node(1);
					temp->one = bit;
				}
				temp = temp->one;
			}
			else { //currBit = 0
				if (temp->zero == NULL) {
					node* bit = new node(0);
					temp->zero = bit;
				}
				temp = temp->zero;
			}
		}
	}


	int maxXorPair(int*arr, int n) {
		int maxXor = 0;

		for (int i = 0; i < n; ++i)
		{
			int num = arr[i];
			int currXor = 0;
			node* temp = root;
			for (int k = 31; k >= 0; k--)
			{
				int currBit = (num >> k) & 1;
				if (currBit) { //currBit =1
					if (temp->zero) {
						currXor += pow(2, k);
						temp = temp->zero;
					}
					else {
						temp = temp->one;
					}

				}
				else { //currBit =0
					if (temp->one) {
						currXor += pow(2, k);
						temp = temp->one;
					}
					else {
						temp = temp->zero;
					}
				}
			}

			maxXor = max(maxXor, currXor);
		}
		return maxXor;
	}
};

int main(int argc, char const *argv[])
{	trie t;
	int n = 5;
	int arr[10] = {3, 2, 1, 6, 5};
	for (int i = 0; i < n; ++i)
	{
		t.insert(arr[i]);
	}
	cout << t.maxXorPair(arr, n) << endl;
	return 0;
}
















