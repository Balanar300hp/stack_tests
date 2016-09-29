
#include "stack.h"
template <typename T>
class stack : protected allocator<T>
{
public:
	stack();/*noexcept*/
	stack(stack const &); /*strong*/
	auto count() const noexcept->size_t;/*noexcept*/
	auto push(T const &)->void;/*strong*/
	auto pop()->T;/*strong*/
	auto top() const->T&;/*strong*/
	~stack(); 	/*noexcept*/
	auto operator=(const stack&tmp)->stack&;/*strong*/
	auto empty()->bool;/*noexcept*/
};

//__________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________


template<typename T> // проверка на пустоту стэка 
inline auto stack<T>::empty()->bool {
	return (allocator<T>::count_ == 0);
}

template <typename T>//копирование и выделение памяти 
auto mem_copy(size_t count_m, size_t array_size_m, const T * tmp)->T* {
	T *mass = new T[array_size_m];
	std::copy(tmp,tmp+count_m,mass);
	return mass;
}


template <typename T>//освобождение памяти
inline stack<T>::~stack() {
delete[] allocator<T>::ptr_;
};

template <typename T>//конструктор по умолчанию
inline stack<T>::stack() : allocator<T>() {};



template <typename T>//вставка элемента в стэк 
inline auto stack<T>::push(T const &val)->void {
	
		if (allocator<T>::count_ == allocator<T>::size_) {
			size_t size= allocator<T>::size_*2+(allocator<T>::size_==0);
			T *tmp = mem_copy(allocator<T>::count_,size,allocator<T>::ptr_);
			delete[] allocator<T>::ptr_;
			allocator<T>::ptr_ = tmp;
			allocator<T>::size_ = size;

		}


		allocator<T>::ptr_[allocator<T>::count_] = val;
		++allocator<T>::count_;
	}


template <typename T>//конструктор копирования
inline stack<T>::stack(stack const &tmp) {
	allocator<T>::count_ = tmp.count_;
	allocator<T>::ptr_ = mem_copy(tmp.count_, tmp.size_, tmp.ptr_);
	allocator<T>::size_ = tmp.size_;
};

template <typename T>//перегрузка оператора присваивания 
inline auto stack<T>::operator=(const stack &tmp)->stack& {
	if (this != &tmp) {
		delete[] allocator<T>::ptr_; 
		allocator<T>::count_ = tmp.count_;
		std::cout << tmp.count_<<"sad";
		allocator<T>::size_ = tmp.size_;
		allocator<T>::ptr_ = mem_copy(tmp.count_, tmp.size_, tmp.ptr_);
	}
	return *this;
}
template <typename T>//возвращаем count_
inline auto stack<T>::count() const noexcept->size_t {
	return allocator<T>::count_;
}

template <typename T>// уменьшение count_ 
inline auto stack<T>::pop()->T {
	if (allocator<T>::count_ == 0) throw std::logic_error("Empty!");
	return --allocator<T>::count_;
}

template <typename T>//удаление элемента
inline auto stack<T>::top() const->T& {
	if (allocator<T>::count_ == 0) throw std::logic_error("Empty!");
	return allocator<T>::ptr_[allocator<T>::count_];

}
