#include "stack.h" 
//__________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________


template<typename T> // проверка на пустоту стэка 
inline auto stack<T>::empty()->bool {
	return (count_ == 0);
}

template <typename T>//копирование и выделение памяти 
auto mem_copy(size_t count_m, size_t array_size_m, const T * tmp)->T* {
	T *mass = new T[array_size_m];
	
	try
{
std::copy(tmp,tmp+count_m,mass);
}
catch(...)
{
delete[] mass;
throw;
}
	return mass;
}


template <typename T>//освобождение памяти
inline stack<T>::~stack() {
};

template <typename T>//конструктор по умолчанию
inline stack<T>::stack() :count_(0),array_size_(0),array_(nullptr){};



template <typename T>//вставка элемента в стэк 
inline auto stack<T>::push(T const &val)->void {
	
		if (count_ == size_) {
			size_t size= size_*2+(size_==0);
			T *tmp = mem_copy(count_,size,ptr_);
			delete[] ptr_;
			ptr_ = tmp;
			size_ = size;

		}


		ptr_[count_] = val;
		++count_;
	}


template <typename T>//конструктор копирования
inline stack<T>::stack(stack const &tmp) {
	count_ = tmp.count_;
	ptr_ = mem_copy(tmp.count_, tmp.size_, tmp.ptr_);
	size_ = tmp.size_;
};

template <typename T>//перегрузка оператора присваивания 
inline auto stack<T>::operator=(const stack &tmp)->stack& {
	if (this != &tmp) {
		delete[] ptr_; 
		count_ = tmp.count_;
		std::cout << tmp.count_<<"sad";
		size_ = tmp.size_;
		ptr_ = mem_copy(tmp.count_, tmp.size_, tmp.ptr_);
	}
	return *this;
}
template <typename T>//возвращаем count_
inline auto stack<T>::count() const noexcept->size_t {
	return count_;
}

template <typename T>// уменьшение count_ 
inline auto stack<T>::pop()->T {
	if (count_ == 0) throw std::logic_error("Empty!");
	return --count_;
}

template <typename T>//удаление элемента
inline auto stack<T>::top() const->T& {
	if (count_ == 0) throw std::logic_error("Empty!");
	return ptr_[count_];

}
