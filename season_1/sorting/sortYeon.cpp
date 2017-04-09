#include <iostream>

using namespace std;

int countSubstrings(string s)
{
  int sum = 0;
  int l = s.size();
  for(int i=0; i<l; i++) {
    int n = 0;
    int w = 0;
    for(int j=i; j<l; j++){
      int val = (s[j] == '1');
      n += val;
      w += val*(j-i);
      if(w == 0 || (w % n) == 0){
        ++sum;
      }
    }
  }
  return sum;
}

int main()
{
  cout << "Input string composed of only 1 and 0" << endl;
  string input;
  
  cin >> input;
  cout << countSubstrings(input) << endl;
}