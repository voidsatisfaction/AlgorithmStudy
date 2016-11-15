#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int sum[301] = {0,};//A[n]:n칸 까지 갔을때 최대 점수 
	int pt[300] = {0,};//pt[n]: n+1번째 칸의 점수
	int n;//계단의 총 단수

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>pt[i];
	}
	//sum[0] = 0 으로 초기화 되어있음
	sum[1] = pt[0];
	sum[2] = pt[0] + pt[1];

	for(int i=3;i<n+1;i++){//sum[3]부터 sum[n]까지를 채운다
		sum[i] = max(sum[i-2]+pt[i-1],sum[i-3]+pt[i-2]+pt[i-1]);
	}

	cout<<sum[n];
	return 0;
}