// Fibonacci - Memoization
#include <iostream>
#include <vector>
using namespace std;

// fibo(N)의 답을 메모하는 장소
vector<long long> memo;

long long fibo(int N) {
    // base case
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // 이미 계산된 경우 해당 결과 반환
    if (memo[N] != -1) return memo[N];

    // 답을 메모하면서 재귀 호출
    return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main() {
    // -1로 초기화
    memo.assign(50, -1);

    fibo(49);

    // memo[0], ..., memo[49] 에 답이 저장되어 있음.
    for (int N = 2; N < 50; ++N) {
        cout << N << " 項目: " << memo[N] << endl;
    }
    return 0;
}
