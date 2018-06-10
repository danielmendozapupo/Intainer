#ifndef INTAINER_H
#define INTAINER_H


#include <iostream>
#include<iomanip>
#include <algorithm>
#include<stdexcept>

using namespace std;

class intainer
{
private:
	int _maxsize, *_items;
	void CheckBounds(int index) const //checking if the index is between the range 
	{
		if (index < 0 || index >= _maxsize) throw std::out_of_range("intainer out of bounds");
	}
public:

	template <typename T>
	class const_iterator
	{
	public:
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::forward_iterator_tag iterator_category;
		const_iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator++() { self_type i = *this; ptr_++; return i; }
		self_type operator++(int junk) { ptr_++; return *this; }
		const reference operator*() { return *ptr_; }
		const pointer operator->() { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
	};

	
	intainer(int MaxSize) { _maxsize = MaxSize; _items = new int[MaxSize]; }


	void set(int index, int val) { CheckBounds(index); _items[index] = val; }
	int get(int index) const { CheckBounds(index); return _items[index]; }


	const_iterator<int> begin()
	{
		return const_iterator<int>(_items);
	}

	const_iterator<int> end()
	{
		return const_iterator<int>(_items + _maxsize);
	}
	


	~intainer() {};
};
#endif
