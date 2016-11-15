#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int> point(n);
     
    vector<int> dp(n);
     
    for(int i = 0; i < n; i++){
        cin >> point[i];
    }
     
    for(int i = 0; i < n; i++){
        if(i > 2)
            dp[i] = max(dp[i-3] + point[i] + point[i-1], dp[i-2] + point[i]);
        else if(i == 2)
            dp[i] = max(point[i] + point[i-1], dp[i-2] + point[i]);
        else if(i == 1)
            dp[i] = point[i] + point[i-1];
        else
            dp[i] = point[i];
    }
     
    cout << dp[n-1] << endl;
     
    return 0;
}
