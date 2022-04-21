// self-referencing structure
struct Node {
    Node* next; // 다음이 어떤 노드인지
    string name; // 노드에 저장된 값

    Node(string name_ = "") : next(NULL), name(name_) { }
};
