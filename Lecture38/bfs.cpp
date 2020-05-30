#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//weighted graph

class graph
{
	unordered_map<int, list<int > > mp;
	//unordered_map<vertex, list<neighbour > > mp;
public:

	void addEdge(int x, int y, bool bidirectional = true) {

		mp[x].push_back(y);

		if (bidirectional) {
			mp[y].push_back(x);
		}
	}

	void bfs(int src) {
		unordered_map<int, bool> visited;

		queue<int> q;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			int frontNode = q.front();
			q.pop();

			cout << frontNode << ", ";

			for (auto nbr : mp[frontNode]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		cout << endl;

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

	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 2);
	g.addEdge(1, 3, 4);
	g.addEdge(3, 4, 1);
	g.addEdge(3, 2, 1);
	g.addEdge(2, 4, 2);

	g.printList();
	g.bfs(0);
	return 0;
}
