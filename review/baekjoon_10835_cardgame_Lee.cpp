#include <iostream>
#include <algorithm>

using namespace std;

//전역변수
int n = 0;
int A[2000] = {0},
	B[2000] = {0},
	dpArr[2000][2000] ;

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

	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			dpArr[i][j] = -1;
		}
	}

	cout<<dp(0,0);

	return 0;
}

int dp(int i, int j){
	if(dpArr[i][j] != -1){
		return dpArr[i][j];
	}

	if(A[i] > B[j]){
		if(j == n-1){
			dpArr[i][j] = B[j];
		}else{
			dpArr[i][j] = dp(i, j+1) + B[j];
		}
	}else{
		if(i == n-1){
			dpArr[i][j] = 0;
		}else if(j == n-1){
			dpArr[i][j] = dp(i+1, j);
		}else{
			dpArr[i][j] = max(dp(i+1, j),dp(i+1, j+1));
		}
	}

	return dpArr[i][j];
}
