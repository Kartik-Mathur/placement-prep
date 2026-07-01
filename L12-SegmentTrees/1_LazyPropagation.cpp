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

int minQuery(int s,int e,int qs,int qe, int index, int* tree,
	int *lazy){
	
	if(lazy[index] != 0){
		tree[index] += lazy[index];

		if(s != e){ // s == e means leaf node
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}

		lazy[index] = 0;
	}

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
	int left = minQuery(s,mid,qs,qe,2*index,tree, lazy);
	int right = minQuery(mid+1,e,qs,qe,2*index+1,tree, lazy);
	
	return min(left,right);

}

void updateLazy(int s,int e,
	int qs, int qe, int val,int index,
	int *tree, int* lazy){

	if(lazy[index] != 0){

		tree[index] += lazy[index];

		if(s != e){ // s == e means leaf node
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}

		lazy[index] = 0;
	}

	if(qe < s or qs > e) return;

	if(s >= qs and e <= qe){ // complete overlap
		tree[index] += val;

		if(s != e){ // s == e means leaf node
			lazy[2*index] += val;
			lazy[2*index+1] += val;
		}

		return;
	}

	int mid = (s+e)/2;
	updateLazy(s,mid,qs,qe,val,2*index,tree, lazy);
	updateLazy(mid+1,e,qs,qe,val,2*index+1,tree, lazy);
	tree[index] = min(tree[2*index], tree[2*index+1]);
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif		 

	int a[] = {2,1,-3,4,-5,6};
	int n = sizeof(a)/sizeof(int);

	int* tree = new int[4*n + 1];
	int* lazy = new int[4*n + 1]{0};

	buildTree(a,0,n-1,1,tree);
	
	updateLazy(0,n-1,0,2,10,1,tree,lazy);
	updateLazy(0,n-1,1,4,5,1,tree,lazy);
	updateLazy(0,n-1,2,4,-6,1,tree,lazy);
	updateLazy(0,n-1,0,4,-8,1,tree,lazy);

	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout << minQuery(0,n-1,l,r,1,tree, lazy) <<endl;
	}


	return 0;
}
















