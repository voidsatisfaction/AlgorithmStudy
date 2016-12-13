#include <cstdio>
#include <iostream>
#include <list>
using namespace std;
int bomb(list<char> &vec, list<char>::iterator it_s, string key);
int main(){
    string s;
    string b;
    cin >> s;
    cin >> b;
    list<char> vec;
    list<char> temp;
    
    
    for(int i=0;i<s.size();i++){
        vec.push_back(s.at(i));
    }
    for(list<char>::iterator it = vec.begin(); it !=vec.end();it++){
        if(*it == b.at(0)){
            int a = bomb(vec,it--,b);
            if(a != b.size()){
                for(int i=0;i<-a;i++){
                    it++;
                }
                it++;
            }
        }
    }
    if(vec.empty()){
        printf("FRULA");
    }else{
        for(list<char>::iterator it = vec.begin();it !=vec.end();it++){
            printf("%c",*it);
        }
    }
    return 0;
}
int bomb(list<char> &vec, list<char>::iterator it_s, string key){
    list<char>::iterator it = it_s;
    int keysize = key.size();
    for(int j=1;j<key.size();j++){
        it++;
        if(it == vec.end()){
            return -(j-1);
        }
        if(*it == key.at(j)){
            
        }else if(*it == key.at(0)){
            int b = bomb(vec,it--,key);
            if(keysize != b){
                return  b-j;
            }
            j--;
        }else{
            return -j;
        }
    }
    for(int k=0;k<key.size();k++){
        it = --vec.erase(it);
    }
    return keysize;
}
