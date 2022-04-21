// 그래프 구현
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    // 꼭짓점 개수와 변 개수
    int N, M;
    cin >> N >> M;

    // 그래프
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);

       // 무향 그래프라면 다음 줄 주석을 제거해서 추가
        // G[b].push_back(a);
    }
}
/*
N(vertex 개수) M(edge 개수)
ai bi (ai -> bi)
input(directed graph)
8 12
4 1
4 2
4 6
1 3
1 6
2 5
2 7
6 7
3 0
3 7
7 0
0 5
*/
