#include <iostream>

using namespace std;
template<typename T>
class Node{
public:
    T value;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;

    Node(T val) : value(val) {}
    Node() = default;
};

template<typename T>
class NodeIterator {

};

template<typename T>
struct DoublyLinkedList{
private:
    Node<T>* first = nullptr;
    size_t size = 0;
public:

    Node<T>* IterateToIndex(size_t index) {
        Node<T>* it = first;
        for (size_t i = 0; i < index; ++i) {
            if (it != nullptr) {
                it = it->next;
            }
        }
        return it;
    }

    void insert(size_t index, size_t elements_to_insert, T array[]){

        size += elements_to_insert;
        Node<T>* current_node = IterateToIndex(index);

        for (size_t i = 0; i < elements_to_insert; ++i) {

            Node<T>* inserted_node = new Node<T>(array[i]);

            if (inserted_node == first) {
                inserted_node->next = first->next;
                first = inserted_node;
                current_node = first;
                continue;
            }

            inserted_node->prev = current_node;
            inserted_node->next = current_node->next;
            current_node = inserted_node;

        }
    }
};

int main() { // 1 8 9 2 3 4
    int arr1[4] = {1, 2, 3, 4};
    int arr2[2] = {8, 9};
    DoublyLinkedList<int> a; // 1 2 3 4
    a.insert(0, 4, arr1);
    a.insert(1, 2, arr2);

}
