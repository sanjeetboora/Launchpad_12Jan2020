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

	bool dfsHelper(int src, unordered_map<int, bool> &visited, vector<bool> &path) {
		visited[src] = true;
		path[src] = true;
		for (int nbr : mp[src]) {
			if (path[nbr]) {
				return true; //cycle detected;
			}
			if (visited.count(nbr) == 0) {
				if (dfsHelper(nbr, visited, path)) {
					return true;//cycle exists;
				}
			}
		}
		path[src] = false;
		return false;
	}

	void dfs(int src) {
		unordered_map<int, bool> visited;

		vector<bool> path;
		path.reserve(100);

		for (int i = 0; i < 10; ++i)
		{
			path[i] = false;
		}

		if (dfsHelper(src, visited, path)) {
			cout << "Cycle Exists" << endl;
		}
		else {
			cout << "Cycle doesn't exist" << endl;
		}
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

	g.addEdge(0, 1, false);
	g.addEdge(0, 2, false);
	g.addEdge(0, 3, false);
	g.addEdge(1, 2, false);
	//g.addEdge(2, 3, false);
	g.addEdge(2, 4, false);


	g.printList();
	g.dfs(0);
	return 0;
}
