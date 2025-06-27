#include <iostream>
using namespace std;

// Node class
class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

// HashTable class
class HashTable {
private:
    Node** table;   // dynamic array of Node* (linked list heads)
    int size;       // size of the hash table

    // Hash function
    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key)
            hash = (hash * 31 + ch) % size;
        return hash;
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; ++i)
            table[i] = nullptr;
    }

    // Insert key-value pair
    void insert(const string& key, int value) {
        int index = hashFunction(key);
        Node* head = table[index];

        // Update if exists
        while (head != nullptr) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }

        // Insert new node at beginning
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Search key
    bool search(const string& key, int& result) {
        int index = hashFunction(key);
        Node* head = table[index];
        while (head != nullptr) {
            if (head->key == key) {
                result = head->value;
                return true;
            }
            head = head->next;
        }
        return false;
    }

    // Remove key
    void remove(const string& key) {
        int index = hashFunction(key);
        Node* head = table[index];
        Node* prev = nullptr;

        while (head != nullptr) {
            if (head->key == key) {
                if (prev != nullptr)
                    prev->next = head->next;
                else
                    table[index] = head->next;
                delete head;
                return;
            }
            prev = head;
            head = head->next;
        }
    }

    // Display hash table
    void display() {
        for (int i = 0; i < size; ++i) {
            cout << i << ": ";
            Node* head = table[i];
            while (head != nullptr) {
                cout << "[" << head->key << ": " << head->value << "] -> ";
                head = head->next;
            }
            cout << "NULL\n";
        }
    }

    // Destructor to free memory
    ~HashTable() {
        for (int i = 0; i < size; ++i) {
            Node* head = table[i];
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

// Main Function
int main() {
    int tableSize;
    cout << "Enter hash table size: ";
    cin >> tableSize;

    HashTable ht(tableSize);

    ht.insert("apple", 100);
    ht.insert("banana", 200);
    ht.insert("orange", 150);
    ht.insert("grape", 180);

    ht.display();

    int value;
    if (ht.search("banana", value))
        cout << "\nValue for 'banana': " << value << endl;
    else
        cout << "\n'banana' not found\n";

    ht.remove("apple");
    cout << "\nAfter removing 'apple':\n";
    ht.display();

    return 0;
}
