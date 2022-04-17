// "1927359"처럼 모든 글자가 1이상 9이하의 숫자로 된 길이가 N인 문자열 S가 주어졌을 때 문자 사이사이에 +를 넣을 수 있다고 하자.
// +는 0개 이상 가능하나 연속한 +는 넣을 수 없다.
// 이런 조건으로 만들 수 있는 모든 문자열을 산술식으로 보고 총합을 계산하는 O(N2^N) 복잡도 알고리즘을 설계하라.
// 예를들어 "125"라면 125, 1+25(=26), 12+5(=17), 1+2+5(=8)이고 이걸 모두 더한 176이 답이다.

#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    // +를 넣을 수 있는 장소는 N-1개 --> 모두 확인
    long long res = 0;
    for (int bit = 0; bit < (1<<(N-1)); ++bit) {
        // tmp：+와 + 사이의 값을 나타내는 변수
        long long tmp = 0;
        for (int i = 0; i < N-1; ++i) {
            tmp *= 10;
            tmp += S[i] - '0';

            if (bit & (1<<i)) { // 누적된 값에 대해 더하고 이후 누적을 위해 tmp 초기화
                res += tmp;
                tmp = 0;
            }
        }

        // 남은 부분 답에 더하기
        tmp *= 10;
        tmp += S.back() - '0';
        res += tmp;
    }
    cout << res << endl;
}
