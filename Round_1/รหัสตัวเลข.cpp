#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010;

int x[N] , y[N] , z[N];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n , t;
	cin >> n >> t;
	if(t == 1){
		for(int i=0;i<n;i++) cin >> y[i];
		for(int i=0;i<n;i++){
			if(i == 0 and y[i] == n-1) x[i] = 0;
			else if(i == 0 and y[i] == n+1) x[i] = 1;
			else {
				if(y[i] == y[i-1] - 1) x[i] = 0;
				else x[i] = 1;
			}
		}
		for(int i=0;i<n;i++) cout << x[i] << "\n";
	}
	else {
		for(int i=0;i<n;i++) cin >> z[i];
		y[0] = z[0];
		for(int i=1;i<n;i++){
			if(z[i] - y[i-1] < y[i-1]) y[i];
			else y[i] = z[i] - (y[i-1]*2);
		}
		for(int i=0;i<n;i++) {
			if(i == 0 and y[i] == n-1) x[i] = 0;
			else if(i == 0 and y[i] == n+1)  x[i] = 1;
			else {
				if(y[i] == y[i-1] - 1) x[i] = 0;
				else x[i] = 1;
			}
		}
		for(int i=0;i<n;i++) cout << x[i] << "\n";
	} 
	
}