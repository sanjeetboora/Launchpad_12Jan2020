#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//weighted graph

class graph
{
	int V;
	unordered_map<int, list<pair<int, int> > > mp;
	//unordered_map<vertex, list<pair<neighbour, weight> > > mp;
public:
	graph(int n) {
		V = n;
	}

	void addEdge(int x, int y, int wt, bool bidirectional = true) {

		mp[x].push_back(make_pair(y, wt));

		if (bidirectional) {
			mp[y].push_back(make_pair(x, wt));
		}
	}



	int dfsHelper(int src, unordered_map<int, pair<bool, int> > &visited, int &maxDistTravelled) {
		visited[src] = make_pair(true, 1);


		for (auto nbrPair : mp[src]) {

			int nbr = nbrPair.first;
			int wt = nbrPair.second;

			if (!visited[nbr].first) {
				visited[src].second += dfsHelper(nbr, visited, maxDistTravelled);
				int nodesNbr = visited[nbr].second;
				int nodesLeft = V - nodesNbr;
				maxDistTravelled += 2 * min(nodesNbr, nodesLeft) * wt;
			}
		}
		return visited[src].second;
	}

	void dfs(int src) {
		unordered_map<int, pair<bool, int> > visited;

		for (auto vertex : mp)
		{
			visited[vertex.first] = make_pair(false, 0);
		}

		int maxDistTravelled = 0;

		dfsHelper(src, visited, maxDistTravelled);
		cout << maxDistTravelled << endl;
	}



	void printList() {

		for (auto pr : mp) {
			int vertex = pr.first;
			list<pair<int, int> > neighbours = pr.second;

			cout << vertex << " --> ";

			for (auto nbr : neighbours)
			{
				int nbr_vertex = nbr.first;
				int nbr_weight = nbr.second;

				cout << "{ " << nbr_vertex << ", " << nbr_weight << " }, ";
			}
			cout << endl;
		}
	}

};


int main(int argc, char const *argv[])
{
	graph g(4);

	g.addEdge(0, 1, 3);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 3, 2);

	g.dfs(0);
	g.printList();

	return 0;
}
