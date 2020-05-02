#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(int*days, int n) {
	vector<int> ans;
	stack<int> st;
	for (int currDay = 0; currDay < n; ++currDay)
	{
		int currDayPrice = days[currDay];
		while (!st.empty() and days[st.top()] <= currDayPrice) {
			st.pop();
		}
		int bestDay = st.empty() ? currDay : st.top();

		ans.push_back(currDay - bestDay);

		st.push(currDay);
	}
	return ans;

}



int main(int argc, char const *argv[])
{
	int arr[7] = {100, 90, 70, 80, 85, 60, 90};
	vector<int> result = stockSpan(arr, 7);

	for (int num : result) {
		cout << num << ", ";
	}
	cout << endl;


	return 0;
}