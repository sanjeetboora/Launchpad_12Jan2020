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

	int connectedComponents() {
		unordered_map<int, bool> visited;

		for (auto vertex : mp)
		{
			visited[vertex.first] = false;
		}

		int components = 0;

		for (auto vertex : mp)
		{
			if (!visited[vertex.first]) {
				cout << "component --> " << components << endl;
				dfsHelper(vertex.first, visited);
				components++;
				cout << endl;
			}
		}

		return components;

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

	g.addEdge(5, 6);
	g.addEdge(7, 6);
	g.addEdge(7, 5);

	g.addEdge(8, 9);


	g.printList();
	cout << g.connectedComponents() << endl;

	return 0;
}
