#pragma once

#include <iostream>
#include <assert.h>

template <class T>
class ArrayList {
public:
	ArrayList(int size = 100);
	ArrayList(const ArrayList<T>& otherList);
	~ArrayList();
	const ArrayList<T>& operator=(const ArrayList<T>&);

	bool  isEmpty() const;
	bool  isFull() const;
	int   listSize() const;
	int   maxListSize() const;
	void  print() const;
	bool  isItemAtEqual(int location, const T& item) const;
	virtual void insertAt(int location, const T& insertItem);
	virtual void insertEnd(const T& insertItem);
	void removeAt(int location);
	void retrieveAt(int location, T& retItem) const;
	void replaceAt(int location, const T& repItem);
	void clearList();
	int seqSearch(const T& item) const;
	void insert(const T& insertItem);
	void remove(const T& removeItem);
	void removeItemAt(unsigned index);
	const T& operator[](int index) const;

	const T& operator[](int index);

	void removeAll(T item);

	ArrayList<int> findAll(T item);

	bool operator>(ArrayList<T> anotherList) const;

	T min();

protected:
	T* list; 
	int length; 
	int maxSize;
	void swap(unsigned firstIndex, unsigned secondIndex);
};

template <class T>
bool ArrayList<T>::isEmpty() const {
	return (length == 0);
}

template <class T>
bool ArrayList<T>::isFull() const {
	return (length == maxSize);
}

template <class T>
int ArrayList<T>::listSize() const {
	return length;
}

template <class T>
int ArrayList<T>::maxListSize() const {
	return maxSize;
}

template <class T>
void ArrayList<T>::print() const {
	for (int i = 0; i < length; i++)
		std::cout << list[i] << " ";
	std::cout << std::endl;
}

template <class T>
bool ArrayList<T>::isItemAtEqual (int location, const T& item) const {
	return(list[location] == item);
}

template <class T>
void ArrayList<T>::insertAt(int location, const T& insertItem) {
	if (location < 0 || location > maxSize)
		std::cerr << "The position of the item to be inserted " << "is out of range" << std::endl;
	else
		if (length >= maxSize) 
			std::cerr << "Cannot insert in a full list" << std::endl;
		else {
			for (int i = length; i > location; i--)
				list[i] = list[i - 1]; 
			list[location] = insertItem; 
			length++; 
		}
} 

template <class T>
void ArrayList<T>::insertEnd(const T& insertItem) {
	if (length >= maxSize)
		std::cerr << "Cannot insert in a full list" << std::endl;
	else {
		list[length] = insertItem; 
		length++; 
	}
} 

template <class T>
void ArrayList<T>::removeAt(int location) {
	if (location < 0 || location >= length)
		std::cerr << "The location of the item to be removed " << "is out of range" << std::endl;
	else {
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
	}
} 

template <class T>
void ArrayList<T>::retrieveAt (int location, T& retItem) const {
	if (location < 0 || location >= length)
		std::cerr << "The location of the item to be retrieved is " << "out of range." << std::endl;
	else
		retItem = list[location];
} 

template <class T>
void ArrayList<T>::replaceAt (int location, const T& repItem) {
	if (location < 0 || location >= length)
		std::cerr << "The location of the item to be replaced is " << "out of range." << std::endl;
	else
		list[location] = repItem;
} 

template <class T>
void ArrayList<T>::clearList() {
	length = 0;
}

template <class T>
ArrayList<T>::ArrayList(int size) {
	if (size < 0) {
		std::cerr << "The array size must be positive. Creating " << "an array of size 100. " << std::endl;
		maxSize = 100;
	}
	else
		maxSize = size;
	length = 0;
	list = new T[maxSize];
	assert(list != NULL);
}

template <class T>
ArrayList<T>::~ArrayList() {
	delete[] list;
}

template <class T>
ArrayList<T>::ArrayList (const ArrayList<T>& otherList) {
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new int[maxSize]; 
	assert(list != NULL);
	for (int j = 0; j < length; j++) 
		list[j] = otherList.list[j];
} 

template <class T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& otherList) {
	if (this != &otherList)  {
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new T[maxSize];
		assert(list != NULL); 
		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}
	return *this;
}

template <class T>
int ArrayList<T>::seqSearch(const T& item) const {
	int loc;
	bool found = false;
	for (loc = 0; loc < length; loc++)
		if (list[loc] == item) {
			found = true;
			break;
		}
	if (found)
		return loc;
	else
		return -1;
}

template <class T>
void ArrayList<T>::insert(const T& insertItem) {
	int loc;
	if (length == 0) 
		list[length++] = insertItem; 
	else if (length == maxSize)
		std::cerr << "Cannot insert in a full list." << std::endl;
	else {
		loc = seqSearch(insertItem);
		if (loc == -1) 
			list[length++] = insertItem;
		else
			std::cerr << "the item to be inserted is already in " << "the list. No duplicates are allowed." << std::endl;
	}
} 

template <class T>
void ArrayList<T>::remove(const T& removeItem) {
	int loc;
	if (length == 0)
		std::cerr << "Cannot delete from an empty list." << std::endl;
	else {
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			std::cout << "The item to be deleted is not in the list." << std::endl;
	}
} 

// ! my code starts from here

template<class T>
const T& ArrayList<T>::operator[](int index) const { 
	if(index >= 0) return this->list[index];
}

template<class T>
const T& ArrayList<T>::operator[](int index) { 
	if(index >= 0) return this->list[index];
}

/**
 * @brief A method used to swap 2 elements in an ArrayList with indecies starting from 1 for the first index
 * 
 * @param firstIndex 
 * @param secondIndex 
 */
template<class T>
void ArrayList<T>::swap(unsigned firstIndex, unsigned secondIndex) {
	firstIndex = firstIndex - 1;
	secondIndex = secondIndex - 1;
	T temp = list[firstIndex];
	list[firstIndex] = list[secondIndex];
	list[secondIndex] = temp;
}


/**
 * @brief A method that removes an element at a specific index
 * 
 * @tparam T 
 * @param index 
 */
template<class T>
void ArrayList<T>::removeItemAt(unsigned index) {
	this->swap(this->list[index], this->list[listSize() - 1]);
	this->length--;
}

/**
 * @brief Remove all the occurences of an element
 * 
 * @tparam T 
 * @param item 
 */
template<class T>
void ArrayList<T>::removeAll(T item) {
	int loc;
	if (length == 0) {
		std::cerr << "Cannot delete from an empty list." << std::endl;
		return;
	}
	for(unsigned i = 0; i < this->length; i++) {
		loc = seqSearch(item);
		if (loc != -1) {
			removeAt(loc);
			if(seqSearch(item) == -1) return;
		}
		else {
			std::cerr << "The item to be deleted is not in the list." << std::endl;
			return;
		}
	}
	return;

}

/**
 * @brief A method that finds all the occurences and returns a list of 
 * the indecies of those occurences
 * 
 * @tparam T: any
 * @param item 
 * @return ArrayList<int> 
 */
template<class T>
ArrayList<int> ArrayList<T>::findAll(T item) {
	ArrayList<int> arrayOfIndecies;
	for(unsigned i = 0; i < this->listSize(); i++) {
		if(list[i] == item) {
			arrayOfIndecies.insertEnd(i);
		}
	}
	return arrayOfIndecies;
}

template<class T>
bool ArrayList<T>::operator>(ArrayList<T> anotherList) const {
	return this->length > anotherList.length;
}

/**
 * @brief A method that returns the minimum value of a list
 * 
 * @tparam T: any
 * @return T
 */
template<class T>
T ArrayList<T>::min() {
	T element = list[0];
	for(unsigned i = 0; i < length; i++) {
		if(element > list[i]) element = list[i];
	}
	return element;
}
