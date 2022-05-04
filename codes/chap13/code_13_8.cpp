// 루트 없는 트리를 루트 트리로 만들 때 각 꼭짓점 깊이 구하기
using Graph = vector<vector<int>>;
vector<int> depth; // 편의를 위해 전역 변수에 답을 저장

// d: 꼭짓점 v의 깊이(v가 루트라면 d = 0)
void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for (auto c : G[v]) {
      if(c==p) continue; // 탐색이 부모 방향으로 역류하는 걸 방지
      dfs(G, c ,v ,d+1); // d에 1을 더하고 자식 꼭짓점으로
    }
}
