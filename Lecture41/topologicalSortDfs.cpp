#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//unweighted graph
template<typename T>
class graph
{
	unordered_map<T, list<T> > mp;
public:

	void addEdge(T x, T y) {

		mp[x].push_back(y);

	}

	void dfsHelper(T node, unordered_map<T, bool> &visited, list<T> &ans ) {
		visited[node] = true;
		for (T nbr : mp[node]) {
			if (!visited[nbr]) {
				dfsHelper(nbr, visited, ans);
			}
		}
		ans.push_front(node);
	}

	void topologicalSortdfs() {
		list<T> ans;
		unordered_map<T, bool> visited;

		for (auto ver : mp) {
			if (!visited[ver.first]) {
				dfsHelper(ver.first, visited, ans);
			}
		}


		for (T ele : ans) {
			cout << ele << ", ";
		} cout << endl;

	}



	void printList() {

		for (auto pr : mp) {
			T vertex = pr.first;


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
	graph<string> g;
	g.addEdge("10", "Diploma");
	g.addEdge("10", "11");
	g.addEdge("11", "12");
	g.addEdge("12", "Drop");
	g.addEdge("12", "JEE");
	g.addEdge("12", "DU");
	g.addEdge("JEE", "BTech");
	g.addEdge("JEE", "BE");
	g.addEdge("Intelligent", "BTech");
	g.addEdge("Diploma", "BTech");


	g.printList();
	g.topologicalSortdfs();
	return 0;
}












