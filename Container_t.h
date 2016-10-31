#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include <cstddef>

template <class T>
class Container_t
{
	public:
		Container_t():m_numOfElements(0){}
		virtual ~Container_t() {};
		virtual bool Append(const T& _el, size_t _index) = 0;		
		virtual bool Prepend(const T& _el, size_t _index) = 0;
		virtual bool Contains(const T& _el) const = 0;
		inline size_t Count() const { return m_numOfElements; }
		virtual bool Find(const T& _el) = 0;
		virtual int Index(const T& _el) const = 0;
		virtual void Insert(const T& _el) = 0;
		bool IsEmpty() const { return m_numOfElements == 0; }
		virtual bool Remove(const T& _el) = 0;
		virtual void RemoveAll() = 0;
		virtual bool RemoveAndDelete(const T& _el) = 0;
		virtual void RemoveAndDeleteAll() = 0;	
		
	protected:
		void IncreaseNumOfElements() { ++m_numOfElements; }
		void DecreaseNumOfElements(){ --m_numOfElements; }
		void ZeroNumOfElements() { m_numOfElements = 0; }

	private:
		size_t m_numOfElements;
};

#endif













































