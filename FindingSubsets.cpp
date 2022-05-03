#include<bits/stdc++.h>
using namespace std;

void findSubsets(char *input, char *output, int i, int j)
{
	//base case
	if (input[i] == '\0')
	{
		output[j] = '\0';
		if (output[0] == '\0')
			cout << "NULL" << endl;
		cout << output << endl;
		return;
	}

	//rec case
	//Including the ith letter
	output[j] = input[i];
	findSubsets(input, output, i + 1, j + 1);

	//Excluding the ith letter
	findSubsets(input, output, i + 1, j);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char input[100];
	char output[100];

	cin >> input;
	findSubsets(input, output, 0, 0);

	return 0;

}