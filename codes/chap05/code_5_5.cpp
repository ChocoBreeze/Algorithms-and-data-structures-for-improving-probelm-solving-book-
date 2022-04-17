// 개구리 문제를 푸는 다른 방법
// 전체 탐색 --> 지수 시간 alg
// pull-based (끌기 전이)
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) { // 완화
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60; // 충분히 큰 값으로 초기화

// 입력 데이터와 메모용 DP 테이블
int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i) {
    // base case : 발판 0의 비용은 0
    if (i == 0) return 0;

    // 답을 나타내는 변수를 INF로 초기화
    long long res = INF;

    // i - 1 발판에서 온 경우
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1])); 
    
    // i - 2 발판에서 온 경우
    if (i > 1) {
        chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    }

    // 결과를 메모하면서 돌려줌
    return res;
}

int main() {
    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 초기값 (최소화 문제라서 INF로 초기화)
    dp.assign(N, INF);

    cout << rec(N - 1) << endl;
}
