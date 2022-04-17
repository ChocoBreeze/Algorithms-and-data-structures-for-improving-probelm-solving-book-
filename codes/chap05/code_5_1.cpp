// 개구리 문제
// 링크 : https://atcoder.jp/contests/dp/tasks/dp_a
// i번째로 가는 방법은 i-1번째에서 jump하거나 i-2번재에서 jump --> 둘 중 min

#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60; // 충분히 큰 값으로 초기화

int main() {
    int N; cin >> N;
    vector<long long> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 배열 dp 정의
    vector<long long> dp(N, INF);

    // 초기 조건
    dp[0] = 0;

    // 루프
    for (int i = 1; i < N; ++i) {
        if (i == 1) dp[i] = abs(h[i] - h[i - 1]);
        else dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), 
                         dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;
}
