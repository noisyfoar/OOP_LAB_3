#include <iostream>
#include <vector>

using namespace std;

template <typename t1>
class element {
private:
	t1 elem;
public:
	element(t1 elem){
		this->elem = elem;
	}
};

template <typename t2>
class container {
private:
	// Pointer to store array created
	element *arr = NULL;
	element *cursor = arr;
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
	}
	// constuctor with parameter
	container(int capacity) {
		this->capacity = capacity;
		arr = new element[capacity];
		size = 0;
	}

	void growArr();
	void reduceArr();
	element first();
	bool eol();
	void prev();
	void next();
	void push_middle(element obj);
	void push_begin(element obj);
	void push_back(element obj);
	void remove(int index);
};

void container:: growArr() {

}

int main(){


}
