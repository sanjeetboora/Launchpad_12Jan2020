#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


class node
{
public:
	int data;
	node* zero;
	node* one;
	int prefixXor;
	node(int d) {
		data = d;
		zero = one = NULL;
		prefixXor = 0;
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
		temp->prefixXor = num;
	}


	int XorQuery(int num) {

		node* temp = root;
		for (int k = 31; k >= 0; k--)
		{
			int currBit = (num >> k) & 1;
			if (currBit) { //currBit =1
				if (temp->zero) {
					temp = temp->zero;
				}
				else {
					temp = temp->one;
				}

			}
			else { //currBit =0
				if (temp->one) {

					temp = temp->one;
				}
				else {
					temp = temp->zero;
				}
			}
		}
		return num xor temp->prefixXor;

	}
};

int main(int argc, char const *argv[])
{	trie t;
	int n = 6;
	int arr[10] = {8, 1, 2, 12, 7, 6};
	int prefixXor = 0;
	int maxXorSubarrayPair = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		prefixXor = prefixXor xor arr[i];
		t.insert(prefixXor);
		maxXorSubarrayPair = max(maxXorSubarrayPair, t.XorQuery(prefixXor));
	}
	cout << maxXorSubarrayPair << endl;
	return 0;
}
















