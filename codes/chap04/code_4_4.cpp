// Euclidean algorithm
// m >= n > 0 ==> O(logn)
#include <iostream>
using namespace std;

int GCD(int m, int n) {
    // base case
    if (n == 0) return m;

    // 재귀 호출
    return GCD(n, m % n);
}

int main() {
    cout << GCD(51, 15) << endl; // 3이 출력
    cout << GCD(15, 51) << endl; // 3이 출력
}
