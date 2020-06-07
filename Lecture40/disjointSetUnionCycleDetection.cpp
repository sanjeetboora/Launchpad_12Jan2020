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
	int n = 4;
	graph g(4);

	vector<pair<int, int> >edgeList;
	edgeList.reserve(n);
	edgeList.push_back(make_pair(0, 1));
	edgeList.push_back(make_pair(2, 3));
	edgeList.push_back(make_pair(1, 2));
	edgeList.push_back(make_pair(3, 0));
	bool cycle = false;

	for (int i = 0; i < edgeList.size(); ++i)
	{
		int x = edgeList[i].first;
		int y = edgeList[i].second;

		if (g.superParent(x) != g.superParent(y)) {
			g.unite(x, y);
		}
		else {
			cycle = true;
			cout << "cycle detcted b/w" << x << ", " << y << endl;
		}
	}
	if (cycle) {
		cout << "this is a cyclic graph" << endl;
	} else {
		cout << "this is an acyclic graph" << endl;
	}

	return 0;
}




