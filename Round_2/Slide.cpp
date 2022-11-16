#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010;

int x[N] , y[N] , z[N];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n , cnt = 0;
	cin >> n;
	for(int i=0;i<n;i++) cin >> x[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(x[j] > x[i]) cnt++;
		}
	}
	cout << cnt;
	
}