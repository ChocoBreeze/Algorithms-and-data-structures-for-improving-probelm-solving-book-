// N개ㅑ의 정수가 주어졌을 때, k번째로 작은 정수를 O(N)으로 구하기 --> median of medians
int rec(a, k) {
    // 종단조건
    if (a.size() <= 100) {
         sort(a.begin(), a.end()); 
         return a[k];
    }
  
    // a의 요소를 5개씩 잘라내어 각 그룹의 median을 모은다
    vector<int> a2;
    for (int i = 0; i < a.size(); i += 5) {
        a2.push_back(a[i:i+5] の median);  // ? 구하는 alg 필요
    }
  
    // a2의 median를 구함.
    int m = rec(a2, a.size()/10);
  
    // a를 3개의 그룹으로 나눈다
    vector<int> p, q, r;
    // p - m보다 작은 그룹 / q - m과 같은 그룹 / r - m보다 큰 그룹
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] < m) p.push_back(a[i]);
        else if (a[i] == m) q.push_back(a[i]);
        else r.push_back(a[i]);
    }

    // 재귀적으로 푼다.
    int res;
    if (k <= p.size()) return rec(p, k);
    else if (k <= p.size() + q.size()) return m;
    else return rec(r, k - p.size() - q.size());
}
// 참고
// https://2jinishappy.tistory.com/127
// https://2jinishappy.tistory.com/124
