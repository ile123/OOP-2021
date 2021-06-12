#include <iostream>


#ifndef KOKO_HPP
#define KOKO_HPP

template <class T> class Stack {
protected:
	T* stack;
	int n;
public:
	Stack() {
		n = 0;
	}
	void pop();
	void push(T element);
	bool is_empty();
};

template<typename T> bool Stack<T>::is_empty(){
	return (n == 0) ? true : false;
}

template<typename T> void Stack<T>::push(T element) {
	n += 1;
	if (n > 1) {
		T* niz = new T[n];
		for (int i = 0;i < n - 1;i++) {
			niz[i] = stack[i];
		}
		niz[n - 1] = element;
		delete[] stack;
		stack = niz;
		delete[]niz;
	}
	else {
		stack[0] = new T[1];
		stack[0] = element;
	}
}

template<typename T> void Stack<T>::pop() {
	n -= 1;
	T* niz = new T[n];
	for (int i = 0;i < n;i++) {
		niz[i] = stack[i];
	}
	delete[] stack;
	stack = niz;
	delete[] niz;
}

#endif
