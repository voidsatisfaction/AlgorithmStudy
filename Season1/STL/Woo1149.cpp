#include <cstdio>
#include <algorithm>
int ary[1000][3];
using namespace std;
int main(){
    int num,r,g,b;
    scanf("%d",&num);
    scanf("%d %d %d",&ary[0][0],&ary[0][1],&ary[0][2]);
    for(int i = 1;i<num;i++){
        scanf("%d %d %d",&r,&g,&b);
        ary[i][0] = min(ary[i-1][1],ary[i-1][2])+r;
        ary[i][1] = min(ary[i-1][0],ary[i-1][2])+g;
        ary[i][2] = min(ary[i-1][0],ary[i-1][1])+b;
    }
    printf("%d",min(min(ary[num-1][0],ary[num-1][1]),ary[num-1][2]));
    return 0;
}
