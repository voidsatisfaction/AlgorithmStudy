#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int num,k;
    scanf("%d %d",&num,&k);
    vector<int> vec(num);
    for(int i=0;i<num;i++){
        scanf("%d",&vec[i]);
    }
    nth_element(vec.begin(),vec.begin()+k-1,vec.end());
    printf("%d",vec[k-1]);
    return 0;
}
