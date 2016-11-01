#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Node;
class Edge;

class Edge{
public:
    Node* to;
    int time;
};

class Node{
public:
    int num;
    int tmpTime = 0;
    bool empty = true;
    vector<Edge> edge;
    
    void clearNode(){
        tmpTime = 0;
        empty = true;
    }
};

void clearGraph(Node* list, int N);
void bfs(Node*, set<int>);


void clearGraph(Node* list, int N){
    for(int i = 0; i < N; i++){
        list[i].clearNode();
    }
}

set<int> forward(Node* list, int s){
    set<int> next;
    for(int i = 0; i < list[s].edge.size(); i++){
        if(list[s].edge[i].to->tmpTime == 0){
            list[s].edge[i].to->tmpTime = list[s].edge[i].time + list[s].tmpTime;
            next.insert(list[s].edge[i].to->num);
        } else{
            if(list[s].edge[i].to->tmpTime > list[s].edge[i].time + list[s].tmpTime){
                next.insert(list[s].edge[i].to->num);
                list[s].edge[i].to->tmpTime = list[s].edge[i].time + list[s].tmpTime;
            }
        }
    }
    return next;
}

void dijkstra(Node* list, int s){
    set<int> present;
    present.insert(s);
    
    bfs(list, present);
}

void bfs(Node* list, set<int> present){
    set<int> next;
    for(int s : present){
        list[s].empty = false;
        
        set<int> tmp = forward(list, s);
        for(int n : tmp){
            next.insert(n);
        }
    }
    
    if (!next.empty())
        bfs(list, next);
}

int main(int argc, const char * argv[]) {
    int N, M, X;
    
    cin >> N;
    cin >> M;
    cin >> X;
    X--;
    
    Node* list = new Node[N];
    int* timeList = new int[N];
    int maxTime = 0;
    
    for(int i = 0; i < N; i++){
        list[i].num = i;
    }
    
    for(int i = 0; i < M; i++){
        int a, b, t;
        cin >> a;
        a--;
        cin >> b;
        b--;
        cin >> t;
        
        Edge e;
        e.to = &list[b];
        e.time = t;
        list[a].edge.push_back(e);
    }
    
    for(int i = 0; i < N; i++){
        if(i != X){
            clearGraph(list, N);
            dijkstra(list, i);
            timeList[i] = list[X].tmpTime;
        }
    }
    
    clearGraph(list, N);
    dijkstra(list, X);
    
    
    for(int i = 0; i < N; i++){
        if(i != X){
            timeList[i] += list[i].tmpTime;
            if(maxTime < timeList[i]) maxTime = timeList[i];
        }
    }
    
    cout << maxTime << endl;
    
    delete[] timeList;
    delete[] list;
    
    return 0;
}

