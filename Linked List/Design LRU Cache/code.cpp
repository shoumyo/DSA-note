#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Node {
    public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
    int capacity;
    
    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }
    
    void deleteNode(Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;
        
        // Move to front (most recently used)
        deleteNode(ansNode);
        addNode(ansNode);
        
        return ans;
    }
    
    void put(int key, int val) {
        if(m.find(key) != m.end()) {
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
            delete oldNode;
        }
        
        if(m.size() == capacity) {
            // Remove least recently used (tail's prev)
            Node* lru = tail->prev;
            deleteNode(lru);
            m.erase(lru->key);
            delete lru;
        }
        
        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
    
    ~LRUCache() {
        // Clean up memory
        Node* current = head;
        while(current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    // Example usage
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;    // returns 1
    cache.put(3, 3);                 // evicts key 2
    cout << cache.get(2) << endl;    // returns -1 (not found)
    cache.put(4, 4);                 // evicts key 1
    cout << cache.get(1) << endl;    // returns -1 (not found)
    cout << cache.get(3) << endl;    // returns 3
    cout << cache.get(4) << endl;    // returns 4
    
    return 0;
}