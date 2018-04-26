#include <memory>
#include <iostream>
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
public:
	// Member functions
	List();
	List(std::initializer_list<T> mInitializer_list);
	~List();

	// Modifiers
	void push_back(T mValue);
	void push_front(T mValue);
	void insert(int mPosition, T mValue); // do poprawy

	// Capacity
	bool empty();
	int size();

	// Operations
	void show();
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
inline List<T>::List(std::initializer_list<T> mInitializer_list)
{
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
inline void List<T>::push_back(T mValue)
{
	if (_tail == nullptr)
	{
		_head = _tail = std::make_shared<Node>(mValue);
		_size++;
	}
	else 
	{
		auto temp_node = std::make_shared<Node>(mValue, nullptr, _tail);
		_size++;
		_tail->_next = temp_node;
		_tail = temp_node;
	}
}

template<class T>
inline void List<T>::push_front(T mValue)
{
	if (_head == nullptr)
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
inline void List<T>::insert(int mPosition, T mValue)
{
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
	auto temp_node = _head;
	while (temp_node)
	{
		std::cout << temp_node->_data << std::endl;
		temp_node = temp_node->_next;
	}
}