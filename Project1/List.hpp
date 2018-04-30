#include <memory>
#include <iostream>
#include <cassert>
#pragma once
template<class T> 
class List
{
private:
	struct Node;
	using node_ptr = std::shared_ptr<Node>;

	struct Node {
		T _data;
		node_ptr _next, _previous;

		Node(T mData);
		Node(T mData, node_ptr mNext, node_ptr mPrevious);
	};

	node_ptr _head, _tail;
	int _size;

	bool _way = false;
public:
	// Member functions
	List();
	List(const std::initializer_list<T> mInitializer_list);
	~List();

	// List modifiers
	void push_back(const T mValue);
	void push_front(const T mValue);
	void insert(const int mPosition, const T mValue); 

	void pop_back();
	void pop_front(); 
	void erese(const int mPostion); 

	// Priorty queue modifiers
	void push(const T mValue);
	void pop();
	T front();

	// Capacity
	bool empty();
	int size();

	// Operations
	void show();
	void swap(int mSrc, int mTrg);

	void setWay(const bool mWay);
	bool getWay(); 
};

template<class T>
inline List<T>::Node::Node(T mData)
	: Node(mData, nullptr, nullptr)
{
}

template<class T>
inline List<T>::Node::Node(T mData, node_ptr mNext, node_ptr mPrevious)
	: _data(mData), _next(mNext), _previous(mPrevious)
{
}

template<class T>
inline List<T>::List()
	: _head(nullptr), _tail(nullptr)
{
}

template<class T>
inline List<T>::List(const std::initializer_list<T> mInitializer_list)
{
	assert(mInitializer_list != nullptr)

	for (auto& element : mInitializer_list)
	{
		push_back(element);
	}
}

template<class T>
inline List<T>::~List()
{
}

template<class T>
inline void List<T>::push_back(const T mValue)
{
	if (!size())
	{
		_head = _tail = std::make_shared<Node>(mValue);
		_size++;
	}
	else 
	{
		assert(_head != nullptr);
		assert(_tail != nullptr);

		auto temp_node = std::make_shared<Node>(mValue, nullptr, _tail);
		_size++;
		_tail->_next = temp_node;
		_tail = temp_node;
	}
}

template<class T>
inline void List<T>::push_front(const T mValue)
{
	if (!size())
	{
		_head = _tail = std::make_shared<Node>(mValue);
		_size++;
	}
	else
	{
		auto temp_node = std::make_shared<Node>(mValue, _head, nullptr);
		_size++;
		_head->_previous = temp_node;
		_head = temp_node;
	}
}

template<class T>
inline void List<T>::insert(const int mPosition, const T mValue)
{
	assert(_head != nullptr);
	assert(_tail != nullptr);

	node_ptr current_node = _head;
	node_ptr previous_node;
	for (int i = 1; i <= mPosition; ++i)
	{
		previous_node = current_node;
		current_node = current_node->_next;
	}
	node_ptr new_node = std::make_shared<Node>(mValue, current_node, previous_node);
	previous_node->_next = new_node;
	current_node->_previous = new_node;
}

template<class T>
inline void List<T>::pop_back()
{
	assert(_head != nullptr);
	assert(_tail != nullptr);

	_tail = _tail->_previous;
	_tail->_next = nullptr;
	--_size;
}

template<class T>
inline void List<T>::pop_front()
{
	assert(_head != nullptr);
	assert(_tail != nullptr);

	_head = _head->_next;
	_head->_previous = nullptr;
	--_size;
}

template<class T>
inline void List<T>::erese(const int mPosition)
{
	// maybe later
}

template<class T>
inline void List<T>::push(const T mValue)
{
	if (!size())
	{
		_head = _tail = std::make_shared<Node>(mValue);
		_size++;

		assert(_head != nullptr);
		assert(_tail != nullptr);
	}
	else
	{
		assert(_head != nullptr);
		assert(_tail != nullptr);

		node_ptr node_helper = _head;

		while (node_helper)
		{
			if (node_helper->_data < mValue)
			{
				node_helper = node_helper->_next;
			}
			else
			{
				if (node_helper == _head)
				{
					node_ptr temp = std::make_shared<Node>(mValue, node_helper, nullptr);
					assert(temp != nullptr);

					node_helper->_previous = temp;
					_head = temp;
					_size++;

					return;
				}
				else
				{
					node_ptr temp = std::make_shared<Node>(mValue, node_helper, node_helper->_previous);
					assert(temp != nullptr);

					node_helper->_previous->_next = temp;
					node_helper->_previous = temp;
					_size++;

					return;
				}
			}
		}

		if (node_helper == nullptr)
		{
			node_ptr temp = std::make_shared<Node>(mValue, nullptr, _tail);
			assert(temp != nullptr);

			_tail->_next = temp;
			_size++;

			_tail = temp;
		}
	}
}

template<class T>
inline void List<T>::pop()
{
	if (size())
	{
		_size--;
		_way ? pop_front() : pop_back();
	}
}

template<class T>
inline T List<T>::front()
{
	assert(_head != nullptr);
	assert(_tail != nullptr);

	return _way ? _head->_data : _tail->_data;
}

template<class T>
inline bool List<T>::empty()
{
	return !_size;
}

template<class T>
inline int List<T>::size()
{
	return _size;
}

template<class T>
inline void List<T>::show()
{
	auto temp_node = _way ? _head : _tail;

	assert(temp_node != nullptr);

	while (temp_node)
	{
		std::cout << temp_node->_data << std::endl;
		temp_node = _way ? temp_node->_next : temp_node->_previous;
	}
}

template<class T>
inline void List<T>::swap(int mSrc, int mTrg)
{
	node_ptr src = nullptr, trg = nullptr;

	node_ptr node_helper{ _head };
	assert(node_helper != nulltpr);
	int counter{ 0 };

	while (node_helper)
	{
		if (counter == mSrc)
		{
			src = node_helper;
		}
		else if (counter == mTrg)
		{
			trg = node_helper;
		}

		if (trg && src)
		{
			assert(trg != nullptr);
			assert(src != nullptr);
			std::swap(src->_data, trg->_data);
			return;
		}
		
		++counter;
		node_helper = node_helper->_next;
	}
}

template<class T>
inline void List<T>::setWay(const bool mWay)
{
	_way = mWay;
}

template<class T>
inline bool List<T>::getWay()
{
	if (_way)
	{
		std::cout << "Rosnaco" << std::endl;
	}
	else
	{
		std::cout << "Malejaco" << std::endl;
	}
	return _way;
}
