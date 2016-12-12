#include <iostream>
#include <queue>

using namespace std;

int mage[100][100] = {{0}},
	width = 0,
	height = 0,
	answer = 0;
queue<int> que; //����� int�� 100���� ���� ���� i, �������� j����ϸ�, �̴� mage[i][j]�� �ǹ��Ѵ�

int main(void){

	cin>>height>>width;

	for(int i =0;i<height;i++){
		for(int j=0;j<width;j++){
			do{
				mage[i][j] = getchar() - '0';
			}while(mage[i][j] == -38);
		}
	}

	//�ϴ� ť�� mage[0][0]�� ����ֱ�. �����δ� (0*100 + 0) = 0�� ���·� ����ִ´�
	que.push(0);
	mage[0][0] = 0;

	bool breakloop = false; //true�� �Ǹ� �Ʒ��� while�� ���̻� ���� �ʴ´� 
	while(!(que.empty()) && (!breakloop)){ //que�� �������� bfs OR ���������� ����������
		answer ++;
		int qsize = que.size();

		for(int i=0; i<qsize; i++){
			int y = que.front() / 100,
				x = que.front() % 100;

			if((y == height -1)&&(x == width-1)){
				breakloop = true;
				break;
			}
			//���� üũ
				if((y>0)&&(mage[y-1][x] ==1)){
					que.push((y-1)*100 + x);
					mage[y-1][x] = 0;
				}
			//�Ʒ��� üũ
				if((y<height-1)&&(mage[y+1][x] ==1)){
					que.push((y+1)*100 + x);
					mage[y+1][x] = 0;
				}
			//������ üũ
				if((x>0)&&(mage[y][x-1] ==1)){
					que.push(y*100 + (x-1));
					mage[y][x-1] = 0;
				}
			//�������� üũ
				if((x<width-1)&&(mage[y][x+1] ==1)){
					que.push(y*100 + (x+1));
					mage[y][x+1] = 0;				
				}
			que.pop();
		}
	}

	cout<<answer;

	return 0;
}
