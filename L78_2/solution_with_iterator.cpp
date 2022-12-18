#include <iostream>
#include <string>

template <typename T>
class iterator{
public:

    iterator(T* ptr){
        _ptr = ptr;
    }

    iterator& operator++(){
        ++_ptr;
        return *this;
    }

    T& operator*(){
        return *_ptr;
    }

    bool operator==(iterator& other){
        return _ptr == other._ptr;
    }

    bool operator!=(iterator& other){
        return _ptr != other._ptr;
    }

private:
    T* _ptr;
};

template<typename T>
class dynamic_array {
private:
    size_t _size = 0;
    size_t _capacity = 1;
    T* thing = nullptr;
public:

    dynamic_array(){
        thing = new T[_capacity];
    }

    ~dynamic_array(){
        delete[] thing;
    }

    explicit dynamic_array(size_t s) : _size(s){
        while (_capacity <= _size) {
            _capacity <<= 1;
        }
    }

    T& operator[](size_t index){
        return thing[index];
    }

    friend std::ostream& operator<<(std::ostream &out, dynamic_array<T> &arr)
    {
        for (size_t i = 0; i < arr._size; ++i) {
            out << arr.thing[i] << " ";
        }
        return out;
    }

    size_t size(){
        return _size;
    }
    size_t capacity(){
        return _capacity;
    }

    iterator<T> begin(){
        return iterator<T>(thing);
    }

    iterator<T> end(){
        return iterator<T>(thing + _size);
    }

    void insert(size_t pos, size_t number_of_elements_to_insert, const T arr[]){

        _size += number_of_elements_to_insert;
        while (_capacity <= _size) {
            _capacity <<= 1;
        }

        T* new_thing = new T[_capacity];

        size_t i = 0;
        for (; i < pos; ++i) {
            new_thing[i] = thing[i];
        }

        size_t j = 0;
        for (; j < number_of_elements_to_insert; ++j){
            new_thing[i+j] = arr[j];
        }

        for (; i+j < _size; ++i){
            new_thing[i+j] = thing[i];
        }

        delete[] thing;
        thing = new_thing;
    }

    void erase(size_t index, size_t number_of_elements_to_erase){

        T* new_thing = new T[_capacity];

        size_t external_counter = 0;
        for (size_t i = 0; i < _size; ++i){
            if (i == index){
                i += number_of_elements_to_erase;
            }
            new_thing[external_counter] = thing[i];
            ++external_counter;
        }
        _size -= number_of_elements_to_erase;

        delete[] thing;
        thing = new_thing;
    }

    void initialize(int number_to_initialize_with = 0){
        for (int i = 0; i < _size; ++i) {
            thing[i] = number_to_initialize_with;
        }
    }

};

int main() {
    dynamic_array<int> a;
    int N[5]{1, 2, 3, 4, 5};
    a.insert(0, 5, N);
    for (int i : a){
        std::cout << i << ' ';
    }
    std::cout << '\n';

    for (auto it = a.begin(); it != a.end(); ++it){
        std::cout << *it << ' ';
    }
}
