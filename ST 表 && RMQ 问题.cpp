#include<iostream>

using namespace std;
const int maxN=1e5+5;
int smax[maxN][31],log_2[maxN];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main(){
	int N,M;
	N=read(),M=read();
	log_2[1]=0;
	for(int i=2;i<=N;i++){
		log_2[i]=log_2[i/2]+1;
	}
	for(int i=1;i<=N;i++){
		smax[i][0]=read();
	}
	for(int j=1;j<=log_2[N];j++){
		for(int i=1;i+(1<<j)-1<=N;i++){
			smax[i][j]=max(smax[i][j-1],smax[i+(1<<(j-1))][j-1]);
		}
	}
	int l,r;
	for(int i=1;i<=M;i++){
		l=read(),r=read();
		int s=log_2[r-l+1];//s就是j-1
		cout<<max(smax[l][s],smax[r-(1<<s)+1][s])<<'\n';
	}
	
	return 0;
}
