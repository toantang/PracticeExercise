#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node *p = new Node(data);
    if (head == NULL) {
        head = p;
    }
    else {
        p->next = head;
        head = p;
    }
    return head;
}

// print the list content on a line
void print(Node* head) {
    Node *p = head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
}

int main() {
    cout << "ho ten: Tang The Toan" << endl;
    cout << "MSSV: 20183998" << endl;
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);
    cout << "Reversed list: ";
    print(head);

    return 0;
}
