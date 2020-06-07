#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class graph
{	int V;
	int connectedComponents;
	vector<int> parent;
public:
	graph(int v) {
		V = v;
		connectedComponents = V;
		parent.reserve(V);

		for (int i = 0; i < V; ++i)
		{
			parent[i] = i;
		}
	}

	int superParent(int x) {

		if (parent[x] == x) {
			return x;
		}
		else {
			int SupeParentOfX = superParent(parent[x]);
			parent[x] = SupeParentOfX;
			return SupeParentOfX;
		}

	}

	void unite(int u, int v) {
		int parU = superParent(u);
		int parV =  superParent(v);

		if (parU != parV) {
			parent[parU] = parV;
			connectedComponents--;
		}
	}


};


int main(int argc, char const *argv[])
{
	int n = 7;
	graph(n);


	return 0;
}




