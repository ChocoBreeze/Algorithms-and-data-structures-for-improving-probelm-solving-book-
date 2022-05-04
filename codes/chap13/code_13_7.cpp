// 루트 없는 트리를 조사하는 구현 기본형
// 각 꼭짓점의 후위 순회에서 자식 꼭짓점 정보를 합치고 싶을 때가 많으므로 DFS가 유리함.
using Graph = vector<vector<int>>;

// 트리 탐색
// v: 현재 탐색 중인 꼭짓점 p: v의 부모(v가 루트라면 p=-1)
void dfs(const Graph &G, int v, int p = -1) {
    for (auto c : G[v]) {
        if(c==p) continue; // 탐색이 부모 방향으로 역류하는 걸 방지
      
        // c는 v의 각 자식 꼭짓점을 돌아다니고 c의 부모는 v가 됨
        dfs(G, c, v);
    }
}
