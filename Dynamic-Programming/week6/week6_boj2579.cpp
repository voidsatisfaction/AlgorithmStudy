#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int cost[301] = {0}, dp[301][2] = {{0}};
    scanf("%d",&cost[1]);
    dp[1][1] = cost[1];
    scanf("%d",&cost[2]);
    dp[2][0] = cost[2];
    dp[2][1] = cost[1] + cost[2];
    for(int i = 3;i <= n;i++){
        scanf("%d",&cost[i]);
        dp[i][0] = max(dp[i - 2][0],dp[i - 2][1]) + cost[i];
        dp[i][1] = dp[i - 1][0] + cost[i];
    };
    printf("%d",max(dp[n][0],dp[n][1]));
}
