template <class T>
class Dlist_t : public Container_t<T>
{
	public:
		Dlist_t();
		Dlist_t(const Dlist_t& _arr);
		virtual ~Dlist_t();
		virtual const Dlist_t<T> operator=(const Dlist_t& _arr);
		virtual bool Append(const T& _el, size_t _index);		
		virtual bool Prepend(const T& _el, size_t _index);
		virtual bool Contains(const T& _el) const;
		virtual bool Find(const T& _el) const;
		virtual size_t Index(const T& _el) const;
		virtual void Insert(const T& _el);
		virtual bool IsEmpty() const;
		virtual bool Remove(const T& _el);
		virtual void RemoveAll();
		virtual bool RemoveAndDelete(const T& _el);
		virtual void RemoveAndDeleteAll();		
	private:
		T* m_head;//NODE
		T* m_tail;
};
