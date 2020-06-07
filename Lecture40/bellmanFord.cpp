#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//weighted graph

class graph
{

	int V;
	int E;
	//edgeList
	vector<vector<int> > edges;
public:
	graph(int n, int e) {
		V = n;
		E = e;
		edges.reserve(E);
	}

	void addEdge(int x, int y, int wt) {

		vector<int> edge(3);
		edge = {x, y, wt};
		edges.push_back(edge);
	}


	void bell_man_Ford(int src) {

		vector<int> dist(V);

		for (int i = 0; i < V; ++i)
		{
			dist[i] = INT_MAX;
		}
		dist[src] = 0;

		for (int i = 1; i <= V - 1 ; ++i)
		{
			for (int j = 0; j < E; ++j)
			{
				int src = edges[j][0];
				int des = edges[j][1];
				int wt = edges[j][2];

				if (dist[src] != INT_MAX and dist[src] + wt < dist[des]) {
					dist[des] = dist[src] + wt;
				}
			}
		}

		// to detect negative cycle
		for (int j = 0; j < E; ++j)
		{
			int src = edges[j][0];
			int des = edges[j][1];
			int wt = edges[j][2];

			if (dist[src] != INT_MAX and dist[src] + wt < dist[des]) { // negative cycle detected
				cout << "negative cycle detected from " << src << " to " << des << endl;
				return;
			}
		}


		//print distance to all nodes
		for (int i = 0; i < V; ++i)
		{
			cout << i << " --> " << dist[i] << endl;
		}


	}

};


int main(int argc, char const *argv[])
{
	graph g(6, 9);

	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 3, 3);
	g.addEdge(1, 4, 2);
	g.addEdge(2, 4, -7);
	g.addEdge(2, 1, 1);
	g.addEdge(5, 3, 2);
	g.addEdge(4, 5, 1);
	g.addEdge(3, 4, -13);

	g.bell_man_Ford(0);

	return 0;
}
