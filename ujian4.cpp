#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Fungsi untuk menambah node di akhir list
    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Fungsi untuk menghapus node berdasarkan nilai data yang dicari
    void deleteNode(int val) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == val) {
                if (curr == head && curr == tail) {
                    head = tail = nullptr;
                } else if (curr == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (curr == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                break;
            }
            curr = curr->next;
        }
    }

    // Fungsi untuk menampilkan isi double linked list
    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);
    dll.append(6);
    dll.append(7);
    dll.append(8);
    dll.append(9);
    dll.append(10);

    std::cout << "Linked List nilai sebelum penghapusan: ";
    dll.display();

    int nilai_hapus;
    std::cout << "Masukkan nilai yang ingin dihapus: ";
    std::cin >> nilai_hapus;

    dll.deleteNode(nilai_hapus);

    std::cout << "Linked List nilai setelah penghapusan: ";
    dll.display();

    return 0;
}
