#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif	

	int n;
	cin>>n;
	vector<int> a(n), leftMax(n), rightMin(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	// Finding leftMax
	
	leftMax[0] = INT_MAX;
	int ans = a[0];

	for (int i = 1; i < n; ++i)
	{
		leftMax[i] = ans;
		ans = max(ans,a[i]);
	}

	ans = INT_MAX;
	for (int i = n-1; i >= 0; --i)
	{
		ans = min(ans, a[i]);
		rightMin[i] = ans;
	}

	int result = 1;
	for (int i = 1; i < n; ++i)
	{
		if(leftMax[i] <= rightMin[i])
			result++;
	}

	cout << result<<endl;


	return 0;
}
















