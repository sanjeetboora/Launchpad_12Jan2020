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


	void dijkstra(int src) {
		set<pair<int, int> >pathSet;//set<pair<weight of path till node_x, node_x> >pathSet;

		unordered_map<int, int>distance; //unordered_map<node_x, weight of path till node_x>distance;

		for (auto vr : mp) {
			distance[vr.first] = INT_MAX;
		}

		distance[src] = 0;
		pathSet.insert(make_pair(distance[src], src));

		while (!pathSet.empty()) {
			auto minDisNode = *(pathSet.begin());

			int node = minDisNode.second;
			int nodeDis = minDisNode.first;

			pathSet.erase(pathSet.begin());

			for (auto nbr : mp[node]) {
				//better result
				if ((nbr.second + nodeDis) < distance[nbr.first]) {
					auto findInSet = pathSet.find(make_pair(distance[nbr.first], nbr.first));
					if (findInSet != pathSet.end()) { //node found in set
						pathSet.erase(findInSet);// nbr deleted from set
					}

					distance[nbr.first] = nbr.second + nodeDis; //distance updated
					pathSet.insert(make_pair(distance[nbr.first], nbr.first)); // nbr inserted in set
				}
			}

		}

		for (auto vr : distance) {
			cout << vr.first << ", " << vr.second << endl;
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

	g.addEdge(0, 1, 2, false);
	g.addEdge(0, 2, 4, false);
	g.addEdge(1, 3, 3, false);
	g.addEdge(1, 4, 2, false);
	g.addEdge(2, 4, 7, false);
	g.addEdge(5, 3, 2, false);
	g.addEdge(4, 5, 1, false);
	g.addEdge(2, 1, 1, false);
	g.addEdge(3, 4, 3, false);

	g.dijkstra(0);


	g.printList();

	return 0;
}
