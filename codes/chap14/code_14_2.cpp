// Bellman-Ford alg - O(|V||E|)
// 각 변에 해당하는 완화 처리를 |V|번 반복
// |V|번째 작업에서 갱신이 발생하는 경우 negative cycle이 존재함을 알 수 있음.
// negative cycle이 없는 경우 |V|-1번만 수행해도 최단 경로를 구할 수 있음.

/*
input 예시
N : 그래프 꼭짓점 수 / M : 변의 개수 / s : 시작점 번호
a0 -> b0 가중치 = w0
N M s 
a0 b0 w0
a1 b1 w1
...
*/

#include <iostream>
#include <vector>
using namespace std;

// 무한대를 뜻하는 값
const long long INF = 1LL << 60; // 충분히 큰 값을 사용(여기에서는 2^60)

// 변의 자료형. 가중치는 long long형을 사용
struct Edge {
    int to; // 인접 꼭짓점 번호
    long long w; // 가중치
    Edge(int to, long long w) : to(to), w(w) {}
};

// 가중 그래프 자료형
using Graph = vector<vector<Edge>>;

// 완화를 실시하는 함수
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    // 꼭짓점 개수, 변 개수, 시작점
    int N, M, s;
    cin >> N >> M >> s;

    // 그래프
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }

    // 벨만 포드 알고리즘
    bool exist_negative_cycle = false; // 음의 닫힌 경로가 존재하는가
    vector<long long> dist(N, INF);
    dist[s] = 0;
    for (int iter = 0; iter < N; ++iter) {
        bool update = false; // 갱신 발생 여부 플래그 (시작점 s에서 도달할 수 없는 꼭짓점으로 시작하는 완화는 하지 않음)
        for (int v = 0; v < N; ++v) {
            // dist[v] = INF이라면 꼭짓점 v에서의 완화를 하지 않음
            if (dist[v] == INF) continue;

            for (auto e : G[v]) {
                // 완화 처리를 하고 갱신되면 update를 true로
                if (chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                }
            }
        }

        // 갱신이 없었다면 최단 경로가 이미 구해졌음
        if (!update) break;

        // N번째 반복에서 갱신되었다면 음의 닫힌 경로가 존재함
        if (iter == N - 1 && update) exist_negative_cycle = true;
    }

    // 결과 출력
    if (exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
    else {
        for (int v = 0; v < N; ++v) {
            if (dist[v] < INF) cout << dist[v] << endl;
            else cout << "INF" << endl;
        }
    }
}
