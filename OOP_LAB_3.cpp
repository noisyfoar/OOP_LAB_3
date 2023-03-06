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
};

int main(){


}
