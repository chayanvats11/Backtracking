#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr, int n)
{
	//print the array
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}
void fillArray(vector<int> &arr, int i, int n, int val)
{
	//base case
	if (i == n)
	{
		printArray(arr, n);
		return;
	}
	//rec case
	arr[i] = val;
	fillArray(arr, i + 1, n, val + 1);

	//backtracking step
	arr[i] = -1 * arr[i];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> arr(100, 0);
	int n;
	cin >> n;

	fillArray(arr, 0, n, 1);
	printArray(arr, n);
	return 0;
}