#include <bits/stdc++.h>
using namespace std;

// ele, array no., ele idx

typedef pair<int, pair<int, int> > node;

vector<int> mergeKSortedArray(vector<vector<int> > v){
	priority_queue<node, vector<node>, greater<node> > pq; //min heap
	int k = v.size();
	vector<int> result;

	int i=0;
	while(i<k){
		node ele = make_pair(v[i][0], make_pair(i, 0));
		pq.push(ele);
		i++;
	}

	while(!pq.empty()){
		node topEle = pq.top(); //pair<int, pair<int, int> > 
		result.push_back(topEle.first);

		pq.pop();

		int arrNumber = topEle.second.first;
		int idx = topEle.second.second;

		if(idx+1 < v[arrNumber].size()){
			node ele = make_pair(v[arrNumber][idx+1], make_pair(arrNumber, idx+1));
			pq.push(ele);
		}

	}
	return result;


}
int main(int argc, char const *argv[])
{
	
	vector<vector<int> > v {{1,5,8,9,10},
							{11,24,36,58, 223},
							{2,4,6}};
							
	vector<int> result = mergeKSortedArray(v);
	for (int i = 0; i < result.size(); ++i)
	{
		cout<<result[i]<<", ";
	}
	cout<<endl;
	

}