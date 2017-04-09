/*
  1. 만약, taste > 0 이면 어떤 type이던, 전부 다 먹어야 효용(joy)가 최대화 된다.
  2. taste < 0 인것 중에서 taste > 0 이 이미 존재한 type 이외의 type인 taste를 추가할 지 안할지 정한다.
    (정할때, 되도록 taste가 적게 떨어지는 것을 골라 나가야 한다.)
  3. 그 고른 햄버거를 넣었을때의 전체 효용이 그 전 상태의 전체효용보다 작아질 경우에는 이 사이클을 그만한다.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class AlienAndHamburgers{
public:
  int getNumber(vector <int> type, vector <int> taste)
  {
    int tasteSum = 0;
    int length = type.size();

    set<int> setType;
    vector<int> plusType;
    vector<int> orderedMinusType;
    vector<int> orderedMinusTaste;
    set<int> minusTypeSet;
    // taste가 양수이면 다 더한다.
    for(int i=0; i < length; i++) {
      if(taste[i] >= 0){
        setType.insert(type[i]);
        tasteSum += taste[i];
      }
    }

    // tasteSum == 0 이면 답은 0이다.
    if(tasteSum == 0) return 0;

    // taste가 음수이면 앞서 taste가 양수였던 type을 제외한 것들을 선택하는데 
    // 그 선택된 taste를 삽입정렬시킨다. (새로운 벡터에다가 삽입 정렬함)
    for(int i=0; i < length; i++) {
      if(taste[i] < 0 && !setType.count(type[i])){
        if(orderedMinusTaste.empty() || orderedMinusTaste.back() > taste[i]){
          orderedMinusTaste.push_back(taste[i]);
          orderedMinusType.push_back(type[i]);
        } else {
          int index;
          for(index=0; orderedMinusTaste[index] > taste[i]; index++){}
          orderedMinusTaste.insert(orderedMinusTaste.begin()+index, taste[i]);
          orderedMinusType.insert(orderedMinusType.begin()+index, type[i]);
        }
      }
    }

    // 가장 작은 minusTaste를 하나씩 적용하면서 totalJoy를 비교한다.
    int typeSum = setType.size();
    int totalJoy = tasteSum * typeSum;
    for(int i=0; i < orderedMinusType.size(); i++) {
      if( !minusTypeSet.count(orderedMinusType[i]) ){
        minusTypeSet.insert(orderedMinusType[i]);
        int nextTotalJoy = (tasteSum + orderedMinusTaste[i]) * (typeSum + 1);
        if(nextTotalJoy > totalJoy){
          tasteSum += orderedMinusTaste[i];
          typeSum++;
          totalJoy = nextTotalJoy;
        }
      }
    }
    return totalJoy;
  }
};

int main() {
  int ans;
  static const int arr1[] = 	{1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
  vector<int> type (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
  static const int arr2[] =  {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
  vector<int> taste (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

  AlienAndHamburgers a;

  ans = a.getNumber(type, taste);

  cout << ans << endl;
  return 0;
}