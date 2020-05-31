#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//unweighted graph

class graph
{
	unordered_map<int, list<int> > mp;
public:

	void addEdge(int x, int y, bool bidirectional = true) {

		mp[x].push_back(y);

		if (bidirectional) {
			mp[y].push_back(x);
		}
	}

	void dfsHelper(int src, unordered_map<int, bool> &visited) {
		visited[src] = true;
		cout << src << ", ";

		for (int nbr : mp[src]) {
			if (!visited[nbr]) {
				dfsHelper(nbr, visited);
			}
		}

	}

	void dfs(int src) {
		unordered_map<int, bool> visited;

		for (auto vertex : mp)
		{
			visited[vertex.first] = false;
		}

		dfsHelper(src, visited);
	}


	void printList() {

		for (auto pr : mp) {
			int vertex = pr.first;


			cout << vertex << " --> ";

			for (auto nbr : pr.second)
			{


				cout << nbr << ", ";
			}
			cout << endl;
		}
	}

};


int main(int argc, char const *argv[])
{
	graph g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 4);


	g.printList();
	g.dfs(0);
	return 0;
}
