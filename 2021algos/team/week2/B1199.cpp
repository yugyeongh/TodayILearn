// 오일러 회로
// : 그래프의 모든 간선을 한번만 통과해서 시작점으로 돌아오는 사이클 like 한붓그리기

// 오일러 회로의 조건
// 1. 그래프가 단 하나의 컴포넌트로 구성되어야 함
// 2. 모든 정점의 차수는 짝수가 되어야 함

// 오일러 회로 알고리즘
// 1. 아무 정점 v를 뽑고 v에서 출발해 v로 돌아오는 경로를 하나 뽑는다.
// 2. 이때 방문되지 못한 간선이 있는 정점 u가 존재하면, u에서 시작해 아직 쓰이지 않은 간선들만 u로 돌아오는 경로를 찾아 원래 경로에 끼워넣는다...?

#include <iostream>
using namespace std;

int N;
int graph[1001][1001];

void dfs(int node){
    for (int i=1;i<=N;i++){
        if (graph[node][i]>0){
            graph[node][i]--;
            graph[i][node]--;
            dfs(i);
        }
    }
    cout << node << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    /* 입력 && 정점의 차수 계산하기 */
    cin >> N;
   
    int start=0;
    for (int i=1;i<=N;i++){
        int cnt=0;
        for (int j=1;j<=N;j++){
            cin >> graph[i][j];
            cnt+=graph[i][j];
        }
        /* 오일러 회로 조건을 만족하는지 확인 */
        if (cnt%2==1){
            cout << -1;
            return 0;
        }
        if (start==0 && cnt>0) start=i;
    }
    dfs(start);
    cout << '\n';
    return 0;
}
