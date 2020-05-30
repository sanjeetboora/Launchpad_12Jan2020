#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//weighted graph

class graph
{
	unordered_map<int, list<pair<int, int> > > mp;
	//unordered_map<vertex, list<pair<neighbour, weight> > > mp;
public:

	void addEdge(int x, int y, int wt, bool bidirectional = true) {

		mp[x].push_back(make_pair(y, wt));

		if (bidirectional) {
			mp[y].push_back(make_pair(x, wt));
		}
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
	graph g;

	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 2);
	g.addEdge(1, 3, 4);
	g.addEdge(3, 4, 1);
	g.addEdge(3, 2, 1);
	g.addEdge(2, 4, 2);

	g.printList();

	return 0;
}
