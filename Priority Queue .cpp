#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
	priority_queue<int> S;
	string op;
	int k;
	
	while(cin>>op){
		if(op=="insert"){
			cin>>k;
			S.push(k);
		}else if(op=="extract"){
			cout<<S.top()<<endl;
			S.pop();
		}else if(op=="end"){
			break;
		}
	}
	return 0;
}
