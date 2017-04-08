#include <iostream>
#include <algorithm>

using namespace std;

//전역변수
int n = 0;
int A[2000] = {0},
	B[2000] = {0},
	dpArr[2000][2000]; // dp[i][j] : A[i]와 B[j]가 뒤집혀있을때 앞으로 얻을수 있는 최대 점수

//함수
int dp(int i, int j);

int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n;i++){
		cin>>B[i];
	}

	//일단 모두 -1로 초기화
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			dpArr[i][j] = -1;
		}
	}

	cout<<dp(0,0);

	return 0;
}

int dp(int i, int j){//dpArr[i][j]를 구하는 함수
	if(dpArr[i][j] != -1){
		return dpArr[i][j];
	}

	if(A[i] > B[j]){
		if(j == n-1){ // B를 버리고 더이상 못버리니 끝낸다
			dpArr[i][j] = B[j];
		}else{ // B를 버리고 다음 결정을 준비한다
			dpArr[i][j] = dp(i, j+1) + B[j];
		}
	}else{
		if(i == n-1){ //더이상 A를 버릴수 없어서 0
			dpArr[i][j] = 0;
		}else if(j == n-1){  //지금은 B를 버릴수 없지만 A를 넘기다보면 B를 버릴수 있을수도 있다
			dpArr[i][j] = dp(i+1, j);
		}else{ //왼쪽만 버리던가 왼,오를 다 버리던가
			dpArr[i][j] = max(dp(i+1, j),dp(i+1, j+1));
		}
	}

	return dpArr[i][j];
}
