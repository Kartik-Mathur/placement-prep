#include <iostream>
using namespace std;

int solve(int n,vector<int> &heights, vector<int> &dp){
	// base case
	if(n == 1){
		return abs(heights[n]-heights[n-1]);
	}
	if(n == 0) return 0;

	if(dp[n] != -1){
		return dp[n];
	}
	// recursive case
	int op1, op2;
	// Take 1 step

	op1 = abs(heights[n] - heights[n-1]) + 
			solve(n-1, heights, dp);
	// Take 2 step
	op2 = abs(heights[n] - heights[n-2]) +
			solve(n-2, heights, dp);

	return dp[n]=min(op1,op2);
}

int bottomUp(vector<int> &heights){

	int n = heights.size();
	vector<int> dp(n+1,0);
	dp[1] = abs(heights[1] - heights[0]);
	int op1,op2;
	for (int i = 2; i < n; ++i)
	{
		op1 = abs(heights[i] - heights[i-1]) + 
			dp[i-1];

		op2 = abs(heights[i] - heights[i-2]) +
			dp[i-2];

		dp[i] = min(op1, op2);
	}

	return dp[n-1];
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif		

	int n;
	cin>>n;
	
	vector<int> heights(n), dp(n+1, -1);

	for (int i = 0; i < n; ++i)
	{
		cin>>heights[i];
	}

	cout << solve(n-1,heights, dp) << endl;
	cout << bottomUp(heights) << endl;

	return 0;
}
















