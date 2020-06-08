#include <bits/stdc++.h>
using namespace std;

int maxActivities(int n, vector<pair<int, int> >activities) {
	int numActivities = 1;

	int lastActivityEndTime = activities[0].first;
	for (int i = 1; i < n; ++i)
	{
		if (activities[i].second >= lastActivityEndTime) {
			numActivities++;
			lastActivityEndTime = activities[i].first;
		}
	}
	return numActivities;
}

int main(int argc, char const *argv[])
{

	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<pair<int, int> >activities;
		for (int i = 0; i < n; ++i)
		{
			int st, end;
			cin >> st >> end;
			activities.push_back(make_pair(end, st));
		}

		sort(activities.begin(), activities.end());
		cout << maxActivities(n , activities) << endl;
	}
	return 0;
}