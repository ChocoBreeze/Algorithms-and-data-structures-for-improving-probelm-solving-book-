// 재귀로 DFS 구현
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 깊이 우선 탐색
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v는 이미 방문했음으로 처리

    // v에서 갈 수 있는 각 꼭짓점 nex_v에 대해서
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v가 이미 탐색한 곳이면 건너뜀
        dfs(G, next_v); // 재귀적으로 탐색
    }
}

int main() {
    // 꼭짓점 개수와 변 개수
    int N, M;
    cin >> N >> M;

    // 그래프 입력(유향 그래프라고 가정)
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    
    // DFS는 모든 꼭짓점을 탐색할 수 있다는 보장이 불가능하기 때문에
    // for 반복문을 통해 아직 방문하지 않은 꼭짓점이 없어질 때까지 dfs를 호출함.
    // 탐색
    seen.assign(N, false); // 초기 상태는 모든 꼭짓점이 미방문
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // 이미 방문했으면 탐색하지 않음
        dfs(G, v);
    }
}
