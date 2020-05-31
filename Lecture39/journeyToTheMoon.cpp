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

	void dfsHelper(int src, unordered_map<int, bool> &visited, int &vertexCount) {
		visited[src] = true;
		vertexCount++;

		for (int nbr : mp[src]) {
			if (!visited[nbr]) {
				dfsHelper(nbr, visited, vertexCount);
			}
		}

	}

	int pairsFromDifferentCountries(int n) {
		unordered_map<int, bool> visited;

		int countries = 0;
		int totalPossiblePairs = (n * (n - 1)) / 2; //nC2

		int pairsFromSameCountry = 0;

		for (auto vertex : mp)
		{	int atronauts = 0;
			if (!visited[vertex.first]) {

				dfsHelper(vertex.first, visited, atronauts);
				pairsFromSameCountry = (atronauts * (atronauts - 1)) / 2;
				totalPossiblePairs -= pairsFromSameCountry;

				countries++;

			}
		}
		cout << "countries -- " << countries << endl;
		return totalPossiblePairs;

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
	int n = 7;
	g.addEdge(0, 1);
	g.addEdge(0, 4);

	g.addEdge(5, 6);

	g.addEdge(2, 3);

	cout << g.pairsFromDifferentCountries(n) << endl;

	return 0;
}
