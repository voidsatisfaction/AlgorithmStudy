#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
4 5 1
1 2
1 3
1 4
2 4
3 4

6 8 1
1 2
1 3
2 4
2 5
4 5
4 6
5 6
6 3
*/

int nodes, //����� ����
	lines; //������ ����
vector<int> gra[1001]; //���� ����Ʈ�� ������ ���͹迭. gra[a]�� a�� �������� ��尡 ����� ����� ������ �����. gra[0]�� �ڿ������� ��
bool visited[1001] = {false};//dfs�� �湮�� ���� �����ϴ� �迭. visit[a]�� �湮 �ߴٸ� true, �ƴϸ� false;

void dfs(int here){
	visited[here] = true;
	cout<<here<<" ";

	for(int i=0;i<gra[here].size();i++){
		int next=gra[here][i];
		if(!visited[next]){
			dfs(next);
		}
	}
};

void bfs(int start){
	int* q = new int[nodes+1];
	int head=0,tail=0;

	visited[start] = true;
	q[tail++] = start;
	while(head<tail){
		for(int i=head;i<tail;i++){
			for(int j=0; j<gra[i+1].size();j++){
				if(!(visited[gra[i+1][j]])){
					visited[gra[i+1][j]] = true;
					q[tail++]=gra[i+1][j];
				}
			}
			cout<<q[head++]<<" ";
		}
	}

	delete[] q;
};

int main(){
	int start;//Ž���� �����ϴ� ���

	scanf("%d%d%d", &nodes,&lines,&start);

	//��������Ʈ ����
    for (int i = 0; i<lines; i++) { 
        int node1, node2;
        scanf("%d %d", &node1, &node2);
		if(find(gra[node1].begin(), gra[node1].end(), node2) == gra[node1].end()){ //�ߺ��� ������ �ԷµǾ����� �̸� �Ÿ��� ���ǽ�
			gra[node1].push_back(node2); 
			gra[node2].push_back(node1);
		}
	}

	//���� ����Ʈ ���� üũ
	//for(int i=0;i<=nodes;i++){
	//	vector<int>::iterator a;
	//	cout<<"gra["<<i<<"] �� ����: ";
	//	for(a = gra[i].begin() ; a != gra[i].end() ; ++a){
	//		cout<<*a<<" ";
	//	}
	//	cout<<endl;
	//}

	dfs(start);

	cout<<endl;

	for(int i=0;i<=nodes;i++){
		if(visited[i] ==true) visited[i] = false;
	}

	bfs(start);

	return 0;
}