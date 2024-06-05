#include <iostream>

using namespace std;

// Definisikan struktur Node
struct Node {
    int data;
    Node* next;
};

// Definisikan kelas CircularLinkedList
class CircularLinkedList {
private:
    Node* head;

public:
    // Konstruktor
    CircularLinkedList() {
        head = nullptr;
    }

    // Destruktor
    ~CircularLinkedList() {
        if (head != nullptr) {
            Node* current = head->next;
            while (current != head) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            delete head;
        }
    }

    // Fungsi untuk menambahkan node di awal list
    void addNodeAtBeginning(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    // Fungsi untuk menambahkan node di akhir list
    void addNodeAtEnd(int newData) {
        Node* newNode = new Node;
        newNode->data = newData;
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
    }

    // Fungsi untuk menambahkan node di tengah list
    void addNodeInMiddle(int newData, int position) {
        if (position <= 0) {
            cout << "Posisi harus lebih dari 0." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = newData;

        if (head == nullptr && position > 1) {
            cout << "List kosong, tidak bisa menambahkan di posisi selain 1." << endl;
            return;
        }

        Node* current = head->next;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current != head) {
            current = current->next;
            currentPosition++;
        }

        if (current == head && currentPosition < position - 1) {
            cout << "Posisi melebihi panjang list." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Fungsi untuk menampilkan isi circular linked list
    void displayList() {
        if (head == nullptr) {
            cout << "Circular linked list kosong." << endl;
            return;
        }

        Node* current = head->next;
        cout << "Isi circular linked list: ";
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList myList;

    // Menambahkan node di awal list
    myList.addNodeAtBeginning(5);
    myList.addNodeAtBeginning(10);
    myList.displayList();

    // Menambahkan node di akhir list
    myList.addNodeAtEnd(15);
    myList.addNodeAtEnd(20);
    myList.displayList();

    // Menambahkan node di tengah list
    myList.addNodeInMiddle(25, 3);
    myList.displayList();

    return 0;
}
