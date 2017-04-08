#include<cstdio>
#include<list>
using namespace std;
int main (){
  int num;
  scanf("%d\n", &num);
  list<char> vec;
  list<char>::iterator it;
  while(num--){
    vec.clear();
    it = vec.begin();
    char c;
    while((c = getchar()) != '\n'){
      switch (c) {
				case '<':
          if (it != vec.begin()) it--;
					break;
				case '>':
          if (it != vec.end()) it++;
					break;
				case '-':
          if (it != vec.begin()) it = vec.erase(--it);
					break;
				default:
          it = ++vec.insert(it, c);
      };
    };
    for(it = vec.begin();it != vec.end();it++){
      printf("%c",*it);
    }
    printf("\n");
  };
  return 0;
};