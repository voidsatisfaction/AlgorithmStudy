#include <cstdio>
#include <algorithm>
using namespace std;
int stair[300],costarray[300];
int cost(int n);
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&stair[i]);
    }
    printf("%d",cost(num));
    return 0;
     
}
int cost(int n){
    int temp;
    if(costarray[n-1] !=0){
        temp = costarray[n-1];
    }else{
        if(n==0){
            temp = 0;
        }else if(n==1){
            temp = stair[0];
        }else if(n==2){
            temp = stair[0]+ stair[1];
        }else if(n>2){
            temp = max(cost(n-2),cost(n-3)+stair[n-2])+stair[n-1];
        }
        costarray[n-1] = temp;
    }
    return temp;
}
