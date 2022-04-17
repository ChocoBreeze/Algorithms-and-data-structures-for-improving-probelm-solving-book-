// 재귀를 이용한 부분합
// 최악의 경우 O(2^N)가지 확인
// 해당 원소를 선택하거나 선택하지 않거나로 나누기
// Memoization 개선 --> practice_4_6
#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int w, const vector<int> &a) {
    // base case
    if (i == 0) {
        if (w == 0) return true;
        else return false;
    }

    // a[i - 1]를 선택하지 않은 경우
    if (func(i - 1, w, a)) return true;

    // a[i - 1]를 선택한 경우
    if (func(i - 1, w - a[i - 1], a)) return true;

    // 둘 다 false이면 false
    return false;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 재귀적으로 풀기
    if (func(N, W, a)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
