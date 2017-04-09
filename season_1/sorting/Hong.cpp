//
//  main.cpp
//  week1
//
//  Created by ymmtlab initialize on 10/8/16.
//  Copyright © 2016 ymmtlab initialize. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;


class Lever{
private:
    bool* binstr;
    int current;
    int lsum;
    int rsum;
    int ltorq;
    int rtorq;
public:
    Lever(string a);
    ~Lever();
    bool isBalStr(int i, int j);
    void setCur(int i);
};

Lever::Lever(string a){
    bool* b = new bool[a.length()];
    for(int i = 0; i < a.length(); i++){
        b[i] = a[i]-'0';
    }
    binstr = b;
    current = 0;
    lsum = 0;
    rsum = 0;
    ltorq = 0;
    rtorq = 0;
}

Lever::~Lever(){
    delete[] binstr;
}

void Lever::setCur(int i){
    lsum = 0;
    rsum = 0;
    ltorq = 0;
    rtorq = 0;
    current = i;
}



bool Lever::isBalStr(int i, int j){
    
    rtorq += (j-current)*(binstr[j]);
    
    if(current < j)
        rsum += binstr[j];
    
    while(ltorq < rtorq){   //invariance : current >= balanced point
        lsum += binstr[current];
        ltorq += lsum;
        current++;
        rsum -= binstr[current];
        rtorq -= binstr[current];
        rtorq -= rsum;
    }
    
    if(ltorq == rtorq) return true;
    else return false;
}

int main(int argc, const char * argv[]) {
    
    
    string a;
    
    cin >> a;
    
    Lever lever(a);
    
    int total = 0;
    int len = (int)a.length();
    
    for(int i = 0; i < len; i++){
        lever.setCur(i);
        for(int j = i; j < len; j++){
            if(lever.isBalStr(i, j)) total++;
        }
    }
    
    cout << total << endl;
    return 0;
}
