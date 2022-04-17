// 4_9 Memoization 적용
// 1. 이미 답이 있는 경우 답 반환
// 2. 계산에서 답을 찾은 경우 memo 배열에 답을 적기
// 부분합 문제 
#include <iostream>
#include <vector>
using namespace std;

// func(i, w, a) 답을 적어두는 배열
vector<vector<int>> memo;

// 0：false、1: true
int func(int i, int w, const vector<int> &a) {
    // base case
    if (i == 0) {
        if (w == 0) return true;
        else return false;
    }

    // 이미 답이 있는 경우 해당 답 리턴
    if (memo[i][w] != -1) return memo[i][w];

    // a[i - 1]를 선택하지 않은 경우
    if (func(i - 1, w, a)) return memo[i][w] = 1;

    // a[i - 1]를 선택한 경우
    if (func(i - 1, w - a[i - 1], a)) return memo[i][w] = 1;

    // 둘 다 false이면 false
    return memo[i][w] = 0;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 재귀적으로 풀기
    memo.assign(N+1, vector<int>(W+1, -1));
    if (func(N, W, a)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
