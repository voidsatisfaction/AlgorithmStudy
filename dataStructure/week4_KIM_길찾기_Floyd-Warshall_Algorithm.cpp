#include <cstdio>
#include <algorithm>
#define MAX 1000000
using namespace std;
int N, M, X, from, to, cost, A[1000][1000], answer = 0;
int main(){
	scanf("%d %d %d\n",&N,&M,&X);
	X--;
	for(int i = 0;i < N;i++){
    fill_n(A[i], N, MAX);
		A[i][i] = 0;
	};
	while(M--){
		scanf("%d %d %d\n",&from,&to,&cost);
		from--, to--;
		A[from][to] = cost;
	};
  /*
  Floyd-Warshall Algorithm
  */
	for(int k = 0;k < N;k++){
    for(int i = 0;i < N;i++){
      if(i != k && A[i][k] != MAX){
        for(int j = 0;j < N;j++){
          A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
        };
      };
    };
  };
	for(int i = 0;i < N;i++){
    answer = max(answer, A[i][X] + A[X][i]);
  };
	printf("%d", answer);
}
