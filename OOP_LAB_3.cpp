#include <iostream>
#include<string>

using namespace std;

class A {
public:
	int a;
	string str;
	A() {
		a = rand();
		str = "elem: " +  to_string(a);
	}
	int get_a() {
		return a;
	}
	string get_str() {
		return str;
	}
};
ostream& operator<<(ostream &os,const A &obj) {
	return os << obj.str;
}

template<typename t>
class container {
private:
	// Pointer to store array created
	t* arr = NULL;
	// Array size
	int size;
	// Container size
	int capacity;
public:
	// default constructor
	container() {
		capacity = 1;
		size = 0;
		arr = new t[capacity];
	}
	// constuctor with parameter
	container(int capacity) {
		this->capacity = capacity;
		arr = new t[capacity];
		size = 0;
	}

	void growArr() {
		t* temp = new t[capacity * 2];

		capacity *= 2;

		for (int i = 0; i <= size; ++i) {
			temp[i] = arr[i];
		}
		delete[] arr;

		arr = temp;
	}
	void reduceArr() {
		capacity = size;
		t* temp = new t[capacity];

		for (int i = 0; i <= size; ++i) {
			temp[i] = arr[i];
			delete[] arr;
			arr = temp;
		}
	}
	void push_back(t value) {
		if (size == capacity) {
			growArr();
		}
		arr[size] = value;
		++size;
	}
	void push_middle(t obj) {

	}
	int search(t obj)
	{
		for (int i = 0; i < size; i++) {
			if (arr[i] == obj) {
				return i;
			}
		}
		return -1;
	}
	void pop_back() {
		arr[size - 1] = 0;
		--size;
		if (size == (capacity / 2)) {
			reduceArr();
		}
	}
	void remove(int index) {
		for (int i = index; i <= size; ++i) {
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = 0;
		--size;
		if (size == (capacity / 2)) {
			reduceArr();
		}
	}
	
	t getAt(int index) {
		if ((index <= size) && (index > 0)) {
			return arr[index];
		}
		return NULL;
	}
	t setAt(int index, t obj) {
		if ((index <= size) && (index > 0)) {
			arr[index] = obj;
		}
		return NULL;
	}
	void insertAt(int index, t obj)
	{
		if (size == capacity) {
			growArr();
		}
		for (int i = size - 1; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = obj;
		++size;
	}
	int get_size() {
		return size;
	}
};



int main() {
	srand(time(NULL));
	container<A*> arr;
	clock_t start = clock();
	for (int i = 0; i < 100000; ++i) {
		arr.push_back(new A());
	}
	for (int i = 0; i < 1000; ++i) {
		switch (rand() % 4)
		{
		case 0:
			arr.push_back(new A());
			break;
		case 1:
			if (arr.get_size()) {
				arr.remove(rand() % arr.get_size());
			}
			break;
		case 2:
			if (arr.get_size()) {
				arr.pop_back();
			}
			break;
		case 3:
			arr.getAt(rand() % arr.get_size());
			break;
		case 5:
			arr.setAt(rand() % arr.get_size(), new A());
			break;
		case 6:
			arr.search((new A()));
			break;
		case 7:
			arr.insertAt(rand() % arr.get_size(), new A());
			break;
		}
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;

	for (int i = 1; i < arr.get_size(); ++i) {
		cout << *arr.getAt(i);
		cout << '\n';
	}
	cout << '\n';
	
	cout << "Seconds to complete " << seconds << '\n';

}
