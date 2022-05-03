#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) // for ordering subsets on length and lexicographic criteria
{
	if (a.length() == b.length())
	{
		return a < b; //lexicographic
	}
	return a.length() < b.length();
}
void find_orderSubsets(char *input, char *output, int i, int j, vector<string> &str)
{
	//base case
	if (input[i] == '\0')
	{
		output[j] = '\0';
		string temp(output);

		str.push_back(temp);
		return;
	}

	//rec case
	//Including the ith letter
	output[j] = input[i];
	find_orderSubsets(input, output, i + 1, j + 1, str);

	//Excluding the ith letter
	find_orderSubsets(input, output, i + 1, j, str);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char input[100];
	char output[100];
	vector<string> str;

	cin >> input;

	find_orderSubsets(input, output, 0, 0, str);
	sort(str.begin(), str.end(), compare);

	//print the output
	for (auto it : str)
	{
		cout << it << endl;
	}
	return 0;

	//The first output is NULL string therefore it will show empty in first line
}