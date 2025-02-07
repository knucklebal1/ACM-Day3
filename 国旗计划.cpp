#include <iostream>
#include <algorithm>
using namespace std;

const int maxN=2e5+5;
int n,m,ans[maxN],f[maxN*2][20];
struct node{
	int id;
	int l,r;
}s[maxN*2];

bool cmp(node a,node b){
	return a.l<b.l;
}

void pre(){
	for(int i=1,p=1;i<=n*2;i++){
		while(p<=n*2&&s[p].l<=s[i].r){
			p++;
		}
		f[i][0]=p-1;
	}
	for(int i=1; i < 20; i++){
		for (int j=1;j<=n*2;j++) {
			if(f[j][i-1]<=n*2){
				f[j][i]=f[f[j][i-1]][i-1];
			} else {
				f[j][i]=n*2;
			}
		}
	}
}
void solve(int k){
	int rr=s[k].l+m;
	int total=1;
	int p=k;
	for (int i=19; i>=0; i--){
		if (f[k][i]!=0&&s[f[k][i]].r<rr){
			total+=(1 << i);
			k=f[k][i];
		}
	}
	ans[s[p].id]=total+1;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s[i].l>>s[i].r;
		if (s[i].r<s[i].l){
			s[i].r+=m; 
		}
		s[i].id=i;
	}
	sort(s+1,s+1+n,cmp);
	for (int i=1;i<=n;i++){
		s[i+n]=s[i];
		s[i+n].l=s[i].l+m;
		s[i+n].r=s[i].r+m;
	}
	pre();
	for (int i=1;i<=n;i++){
		solve(i);
	}
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

