#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n, dp[1000][3]={{0}};
	scanf("%d",&n);
	scanf(" %d %d %d",&dp[0][0],&dp[0][1],&dp[0][2]);
	for(int i = 1; i < n; i++){
		scanf(" %d %d %d",&dp[i][0],&dp[i][1],&dp[i][2]);
		dp[i][0] += min(dp[i-1][1],dp[i-1][2]);
		dp[i][1] += min(dp[i-1][0],dp[i-1][2]);
		dp[i][2] += min(dp[i-1][0],dp[i-1][1]);
	}
	printf("%d\n",min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]));
}
