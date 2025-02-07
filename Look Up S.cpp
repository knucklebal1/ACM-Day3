#include<iostream>
#include<stack>
using namespace std;
const int maxN=1e5+5;
int H[maxN],ans[maxN];

int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>H[i];
	}
	stack<int> s;
	for(int i=N;i>=1;--i){//倒序循环：由于要找向右（向后）的仰望对象，所以用倒序先处理最后一个元素，（如果要找向左的，可以用顺序）；栈存储的是元素下标；保证栈顶的元素为当前元素向右的仰望对象；如果栈为空，则说明当前元素无仰望对象（后面的都更矮）
		while(!s.empty()&&H[s.top()]<=H[i]){
			s.pop();
		}
		if(s.empty()){
			ans[i]=0;
		}else{
			ans[i]=s.top();
		}
		s.push(i);
	}
	for(int i=1;i<=N;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}
