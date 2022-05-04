#include <iostream>
// 그래프 탐색 구현 - BFS , DFS
#include <vector>
#include <queue> // BFS
#include <stack> // DFS
using namespace std;
using Graph = vector<vector<int>>;

void search(const Graph& G, int s) {
	int N = (int)G.size(); // 그래프 꼭짓점 개수

	// 그래프 탐색용 자료 구조
	vector<bool> seen(N, false); // 모든 꼭짓점을 미방문 상태로 초기화
	queue<int> todo; // bfs
	// stack<int> todo; // dfs

	// 초기 조건
	seen[s] = true; // s를 방문함
	todo.push(s); // todo는 s만 포함한 상태 - 방문 예정인 곳

	// todo가 빈 상태가 될 때까지 탐색
	while (!todo.empty()) {
		// todo에서 꼭짓점 꺼내기
		int v = todo.front();
		todo.pop();

		// v에서 갈 수 있는 꼭짓점 모두 조사
		for (int x : G[v]) {
			// 이미 발견한 꼭짓점은 탐색 x
			if (seen[x]) continue;

			// 새로운 꼭짓점 x를 이미 탐색한 꼭짓점으로 todo에 삽입
			seen[x] = true;
			todo.push(x);
		}
	}
}
