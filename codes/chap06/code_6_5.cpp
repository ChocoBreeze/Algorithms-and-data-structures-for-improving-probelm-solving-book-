// 최적화 문제를 판정 문제로
// 최종적인 패널티를 x 이하로 만들 수 있는지 판정하는 문제
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N), S(N); // H : 초기 위치, S : 매초 풍선이 올라가는 양
    for (int i = 0; i < N; i++) cin >> H[i] >> S[i];

    // 이진 탐색 상한값 구하기
    long long M = 0;
    for (int i = 0; i < N; ++i) M = max(M, H[i] + S[i] * N);

    // 이진탐색
    long long left = 0, right = M;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        
        // 판정
        bool ok = true;
        vector<long long> t(N, 0);  // 각 풍선이 터질 때까지 제한 시간
        for (int i = 0; i < N; ++i) {
            // mid가 초기 높이보다 낮으면 false
            if (mid < H[i]) ok = false; 
            else t[i] = (mid - H[i]) / S[i]; // mid까지 올라가는데 걸리는 시간
        }
        // 시간 제한이 얼마 남지 않은 순서로 정렬
        sort(t.begin(), t.end());   // O(NlogN)
        for (int i = 0; i < N; ++i) {
            // 제한 시간 초과가 발생하면 false
            if (t[i] < i) ok = false; 
        }

        if (ok) right = mid; // 높이를 더 낮추어도 된다
        else left = mid; // 높이를 높여야 함
    }

    cout << right << endl;
}
