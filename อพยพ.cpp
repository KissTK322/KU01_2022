#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010;

int x[N] , y[N] , z[N];
char land[1010][1010];
int mark[1010][1010] , ch[1010][1010];
int di[] = {-1,1,0,0} , dj[] = {0,0,1,-1};
int row , col , si , sj , ei , ej , L , fnd = 0;

void play(int i , int j){
	mark[i][j] = 1;
	if(i == ei && j == ej && !fnd) {
		fnd = 1;
		return;
	}
	for(int k=0;k<4 && !fnd ;k++){
		int ii = i + di[k] , jj = j + dj[k];
		if(mark[ii][jj] == 1 || ch[ii][jj] == 1) continue;
		if(ii <= 0 || jj <= 0 || ii > row || jj > col || ii < si - L || ii > si + L) continue;
		play(ii,jj);
	}
	return;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int q; cin >> row >> col >> q;
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			cin >> land[i][j];
		}
	}
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			if(land[i][j] == '#') ch[i][j] = 1;
			else ch[i][j] = 0;
		}
	}
	while(q--){
		memset(mark,0,sizeof(mark));
		memset(land,0,sizeof(land));
		fnd = 0;
		cin >> si >> sj >> ei >> ej >> L;
		if(ei > si + L || ei < si - L) cout << "0\n";
		else {
			play(si , sj);
			cout << fnd << "\n";
		}
	}
}