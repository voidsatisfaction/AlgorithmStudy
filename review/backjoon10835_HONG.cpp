#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    
    vector<vector<int>> tab(n+1);
    for(int i = 0; i <= n; i++){
        tab[i].assign(n+1, 0);
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    
    for(int i = 0; i <= n; i++){
        tab[i][n] = 0;
        tab[n][i] = 0;
    }
    
    for(int j = n-1; j >= 0; j--){
        for(int i = n-1; i >= 0; i--){
            tab[i][j] = a[i] > b[j] ? (b[j]+tab[i][j+1]) : max(tab[i+1][j], tab[i+1][j+1]);
        }
    }
    
    
    printf("%d\n", tab[0][0]);

    return 0;
}
