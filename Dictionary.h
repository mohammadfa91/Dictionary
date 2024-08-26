#include "dependencies/LinkedList/DLinkedList.h"

template <typename T, typename U>
class Dictionary {
private:
    DLinkedList<T> KeyList;
    DLinkedList<U> ValList;

public:
    void set(T key, U val) {
        for (int i = 0; i < KeyList.size(); i++) {
            if (KeyList.get(i) == key) {
                ValList.set(i, val);
                return;
            }
        }
        KeyList.add(key);
        ValList.add(val);
    }

    U get(T key) {
        for (int i = 0; i < KeyList.size(); i++) {
            if (KeyList.get(i) == key) {
                return ValList.get(i);
            }
        }
        return U(); // Return default value if key not found
    }

    T getKey(U val) {
        for (int i = 0; i < ValList.size(); i++) {
            if (ValList.get(i) == val) {
                return KeyList.get(i);
            }
        }
        return T(); // Return default value if value not found
    }

    int length() const {
        return KeyList.size();
    }

    bool contains(T key) {
        for (int i = 0; i < length(); i++) {
            if (KeyList.get(i) == key) {
                return true;
            }
        }
        return false;
    }

    T getKeyByIndex(int index) {
        return KeyList.get(index);
    }

    // Remove the last key-value pair
    void pop() {
        if (KeyList.size() > 0) {
            KeyList.pop();
            ValList.pop();
        }
    }

    // Remove the first key-value pair
    void shift() {
        if (KeyList.size() > 0) {
            KeyList.shift();
            ValList.shift();
        }
    }

    // Remove key-value pair by index
    void removeByIndex(int index) {
        if (index >= 0 && index < KeyList.size()) {
            KeyList.remove(index);
            ValList.remove(index);
        }
    }

    // Remove key-value pair by key
    void removeByKey(T key) {
        for (int i = 0; i < KeyList.size(); i++) {
            if (KeyList.get(i) == key) {
                KeyList.remove(i);
                ValList.remove(i);
                return;
            }
        }
    }
};
