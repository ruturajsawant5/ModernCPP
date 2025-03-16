#include <iostream>

template<typename T>
struct __Unnamed {
	int offset;
	__Unnamed(int off) :offset(off) {

	}
	void operator()(T &x) {
		x += offset;
		++offset;
	}
};


int main()
{

	__Unnamed<int> n(3);
	int x = 5;
	n(x);

	return 0;
}