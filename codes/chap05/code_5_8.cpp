// Edit distance
// O(|S||T|)
// S의 문자 삽입은 T의 문자 삭제와 동일함
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const int INF = 1 << 29; // 충분히 큰 값(2^29)

int main() {
    string S, T;
    cin >> S >> T;
    
    // DP table 정의
    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INF));

    // DP 초기 조건
    dp[0][0] = 0;

    for (int i = 0; i <= S.size(); ++i) {
        for (int j = 0; j <= T.size(); ++j) {
            // 변경 조작
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) { // 두 문자가 동일 --> 작업 필요 x
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                }
                else { // 두 문자가 다름 --> 대체 작업 필요
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            
            // 삭제 작업
            if (i > 0) chmin(dp[i][j], dp[i - 1][j] + 1);

            // 삽입 작업
            if (j > 0) chmin(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    
    cout << dp[S.size()][T.size()] << endl;
}
