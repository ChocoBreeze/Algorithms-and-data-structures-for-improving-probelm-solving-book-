// 양방향 연결 리스트의 자기 참조 구조체
struct Node {
    Node *prev, *next;
    string name; // 노드에 저장된 값

    Node(string name_ = "") :
    prev(NULL), next(NULL), name(name_) { }
};
