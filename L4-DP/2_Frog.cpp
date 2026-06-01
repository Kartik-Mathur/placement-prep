#include <bits/stdc++.h>
using namespace std;
int n,k;

int bottomUp(vector<int> &heights){
	vector<int> dp(n+1,0);
	dp[1] = abs(heights[1] - heights[0]);
	int op1,op2;
	for (int i = 2; i < n; ++i)
	{
		int ans = INT_MAX;
		for (int j = 1; j <= k; ++j)
		{
			if(i >= j){
				ans = min (ans, 
						abs(heights[i] - heights[i-j])
					+ dp[i - j]);
			}
		}

		dp[i] = ans;
	}

	return dp[n-1];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif		

	cin>>n>>k;
	vector<int> heights(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>heights[i];
	}

	cout << bottomUp(heights) << endl;

	return 0;
}
















