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

	bool dfsHelper(int src, unordered_map<int, bool> &visited, int parent) {
		visited[src] = true;

		for (int nbr : mp[src]) {
			//nbr not visited
			if (visited.count(nbr) == 0) {
				if (dfsHelper(nbr, visited, src)) {
					return true; //cycle exists
				}
			}
			//nbr already visited and it's not your parent
			else if (nbr != parent) { //cycle detected
				return true;
			}
		}
		return false;

	}

	void dfs(int src) {
		unordered_map<int, bool> visited;

		if (dfsHelper(src, visited, -1)) {
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

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	//g.addEdge(1, 2);
	g.addEdge(2, 4);


	g.printList();
	g.dfs(0);
	return 0;
}
