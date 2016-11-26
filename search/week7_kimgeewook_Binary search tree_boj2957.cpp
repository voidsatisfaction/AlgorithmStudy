#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main(){
  int n,el,root;
  long long int c = 0, val = 0;
  map<int,long long int> tree;
  scanf("%d",&n);
  while(n--){
    int right = 0, left = 0;
    scanf("%d",&el);
    tree[el] = 0;
    if(tree.size()==1){ 
      root = el;
      printf("%d\n",0);
    }else{
      map<int,long long int>::iterator it = tree.find(el);
      map<int,long long int>::iterator it2 = it;
      if(el>root){
        if(++it != tree.end()){
          right = it->second;
        };
        left = (--it2)->second;
      }else{
        right = (++it)->second;
        if(it2 != tree.begin()){
          left = (--it2)->second;
        };
      }
      val = max(right,left) + 1;
      tree[el] = val;
      c += val;
      printf("%lld\n",c);
    }
  }
} 