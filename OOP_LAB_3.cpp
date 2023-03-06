#include <iostream>
#include <any>

using namespace std;

class element {
private:
	any elem;
public:
	element() {
		elem = NULL;
	}
	element(any elem){
		this->elem = elem;
	}
	element& operator=(any obj) {
		elem = obj;
}
};


class container {
private:
	// Pointer to store array created
	element *arr = NULL;
	element *cur = NULL;
	// Array size
	int size;
	// Container size
	int capacity;
public: 
	// default constructor
	container() {
		capacity = 1;
		size = 0;
		arr = new element[capacity];
		cur = arr;
	}
	// constuctor with parameter
	container(int capacity) {
		this->capacity = capacity;
		arr = new element[capacity];
		cur = arr;
		size = 0;
	}

	void growArr() {
		element* temp = new element[capacity * 2];

		capacity *= 2;

		for (int i = 0; i < size; ++i) {
			temp[i] = arr[i];
		}
		delete[] arr;

		arr = temp;
	}
	void reduceArr() {
		capacity = size;
		element* temp = new element[capacity];

		for (int i = 0; i < size; ++i) {
			temp[i] = arr[i];
			delete[] arr;
			arr = temp;
		}
	}
	element first() {
		return *cur;
	}
	bool eol() {
		return cur == (arr + size);
	}
	void prev() {
		--cur;
	}
	void next() {
		++cur;
	}
	void push_middle(element obj);
	void push_begin(element obj);
	void push_back(element value) {
		if (size == capacity) {
			growArr();
		}
		arr[size] = value;
		++size;
	}
	void pop_back() {
		arr[size - 1] = 0;
		--size;
		if (size == (capacity / 2)) {
			reduceArr();
		}
	}
	void remove(int index) {
		for (int i = index; i < size; ++i) {
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = 0;
		--size;
		if (size == (capacity / 2)) {
			reduceArr();
		}
	}
	any getObject() {
		return *cur;
	}
};


int main(){
	int n1 = 10;
	string s1 = "asd";
	container arr[2];
	for (arr->first(); arr->eol(); arr->next()) {
		cout << arr->getObject();
	}

	

}
