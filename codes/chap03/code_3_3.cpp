// find minimum value
#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000;   // initial value = 답이 될 수 없는 값

int main() {
    
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_value) min_value = a[i];
    }
    
    // min 출력
    cout << min_value << endl;
}
