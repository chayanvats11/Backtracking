#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

int gridPermutations(int m, int n)
{
	int ways = (factorial(n - 1 + m - 1)) / (factorial(n - 1) * factorial(m - 1));
	return ways;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m, n;
	cin >> m >> n;

	cout << gridPermutations(m, n);
	return 0;
}