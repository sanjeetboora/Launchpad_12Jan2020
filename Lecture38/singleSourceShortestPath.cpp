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

	void sssp(int src) {
		unordered_map<int, int> distance;

		queue<int> q;

		q.push(src);
		distance[src] = 0;

		while (!q.empty()) {
			int frontNode = q.front();
			q.pop();

			cout << frontNode << ", ";

			for (auto nbr : mp[frontNode]) {
				if (distance.count(nbr) == 0) {
					q.push(nbr);
					distance[nbr] = distance[frontNode] + 1;
				}
			}
		}
		cout << endl;


		for (auto dist : distance)
		{
			cout << dist.first << ", " << dist.second << endl;
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
	g.sssp(0);
	return 0;
}
