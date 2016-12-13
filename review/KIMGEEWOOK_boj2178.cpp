#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  int map[102][102] = {{0}};
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      do{
        map[i][j] = getchar() - '0';
      }while(map[i][j] == -38);
    };
  };
  queue < pair< int, int > > q;
  int distance = 1, x, y;
  q.push(make_pair(1,1));
  q.push(make_pair(0,0));//layer level up
  map[1][1] = 0;
  while(!q.empty()){
    x = q.front().first;
    if(!x){
      q.pop();
      q.push(make_pair(0,0));//layer level up
      distance++;
      continue;
    };
    y = q.front().second;
    q.pop();
    if(map[y+1][x]){
      if((y+1) == n && x == m){
        distance++;
        break;
      };
      q.push(make_pair(x,y+1));
      map[y+1][x] = 0;
    }
    if(map[y][x+1]){
      if(y == n && (x+1) == m){
        distance++;
        break;
      };
      q.push(make_pair(x+1,y));
      map[y][x+1] = 0;
    }
    if(map[y-1][x]){
      if((y-1) == n && x == m){
        distance++;
        break;
      };
      q.push(make_pair(x,y-1));
      map[y-1][x] = 0;
    }
    if(map[y][x-1]){
      if(y == n && (x-1) == m){
        distance++;
        break;
      };
      q.push(make_pair(x-1,y));
      map[y][x-1] = 0;
    }
  };
  printf("%d\n",distance);
  return 0;
}
