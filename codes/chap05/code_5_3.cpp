// 5_1 + 5_2
// O(N)
// 끌기 전이 방식(pull based) [i-1] or [i-2] --> [i]
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) { // relaxation
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // 충분히 큰 값

int main() {
    int N; cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 초기화 (최소화 문제이므로 INF로 초기화)
    vector<long long> dp(N, INF);

    // 초기 조건
    dp[0] = 0;

    for (int i = 1; i < N; ++i) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1) {
            chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }

    cout << dp[N - 1] << endl;
}
