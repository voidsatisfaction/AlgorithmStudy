#include <iostream>
#include <vector>

using namespace std;

int calc(int n, unsigned long long c, vector<unsigned long long>& wt, vector<unsigned long long>& val){
	return 0;
}

int main(void){
	int n;
	unsigned long long c,tempwt,tempval;
	vector<unsigned long long> wt;
	vector<unsigned long long> val;

	cin>>n;

	for(int i=0; i<n; i++){
		cin>>tempwt>>tempval;
		wt.push_back(tempwt);
		val.push_back(tempval);
	}
	wt.resize(n);
	val.resize(n);

	cin>>c;

	cout<<calc(n,c,wt,val);
	return 0;
}