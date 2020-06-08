#include <bits/stdc++.h>
using namespace std;

bool mycompare(pair<double, pair<int, int> >p1, pair<double, pair<int, int> >p2) {
	return p1.first > p2.first;
}

int fractionalKnapsack(int* wt, int* prices, int items, int totalWeight) {
	vector<pair<double, pair<int, int>> >details; //pair<price/wt, pair<wt, price> >

	int totalPrice = 0;
	for (int i = 0; i < items; ++i)
	{
		pair<double, pair<int, int> >p;
		p = make_pair(prices[i] / wt[i], make_pair(wt[i], prices[i]));
		details.push_back(p);
	}

	sort(details.begin(), details.end(), mycompare);

	int i = 0;
	while (totalWeight > 0 and i < items) {
		int currWeight = details[i].second.first;
		if (currWeight <= totalWeight) {
			totalWeight -= currWeight;
			totalPrice += details[i].second.second;
		}
		else {
			//fractional wt
			totalPrice += totalWeight * details[i].first;
			totalWeight = 0;
		}
		i++;
	}
	return totalPrice;

}


int main(int argc, char const *argv[])
{
	int wt[3] = {5, 3, 2};
	int prices[3] = {1000, 800, 900};
	int items = 3;
	int totalWeight = 7;

	cout << fractionalKnapsack(wt, prices, items, totalWeight) << endl;
	return 0;
}