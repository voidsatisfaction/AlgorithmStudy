#include <list>
#include <cstdio>

using namespace std;

int main(){
  int n;
  scanf("%d\n", &n);
  list<char> lst;
  list<char>::iterator itr;

  while(n--)
  {
    lst.clear();
    itr = lst.begin();
    char c;
    while((c = getchar()) != '\n')
    {
      switch(c)
      {
        case '<':
          if(itr != lst.begin())
            --itr;
          break;
        case '>':
          if(itr != lst.end())
            ++itr;
          break;
        case '-':
          if(itr != lst.begin())
            itr = lst.erase(--itr);
          break;
        default:
            itr = ++lst.insert(itr,c);
            break;
      }
    }
    for(itr = lst.begin(); itr != lst.end(); itr++)
      printf("%c",*itr);
    
    printf("\n");
  }
  return 0;
}