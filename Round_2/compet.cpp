#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010;

int x[N][N] , win[N];
int n , pass , L , R  , cnt = 0 , passcnt = 0;

void solve(){
	if(L == x[L][R] and R == pass and passcnt == 0) win[L] = 0 , passcnt++; 
	else if(R == x[L][R] and L == pass and passcnt == 0) win[R] = 0 , passcnt++; 
	else {
		if(x[L][R] == L) win[R] = 0;
		else win[L] = 0;
	}
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> pass;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> x[i][j];
	for(int i=1;i<=n;i++) win[i] = i;
	int t = n;
	L = 1 , R = 2;
	while(t != 1){
		cnt = 0;
 		t /= 2;
		for(int i=1;i <= t;i++){
			if(t*2 == n) {
				solve();
				L+=2 , R+=2;
			}
			else {
				cnt = 0;
				for(int i=1;i<=n;i++){
					if(win[i] >= 1 and cnt == 0) L = i , cnt++;
					else if(win[i] >= 1 and cnt == 1) R = i , cnt++;
				}
				solve();
			}
		}
	}
	for(int i=1;i<=n;i++) if(win[i] >= 1) cout << i;
	
}