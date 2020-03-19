//https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650

#include <bits/stdc++.h>
using namespace std;

int getMostWork(vector<int> folders, int workers) {
	int n = folders.size();
	int min = *max_element(folders.begin(), folders.end());
	int max = accumulate(folders.begin(), folders.end(), 0);
	int ans = 0;
	while ( min < max) {
		int mid = min + (max - min) / 2;
		int workerUsed = 1, workload = 0;

		for (int i = 0; i < n; ++i)
		{
			if (folders[i] + workload <= mid) {
				workload += folders[i];
			}
			else {
				workerUsed++;
				workload = folders[i]; // workload of new worker
			}
		}
		if (workerUsed <= workers) {
			ans = mid;
			max = mid;
		}
		else {
			min = mid + 1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int arr[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	int workers = 3;
	//covert array to vector
	vector<int> folders(arr, arr + 9);
	cout << getMostWork(folders, workers) << endl;


	return 0;
}


