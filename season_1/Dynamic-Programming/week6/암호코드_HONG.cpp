#include <iostream>
#include <vector>
 
using namespace std;
 
 
int main(){
    string str;
    cin >> str;
    vector<int> dp(str.size());
     
    for(int i = 0; i < str.size(); i++){
        if(i == 0)
            dp[i] = 1;
        else if(i == 1){
            if((str[i] != '0' && str[i] <= '6' && str[i-1] == '2') || (str[i] != '0' && str[i-1] == '1')){
                dp[i] = 2;
            } else
                dp[i] = dp[i-1];
        } else{
            if((str[i] != '0' && str[i] <= '6' && str[i-1] == '2') || (str[i] != '0' && str[i-1] == '1')){
                dp[i] = dp[i-2] + dp[i-1];
            } else if(str[i] == '0'){
                dp[i] = dp[i-2];
            } else{
                dp[i] = dp[i-1];
            }
        }
        dp[i] %= 1000000;
    }
     
    cout << dp[str.size()-1] << endl;
}
