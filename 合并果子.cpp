#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q;
int main(){
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		q.push(x);
	}
	int sum=0;
	int a,b;
	while(q.size()>1){
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
		sum+=a+b;
		q.push(a+b);
	}
	cout<<sum<<endl;
	
	return 0;
}
