#include <iostream>
#include <stdexcept>




//__________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________
 
template <typename T>
class stack allocator<T>
{
public:
	stack();/*noexcept*/
	stack(stack const &); /*strong*/
	auto count() const noexcept->size_t;/*noexcept*/
	auto push(T const &)->void;/*strong*/
	auto pop()->void;/*strong*/
	auto top() const->T&;/*strong*/
	~stack(); 	/*noexcept*/
	auto operator=(const stack&tmp)->stack&;/*strong*/
	auto empty()->bool;/*noexcept*/

};

//__________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________



template<typename T> // ïðîâåðêà íà ïóñòîòó ñòýêà 
auto stack<T>::empty()->bool {
	return (count_ == 0);
}

template <typename T>//êîïèðîâàíèå è âûäåëåíèå ïàìÿòè 
auto mem_copy(size_t count_m, size_t array_size_m, const T * tmp)->T* {
	T *mass = new T[array_size_m];
	std::copy(tmp, tmp + count_m, mass);
	return mass;
}


template <typename T>//îñâîáîæäåíèå ïàìÿòè
stack<T>::~stack() {};

template <typename T>//êîíñòðóêòîð ïî óìîë÷àíèþ
stack<T>::stack()  {

};



template <typename T>//âñòàâêà ýëåìåíòà â ñòýê 
auto stack<T>::push(T const &val)->void {
	if count_ == size_) {//óâåëè÷èâàåò ïàìÿòü 
		size_t size = allocator<T>::size_ * 2 + (allocator<T>::size_ == 0);
		T *tmp = mem_copy(count_, size, ptr_);
		delete[] ptr_;
		ptr_ = tmp;
		size_ = size;
	}
	
	++count_;
}


template <typename T>//êîíñòðóêòîð êîïèðîâàíèÿ
stack<T>::stack(stack const &tmp) {
	count_ = tmp.count_;
	ptr_ = mem_copy(tmp.count_, tmp.size_, tmp.ptr_);
	size_ = tmp.size_;
};

template <typename T>//ïåðåãðóçêà îïåðàòîðà ïðèñâàèâàíèÿ 
auto stack<T>::operator=(const stack &tmp)->stack& {
	if (this != &tmp) {
		T* cp = mem_copy(tmp.count_, tmp.size_, tmp.ptr_);
		delete[] allocator<T>::ptr_; 
		ptr_ = cp;
		size_ =tmp.size_;
		count_ = tmp.count_;
	}
	return *this;
}


template <typename T>//âîçâðàùàåì count_
auto stack<T>::count() const noexcept->size_t {
	return count_;
}

template <typename T>// óìåíüøåíèå count_ 
auto stack<T>::pop()->void {
	if (count_ == 0) throw std::logic_error("Empty!");
	
	--count_;
}

template <typename T>//óäàëåíèå ýëåìåíòà
auto stack<T>::top() const->T& {
	if (count_ == 0) throw std::logic_error("Empty!");
	return ptr_[count_-1];

}
