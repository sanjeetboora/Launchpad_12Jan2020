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

	void topologicalSortbfs() {
		unordered_map<T, int> indegree;
		for (auto v : mp)
		{
			indegree[v.first] = 0;
		}

		//store indegree of all vertices
		for (auto v : mp)
		{
			T currVertex = v.first;
			list<T> neighbours =  v.second;
			for (T nbr : neighbours) {
				indegree[nbr]++;
			}
		}

		list<T> ans;

		queue<T> q;

		for (auto v : indegree) {
			if (indegree[v.first] == 0) {
				q.push(v.first);
			}
		}

		while (!q.empty()) {
			T frontNode = q.front();
			q.pop();

			ans.push_back(frontNode);

			for (T nbr : mp[frontNode]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
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
	g.topologicalSortbfs();
	return 0;
}












