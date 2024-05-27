#include <bits/stdc++.h> 
using namespace std; 

int maximize(vector<int>& a,  int x, int y, int z) 
{ 
	 
	int n=a.size(); 
	vector<int> L(n);
	L[0] = x * a[0]; 
	for (int i = 1; i < n; i++) 
		L[i] = max(L[i - 1], x * a[i]); 


	vector<int> R(n); 
	R[n-1] = z * a[n-1]; 
	for (int i = n - 2; i >= 0; i--) 
		R[i] = max(R[i + 1], z * a[i]); 

	
	int ans = INT_MIN; 
	for (int i = 0; i < n; i++) 
		ans = max(ans, L[i] + y * a[i] + R[i]); 

	return ans; 
} 
int main() 
{ int n;
cin>>n;
vector<int> a(n) ;
for(int i=0;i<n;i++)
 cin>>a[i];

int x,y,z;
cin>>x>>y>>z;
cout << maximize(a, x, y, z) << endl; 
return 0; 
} 
