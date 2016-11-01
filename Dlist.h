#define NOT_FOUND -1

template <class T>
class Dlist_t : public Container_t<T>
{
	public:
		Dlist_t();
		Dlist_t(const Dlist_t& _arr);
		virtual ~Dlist_t();
		virtual const Dlist_t<T> operator=(const Dlist_t& _arr);
		virtual bool Append(const T* _el, size_t _index);		
		virtual bool Prepend(const T* _el, size_t _index);
		virtual bool Contains(const T& _el) const;
		virtual const T* Find(const T& _el) const;
		virtual int Index(const T& _el) const;
		virtual void Insert(const T* _el);
		virtual bool Remove(const T& _el);
		virtual void RemoveAll();
		virtual bool RemoveAndDelete(const T& _el);
		virtual void RemoveAndDeleteAll();	

	private:
		
		template <class NODE_TYPE>		
		class Node_t
		{
			public:
				Node_t(){};
				Node_t(const Node_t<T>& _next, const Node_t<T>& _prev, const T& _data):m_next(&_next), m_prev(&_prev), m_data(&_data) {}
				~Node_t(){};	
													
				Node_t* m_next;
				Node_t* m_prev;
				const T* m_data;
		};
	
	private:
		Node_t<T> m_head;
		Node_t<T> m_tail;
};

template <class T>
Dlist_t<T>::Dlist_t()
{
	m_head.m_next = &m_tail;
	m_tail.m_prev = &m_head;
}

template <class T>
Dlist_t<T>::~Dlist_t(){}

template <class T>	
Dlist_t<T>::Dlist_t(const Dlist_t& _arr)
{
	const Node_t<T>* node = &(_arr.m_head);
	node = node->m_next;		
	for(size_t i = 0; i < _arr.Count(); ++i)
	{
		T* newData = new T();
		*newData = *(node->m_data);			
		Insert(newData);
		node = node->m_next;
	}
}

template <class T>
const Dlist_t<T> Dlist_t<T>::operator=(const Dlist_t& _arr)
{
	if(this != &_arr)
	{	
		RemoveAll();
		Container_t<T>::operator=(_arr);
		const Node_t<T>* node = &(_arr.m_head);
		node = node->m_next;		
		for(size_t i = 0; i < _arr.Count(); ++i)
		{
			T* newData = new T();
			*newData = *(node->m_data);			
			Insert(newData);
			node = node->m_next;
		}
	}

	return *this;
}

template <class T>
bool Dlist_t<T>::Append(const T* _el, size_t _index)
{
	if(_index  + 1 <= Container_t<T>::Count())
	{
		Node_t<T>* currNode = &m_head;
		for(size_t i = 0; i < _index + 1; ++i)
		{
			currNode = currNode->m_next;
		}
		
		Node_t<T>* newNode = new Node_t<T>();
		if(!newNode)
		{
			throw("Memory allocation error");
		}

		newNode->m_next = currNode->m_next;
		newNode->m_prev = currNode;
		newNode->m_data = _el;

		currNode->m_next->m_prev = newNode;
		currNode->m_next = newNode;
		Container_t<T>::IncreaseNumOfElements();
		
		return true;
	}
	else
	{
		return false;
	}
}	

template <class T>
bool Dlist_t<T>::Prepend(const T* _el, size_t _index)
{
	return _index > 0 ? Append(_el,_index - 1) : false;
}

template <class T>
bool Dlist_t<T>::Contains(const T& _el) const
{
	return (bool) Find(_el);
}

template <class T>
const T* Dlist_t<T>::Find(const T& _el) const
{
	const Node_t<T>* node = &m_head;
	node = node->m_next;		
	for(; node != &m_tail; node = node->m_next)
	{
		if(*(node->m_data) == _el)
		{		
			return node->m_data;
		}
	}
	
	return 0;
}

template <class T>
int Dlist_t<T>::Index(const T& _el) const
{
	int index = 0;
	const Node_t<T>* node = (Dlist_t<int>::Node_t<int>*)&m_head;
	node = node->m_next;
	for(; node != &m_tail; node = node->m_next)
	{
		if(*(node->m_data) == _el)
		{
			return index; 
		}
		++index;
	}
	
	return NOT_FOUND;
}

template <class T>
void Dlist_t<T>::Insert(const T* _el)
{
	Append(_el, Container_t<T>::Count() - 1);
}

template <class T>
bool Dlist_t<T>::Remove(const T& _el)
{
	const Node_t<T>* node = &m_head;
	node = node->m_next;		
	for(; node != &m_tail; node = node->m_next)
	{
		if(*(node->m_data) == _el)
		{
			node->m_prev->m_next = node->m_next;
			node->m_next->m_prev = node->m_prev;			
			delete node;
			Container_t<T>::DecreaseNumOfElements();
			return true;
		}
	}
return false;
}

template <class T>
void Dlist_t<T>::RemoveAll()
{
	const Node_t<T>* node = &m_head;
	node = node->m_next;	
	node = node->m_next;	
	for(; node != &m_tail; node = node->m_next)
	{
		delete node->m_prev;
	}
	delete node->m_prev;
	m_head.m_next = &m_tail;
	m_tail.m_prev = &m_head;
}

template <class T>
bool Dlist_t<T>::RemoveAndDelete(const T& _el)
{
	const Node_t<T>* node = &m_head;
	node = node->m_next;	
	for(; node != &m_tail; node = node->m_next)
	{
		if(*(node->m_data) == _el)
		{
			node->m_prev->m_next = node->m_next;
			node->m_next->m_prev = node->m_prev;	
			delete node->m_data;		
			delete node;
			Container_t<T>::DecreaseNumOfElements();

			return true;
		}
	}
	
	return false;
}

template <class T>
void Dlist_t<T>::RemoveAndDeleteAll()
{
	const Node_t<T>* node = &m_head;
	node = node->m_next;	
	node = node->m_next;	
	for(; node != &m_tail; node = node->m_next)
	{
		delete node->m_prev->m_data;
		delete node->m_prev;
	}
	delete node->m_prev;
	m_head.m_next = &m_tail;
	m_tail.m_prev = &m_head;
}




























