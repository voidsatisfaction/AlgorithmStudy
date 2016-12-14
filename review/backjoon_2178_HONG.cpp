#include <iostream>

using namespace std;

void dp(int (*tab)[101], int (*map)[101], int i, int j, int n, int m){
    if(j < m && ((tab[i][j+1] == 0 && map[i][j+1] == 1) || (tab[i][j+1] > tab[i][j]+1))){
        tab[i][j+1] = tab[i][j]+1;
        dp(tab, map, i, j+1, n, m);
    }
    
    if(j > 0 && ((tab[i][j-1] == 0 && map[i][j-1] == 1) || (tab[i][j-1] > tab[i][j]+1))){
        tab[i][j-1] = tab[i][j]+1;
        dp(tab, map, i, j-1, n, m);
    }
    if(i < n && ((tab[i+1][j] == 0 && map[i+1][j] == 1) || (tab[i+1][j] > tab[i][j]+1))){
        tab[i+1][j] = tab[i][j]+1;
        dp(tab, map, i+1, j, n, m);
    }
    if(i >= 0 && ((tab[i-1][j] == 0 && map[i-1][j] == 1) || (tab[i-1][j] > tab[i][j]+1))){
        tab[i-1][j] = tab[i][j]+1;
        dp(tab, map, i-1, j, n, m);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    int map[101][101];
    int tab[101][101];
    
    for(int i = 0; i <= n; i++) {
        map[i][0] = 0;
        if(i != 0){
            for(int j = 1; j <= m; j++){
                char c;
                do{
                    c = getchar();
                }while(c < '0' || c > '9');
                map[i][j] = c - '0';
            }
        } else{
            for(int j = 0; j <= m; j++) map[i][j] = 0;
        }
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++) tab[i][j] = 0;
    }
    
    tab[1][1] = map[1][1];
    
    dp(tab, map, 1, 1, n, m);
    printf("%d\n", tab[n][m]);
    
    return 0;
}
