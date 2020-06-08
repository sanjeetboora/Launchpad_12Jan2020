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
	int n = 6;
	graph g(6);
	int numEdges = 9;

	vector<vector<int> >edgeList;
	edgeList.reserve(numEdges);

	vector<int> edge(3); //{wt, vertex1, vertex2}
	edge = {1, 1, 2};
	edgeList.push_back(edge);
	edge = {4, 1, 4};
	edgeList.push_back(edge);
	edge = {3, 1, 5};
	edgeList.push_back(edge);
	edge = {4, 2, 4};
	edgeList.push_back(edge);
	edge = {4, 5, 4};
	edgeList.push_back(edge);
	edge = {2, 5, 2};
	edgeList.push_back(edge);
	edge = {4, 5, 3};
	edgeList.push_back(edge);
	edge = {5, 6, 3};
	edgeList.push_back(edge);
	edge = {7, 5, 6};
	edgeList.push_back(edge);


	sort(edgeList.begin(), edgeList.end());

	int totalWt = 0;

	for (int i = 0; i < numEdges; ++i)
	{
		int wt = edgeList[i][0];
		int x = edgeList[i][1];
		int y = edgeList[i][2];

		if (g.superParent(x) != g.superParent(y)) {
			g.unite(x, y);
			totalWt += wt;
		}
	}

	cout << totalWt << endl;



	return 0;
}




