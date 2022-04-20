// 문제 링크 https://atcoder.jp/contests/agc009/tasks/agc009_a
// O(N)
// 생각하자!
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];

    // 답
    long long sum = 0;
    for (int i = N - 1; i >= 0; --i) {
        A[i] += sum; // 전회까지의 작업 횟수 더하기
        long long amari = A[i] % B[i];
        long long D = 0;
        if (amari != 0) D = B[i] - amari;
        sum += D; 
    }
    cout << sum << endl;
}
