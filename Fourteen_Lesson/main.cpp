#include <iostream>
#include <array>
#include <vector>

template <typename T, const int size_>
class MyClass
{
public:

	class iterator
	{
	public:
		iterator() = delete;
		iterator(T* data) : data_(data) {}
		iterator& operator++()
		{
			data_++;
			return *this;
		}

		iterator& operator++(int)
		{
			iterator tmp(*this);
			data_++;
			return tmp;
		}

		bool operator==(const iterator& obj) const
		{
			return this->data_ == obj.data_;
		}

		bool operator!=(const iterator& obj) const
		{
			return !this->operator==(obj);
			// такой стиль применим если условия проверки
			// содержат сложные условия или вызовы функций
			//return this->data_ != obj.data_;
		}

		T& operator*()
		{
			return *data_;
		}

		

	private:
		T* data_;
	};

	int Size()
	{
		return _size;
	}

	T& operator[](int i)
	{
		return _data[i];
	}

	const T& operator[](int i) const
	{
		return _data[i];
	}

	auto at(int i) -> T&	// tail trace
	{
		return _data[i];
	}

	auto at(int i) const -> const T&// tail trace
	{
		return _data[i];
	}

	iterator begin()
	{
		return iterator(_data);
	}

	iterator end()
	{
		return iterator(_data + _size);
	}

	
	

private:
	T _data[size_];
	const int _size{ size_ };
};



void f01(MyClass<int, 10> a)
{
	for (size_t i = 0; i < a.Size(); i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;
}


int main()
{
	MyClass<int, 10> obj;
	for (size_t i = 0; i < obj.Size(); i++)
	{
		obj[i] = i + 1;
	}
	f01(obj);
	//:::::::::::::::::::::::::::::::::::::::::::::
	int arr[10]{};
	for (size_t i = 0; i < std::size(arr); i++)
	{
		arr[i] = i + 1;
	}
	std::cout << std::endl;
	for(const auto& el : arr)
	{
		std::cout << el << ' ';
	}
	std::cout << std::endl;
	//:::::::::::::::::::::::::::::::::::::::::::::
	std::array<int, 10> arrObj;
	for (size_t i = 0; i < std::size(arrObj); ++i)
	{
		arrObj[i] = i + 2;
	}
	std::cout << '\n';
	for (const auto& el : arrObj)
	{
		std::cout << el << ' ';
	}
	std::cout << std::endl;
	//:::::::::::::::::::::::::::::::::::::::::::::

	/*for (auto it = obj.Begin(); it != obj.End(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;*/

	for (const auto& el : obj)
	{
		std::cout << el << ' ';
	}
	std::cout << std::endl;

}


