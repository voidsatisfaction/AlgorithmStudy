#include <cstdio>
#include <map>
using namespace std;
int main(){
    int c,t;
    scanf("%d",&c);
    map<int, int> m;
    for(int i=0;i<c;i++){
        scanf("%d",&t);
        m[t]++;
    }
    for(map<int,int>::iterator it=m.begin();it != m.end();it++){
        for(int j=0;j<it->second;j++){
            printf("%d\n",it->first);
        }
    }
    return 0;
}
