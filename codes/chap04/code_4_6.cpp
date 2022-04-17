// 피보나치 수열을 구하는 재귀함수의 과정 출력
#include <iostream>
using namespace std;

int fibo(int N) {
    cout << "fibo(" << N << ") 호출" << endl;
    
    // base case
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // 재귀적으로 답을 구해서 출력
    int result = fibo(N - 1) + fibo(N - 2);
    cout << N << "  = " << result << endl;

    return result;
}

int main() {
    fibo(6);
}
