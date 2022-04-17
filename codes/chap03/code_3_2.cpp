// 탐색 + 해당 원소의 위치까지
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    
    int found_id = -1; // 답이 될 수 없는 값으로 초기화
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) { // 찾음
            found_id = i; 
            break; 
        }
    }
    // -1인 경우 못 찾은 case
    cout << found_id << endl;
}
