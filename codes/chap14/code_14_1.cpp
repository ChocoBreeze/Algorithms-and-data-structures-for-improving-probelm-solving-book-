// 완화
// 갱신 여부를 bool 값으로 return 
template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

// e = (u, v)에 대한 완화 처리
// chmin(d[v], d[u] + l{e))
// d[v]의 초기값은 v=s일 때, 0 // v!=s일 때 infinity
