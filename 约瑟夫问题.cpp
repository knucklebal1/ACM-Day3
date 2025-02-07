#include<iostream>
#include<queue>
using namespace std;
queue<int> q;

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	int count=0,first;
	while(!q.empty()){
		first=q.front();
		q.pop();
		count++;
		if(count!=m){
			q.push(first);
		}else{
			count=0;
			cout<<first<<' ';
		}
	}
	
	return 0;
}
