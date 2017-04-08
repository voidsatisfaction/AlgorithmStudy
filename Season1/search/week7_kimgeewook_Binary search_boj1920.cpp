#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> d;
void search(int from,int to, int el){
	if(from == to){
		if(d[from] == el){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}else{
		int mid = (from + to)/2;
		if(d[mid] == el){
			printf("1\n");
		}else if(d[mid] > el){
			search(from,mid,el);
		}else{
			search(mid + 1,to,el);
		}
	}
};
int main(){
	scanf(" %d",&n);
	int el;
	for(int i = 1;i <= n;i++){
		scanf(" %d",&el);
		d.push_back(el);
	};
	sort(d.begin(),d.end());
	int m;
	scanf(" %d",&m);
	for(int i = 1;i <= m;i++){
		scanf(" %d",&el);
		search(0,n - 1,el);
	};
};