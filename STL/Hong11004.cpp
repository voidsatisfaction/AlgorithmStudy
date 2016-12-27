#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int order(int *, int, int, int);

int selMed5(int* v, int l, int r){  //요소수가 5 이하일 때 median구하기
    sort(v+l, v+r);
    return v[l+(r-l)/2];
}

int selPiv(int* v, int l, int r){   //pivot구하기
    if(r - l <= 5) return selMed5(v, l, r); //요소수 5 이하이면 selMed5
    int i;
    for(i = l; i < r; i += 5){  //5개씩 묶어서 median구해서 중앙값들을 v의 왼쪽에 몰아넣기
        int m;
        if(i + 5 > r) {
            m = selMed5(v, i, r);
            int tmp = v[i + (r-i)/2];
            v[i + (r-i)/2] = v[l + (i-l)/5];
            v[l + (i-l)/5] = tmp;
        }
        else {
            m = selMed5(v, i, i+5);
            int tmp = v[i + 2];
            v[i + 2] = v[l + (i-l)/5];
            v[l + (i-l)/5] = tmp;
        }
    }
    return order(v, l, l + (i-l)/5, (i-l)/10);
}

pair<int, int> partition(int* v, int l, int r, int pivotValue){ //v를 median을 중심으로 분할
    int* S1 = new int[r-l+1];
    int* S2 = new int[r-l+1];
    int* S3 = new int[r-l+1];
    int s1, s2, s3;
    s1 = s2 = s3 = 0;
    for(int i = l; i < r; i++){
        if(v[i] < pivotValue) S1[s1++] = v[i];
        else if(v[i] == pivotValue) S2[s2++] = v[i];
        else S3[s3++] = v[i];
    }
    
    pair<int, int> p(s1, s2);
    
    int t1, t2, t3;
    t1 = t2 = t3 = 0;
    
    for(int i = l; i < r; i++){
        if(t1 < s1) v[i] = S1[t1++];
        else if(t2 < s2) v[i] = S2[t2++];
        else v[i] = S3[t3++];
    }
    delete[] S1;
    delete[] S2;
    delete[] S3;
    return p;
}

int order(int* v, int l, int r, int K){
    int pivotValue = selPiv(v, l, r);
    if(r - 1 == l) return v[l];
    pair<int, int> p = partition(v, l, r, pivotValue);
    if(p.first >= K) return order(v, l, l+p.first, K);
    else if(p.first + p.second >= K) return pivotValue;
    else return order(v, l + p.first + p.second, r, K - (p.first + p.second));
}

int main(){
    int N, K;
    
    scanf("%d %d", &N, &K);
    int* v = new int[N];

    for(int i = 0; i < N; i++){
        scanf("%d", v+i);
    }
    
    cout << order(v, 0, N, K);
    
    delete[] v;

    return 0;
}
