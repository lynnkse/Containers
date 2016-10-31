template <class T>
class Container
{
	public:
		Container_t();
		virtual ~Container_t() = 0;
		virtual bool Append(const T& _el, size_t _index) = 0;		
		virtual bool Prepend(const T& _el, size_t _index) = 0;
		virtual bool Contains(const T& _el) const = 0;
		virtual size_t Count() const = 0;
		virtual bool Find(const T& _el) const = 0;
		virtual size_t Index(const T& _el) const = 0;
		virtual void Insert(const T& _el) = 0;
		virtual bool IsEmpty() const = 0;
		virtual bool Remove(const T& _el) = 0;
		virtual void RemoveAll() = 0;
		virtual bool RemoveAndDelete(const T& _el) = 0;
		virtual void RemoveAndDeleteAll() = 0;	

	private:
		size_t m_numOfElements;
};















































