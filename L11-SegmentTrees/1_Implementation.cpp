#include <iostream>
using namespace std;

void buildTree(int *a,int s,int e,int index, int* tree){

	if(s == e){
		tree[index] = a[s];
		return;
	}

	int mid = ((s+e)/2);
	buildTree(a,s,mid,2*index,tree);
	buildTree(a,mid+1,e,2*index+1,tree);

	tree[index] = min(tree[2*index], tree[2*index+1]);
}

int minQuery(int *a,int s,int e,int qs,int qe, int index, int* tree){
	
	// no overlap
	if(s > qe or e < qs){
		return INT_MAX;
	}

	// complete overlap
	if(s>=qs and e <= qe){
		return tree[index];
	}

	// Partial overlap
	int mid=(s+e)/2;
	int left = minQuery(a,s,mid,qs,qe,2*index,tree);
	int right = minQuery(a,mid+1,e,qs,qe,2*index+1,tree);

	return min(left,right);

}

void update(int *a,int s,int e,int i,int index,int *tree,int val){

	if(i < s or i > e) return;
	if(s == e){
		tree[index] += val;
		return;
	}

	int mid = (s+e)/2;
	update(a,s,mid,i,2*index,tree, val);
	update(a,mid+1,e,i,2*index+1,tree, val);
	tree[index] = min(tree[2*index], tree[2*index+1]);
}

void updateRange(int *a,int s,int e,int qs, int qe,
				 int index,int *tree,int val){

	if(s > qe or qs > e) return;

	if(s == e){
		tree[index] += val;
		return;
	}

	int mid = (s+e)/2;
	updateRange(a,s,mid,qs,qe,2*index,tree, val);
	updateRange(a,mid+1,e,qs,qe,2*index+1,tree, val);
	tree[index] = min(tree[2*index], tree[2*index+1]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif		 

	int a[] = {2,1,-3,4,5,6};
	int n = sizeof(a)/sizeof(int);

	int* tree = new int[4*n + 1];

	buildTree(a,0,n-1,1,tree);
	// update(a,0,n-1,4,1,tree,-10);
	updateRange(a,0,n-1,2,4,1,tree,-10);
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;

		cout << minQuery(a,0,n-1,l,r,1,tree) <<endl;
	}


	return 0;
}
















