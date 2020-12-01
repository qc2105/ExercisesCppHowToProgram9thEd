#pragma once
#include <iostream>

namespace name19_24
{
	template <class T>
	class TreeNode
	{
		template <class U>
		friend std::ostream& operator << (std::ostream& out, TreeNode<U>& node)
		{
			out << node.data << ' ';
			return out;
		}

		template <class V>
		friend std::istream& operator >> (std::istream& in, TreeNode<V>& node)
		{
			in >> node.data;
			return in;
		}

	public:

		explicit TreeNode(const T& _data) :
			data(_data),
			left(nullptr),
			right(nullptr)
		{}

		bool operator==(TreeNode<T>& b)
		{
			return this->data == b.data;
		}

		bool isLeaf(void)
		{
			return this->left == nullptr && this->right == nullptr;
		}

		T data;
		TreeNode<T>* left;
		TreeNode<T>* right;
	};
}