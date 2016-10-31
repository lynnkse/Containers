#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "Container_t.h"
#include "cstring"

#define DEF_INIT_SIZE 10
#define NOT_FOUND -1

template <class T>
class Array_t : public Container_t<T>
{
	public:
		Array_t();
		Array_t(const Array_t& _arr);
		virtual ~Array_t();
		const Array_t<T>& operator=(const Array_t& _arr);
		virtual bool Append(const T& _el, size_t _index);		
		virtual bool Prepend(const T& _el, size_t _index);
		virtual bool Contains(const T& _el) const;
		virtual bool Find(const T& _el);
		virtual int Index(const T& _el) const;
		virtual void Insert(const T& _el);
		virtual bool Remove(const T& _el);
		virtual void RemoveAll();
		virtual bool RemoveAndDelete(const T& _el);
		virtual void RemoveAndDeleteAll();		
	private:
		T** m_elements;
		size_t m_currSize;
		static size_t m_defaultInitialSize;
		void ResizeIfNeed(size_t _newSize);
};

template <class T>
size_t Array_t<T>::m_defaultInitialSize = DEF_INIT_SIZE;

template <class T>
void Array_t<T>::ResizeIfNeed(size_t _newSize)
{
	if(m_currSize < _newSize)
	{
		delete[] m_elements;
		m_elements = new T*[_newSize];
		m_currSize = _newSize;	
	}
}

template <class T>
Array_t<T>::Array_t():m_currSize(m_defaultInitialSize) 
{
	m_elements = new T*[m_defaultInitialSize];
	if(!m_elements)
	{
		throw("Allocation error");
	}
}

template <class T>
Array_t<T>::~Array_t()
{
	delete[] m_elements;
}

template <class T>
const Array_t<T>& Array_t<T>::operator=(const Array_t<T>& _arr)
{
	ResizeIfNeed(_arr.m_currSize);
	memcpy(m_elements, _arr.m_elements, sizeof(T*) * _arr.Count());

	return *this;
}

template <class T>
bool Array_t<T>::Append(const T& _el, size_t _index)
{
	if(_index  + 1 <= Container_t<T>::Count())
	{	
		size_t newSize = (m_currSize > Container_t<T>::Count() ? m_currSize : m_currSize * 2);
		T** newArray = new T*[newSize];
		memcpy(newArray, m_elements, sizeof(T*) * (_index + 1));
		newArray[_index + 1] = (int*)&_el;
		memcpy(newArray+_index + 2, m_elements +_index + 1, sizeof(T*) * (Container_t<T>::Count() - _index - 1));
		delete[] m_elements;
		m_elements = newArray;
		Container_t<T>::IncreaseNumOfElements();
		m_currSize = newSize;
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Array_t<T>::Prepend(const T& _el, size_t _index)
{
	return _index > 0 ? Append(_el,_index - 1) : false;
}
 
template <class T>
bool Array_t<T>::Contains(const T& _el) const
{
	for (int i = 0, n = Container_t<T>::Count(); i < n; ++i)
	{
		if(*m_elements[i] == _el)
		{
			return true;
		}
	}
	return false;
}

template <class T>
bool Array_t<T>::Find(const T& _el) 
{
	for (int i = 0, n = Container_t<T>::Count(); i < n; ++i)
	{
		if(*m_elements[i] == _el)
		{
			memcpy(m_elements + i, m_elements + i + 1, sizeof(T*) * (Container_t<T>::Count() - i - 1));	
			Container_t<T>::DecreaseNumOfElements();		
			return true;
		}
	}
	return false;
}

template <class T>
int Array_t<T>::Index(const T& _el) const
{
	for (int i = 0, n = Container_t<T>::Count(); i < n; ++i)
	{
		if(*m_elements[i] == _el)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

template <class T>
void Array_t<T>::Insert(const T& _el)
{
	Append(_el, Container_t<T>::Count() - 1);
}

template <class T>
bool Array_t<T>::Remove(const T& _el)
{
	return Find(_el);
}

template <class T>
void Array_t<T>::RemoveAll()
{
	Container_t<T>::ZeroNumOfElements();
}
template <class T>
bool Array_t<T>::RemoveAndDelete(const T& _el)
{
	for (int i = 0, n = Container_t<T>::Count(); i < n; ++i)
	{
		if(*m_elements[i] == _el)
		{
			delete m_elements[i];
			return true;
		}
	}
	return false;
}

template <class T>
void Array_t<T>::RemoveAndDeleteAll()
{
	for(int i = 0, n = Container_t<T>::Count(); i < n; ++i)
	{
		delete m_elements[i];
	}
	
	Container_t<T>::ZeroNumOfElements();
}

#endif





































































