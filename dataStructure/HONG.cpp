//
//  main.cpp
//  week2
//
//  Created by ymmtlab initialize on 10/14/16.
//  Copyright © 2016 ymmtlab initialize. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>



using namespace std;


class AlieanAndHamburgers{
private:
    int typeSum;
    int tasteSum;
    int Max;
public:
    set<int> setType;
    vector<int> orderedNTaste;
    vector<int> orderedType;
    
    void setMax(int max){
        Max = max;
    }
    
    inline bool set_has(int a){
        return (setType.find(a) != setType.end());
    }
    
    int getNumber(int type[], int taste[]){
        for (int i = 0; i < Max; i++){
            if(taste[i] >= 0){              //양수이면 다 더하기
                setType.insert(type[i]);
                tasteSum+=taste[i];
            }
            else {          //음수이면 orderedNTaste에 저장
                if(orderedNTaste.empty() || orderedNTaste.back() > taste[i]){
                    orderedNTaste.push_back(taste[i]);
                    orderedType.push_back(type[i]);
                }
                else {
                    int ind;
                    for(ind = 0; orderedNTaste[ind] > taste[i]; ind++){}
                    orderedNTaste.insert(orderedNTaste.begin()+ind, taste[i]);
                    orderedType.insert(orderedType.begin()+ind, type[i]);
                }
            }
        }

        for(int i = 0; i < orderedNTaste.size(); i++){      //음수를 추가해도 되는지 확인하면서 추가
            if(!set_has(orderedType[i])){
                if((tasteSum+orderedNTaste[i])*((int)setType.size()+1) > tasteSum*(int)setType.size()){
                    tasteSum += orderedNTaste[i];
                    typeSum++;
                    setType.insert(orderedType[i]);
                }
            }
        }
        
        for(int i : setType) cout << i << endl;
        return tasteSum*(int)setType.size();
    }
    
    AlieanAndHamburgers(){
        typeSum = 0;
        tasteSum = 0;
    }
};

int main(int argc, const char * argv[]) {
    int type[50];
    int taste[50];
    
    string in1, in2;
    string tmp;
    AlieanAndHamburgers a;
    
    getline(cin, in1);
    getline(cin, in2);
    
    int i = 0;
    for(char a : in1) {
        if (('0' <= a && a <= '9') || a == '-') {
            tmp.push_back(a);
        } else if(a == ',' || a == '}') {
            type[i++] = stoi(tmp);
            tmp.clear();
        }
    }
    
    a.setMax(i);
    
    i = 0;
    for(char a : in2) {
        if (('0' <= a && a <= '9') || a == '-') {
            tmp.push_back(a);
        } else if(a == ',' || a == '}') {
            taste[i++] = stoi(tmp);
            tmp.clear();
        }
    }
    
    int r = a.getNumber(type, taste);
    cout << r << endl;
    

    return 0;
}
