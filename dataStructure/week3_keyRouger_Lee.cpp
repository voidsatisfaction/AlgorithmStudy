#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define CASES 2 // �׽�Ʈ ���̽��� ����

string decode(string* strx);
void inputTst(vector<string>& testcase);

int main(){

	//�̸� �ڵ忡�� testcase�� �Է¹޴� ���
	//string testcase[CASES];
	//testcase[0] = "<<BP<A>>Cd-"; //BPAC
	//testcase[1] = "<><><><><><><><dd-f-ggg-<<<34"; //34dgg

	//string password[CASES]; // �׽�Ʈ���̽��� �����ؼ� ����ִ� ���ڿ��� �迭

	//for(int i=0; i<CASES; i++){
	//	password[i] = decode(&testcase[i]);//testcase[i]�� �ؼ��ؼ� password[i]�� ����ִ´�
	//	cout<<"testcase["<<i<<"] :"<<testcase[i]<<endl;
	//	cout<<"password["<<i<<"] :"<<password[i]<<endl;
	//}
	vector<string> testcase;
	inputTst(testcase);//cases�� ����

	for(int i = 0; i<(int)testcase.size(); i++){
		cout<<"testcase["<<i<<"] : "<<testcase[i]<<endl;
		cout<<"password : "<<decode(&testcase[i])<<endl;
	}
}

void inputTst(vector<string>& testcase){
	cout<<"Input only A BLANK(space) to end input process"<<endl<<endl;
	while(1){
		string temp;
		getline(cin, temp); //���ڿ��� �Է¹޴� ���.
		if(temp == " ") break;
		testcase.push_back(temp);
	}
}

string decode(string* str){ //str�� �ùٸ� ���·� �ٲپ� �����Ѵ�

	//cout<<str<<endl; str�� ����� �޸��ּ�
	//cout<<*str<<endl; str�� ��
	//cout<<*str[0]<<endl; str�� ù��°��(str�� ���ڷ� �̷���� �迭�̹Ƿ�) ??���� ������ �߸��Ǿ����ϴ�??

	int corsor = 0; //Ŀ���� ��ġ. �ǿ����� 0. n��° ������ �������� n��° Ŀ��
	string result; //���� ���� �ؼ��� str
	string a = *str;

	for(unsigned int i=0;i<a.length();i++){
		switch(a[i]){
		case 60 : // < == 60
			if(corsor != 0){
				corsor--;
			}
			break;
		case 62 : // > == 62 
			if(corsor != result.length()){
				corsor++;
			}
			break;
		case 45 : // - == 45
			if(corsor != 0){
				result.erase(corsor-1,1);
				corsor--;
			}
			break;
		default : // �׿��� ����
			string temp = a.substr(i,1);//insert�Լ��� ���ڿ��� �޴´�
			result.insert(corsor, temp);
			corsor++;
			break;
		}
	}
	return result;
}

