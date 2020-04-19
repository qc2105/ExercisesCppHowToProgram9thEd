#pragma once
#include "TreeNode.h"
#include "List.h"
#include <iostream>

namespace name19_26
{
	template <class T>
	class Tree
	{
		template <class U>
		friend std::ostream& operator <<(std::ostream &out, const Tree<U>& tree)
		{
			tree.preOrderTraverse(out);
			return out;
		}

		template<class V>
		friend std::istream& operator>>(std::istream& in, Tree<V>& tree)
		{
			V temp;
			while (in >> temp)
			{
				tree.insertNode(temp);
			}

			return in;
		}
	public:
		Tree(void) :
			root(nullptr)
		{

		}

		//copy constructor
		Tree(const Tree& b)
		{
			copyHelper(&(b.root));
		}

		~Tree()
		{
			detor(&root);
		}

		void insertNode(const T& data)
		{
			return insertNodeHelper(&root, data);
		}

		void preOrderTraverse(void) const
		{
			preOrderTraverseHelper(&root);
		}

		void preOrderTraverse(std::ostream& out) const
		{
			preOrderTraverseHelper(out, &root);
		}

		void father(const T& data, TreeNode<T>*& father) const
		{
			father = nullptr;
			fatherHelper(&root, data, father);
		}

		void leafs(List<T>& leafsList) const
		{
			leafsHelper(&root, leafsList);
		}

		const TreeNode<T>& rootNode(void) const
		{
			return *root;
		}

		size_t depth(void) const
		{
			List <List<T>> paths;
			leafsToRootPaths(paths);

			size_t level = 0;
			for (size_t i = 0; i < paths.size(); ++i)
			{
				if (paths[i].size() > level)
				{
					level = paths[i].size();
				}
			}

			return level;
		}

		void leafsToRootPaths(List < List<T> >& paths) const
		{
			List<T> leafsList;

			leafs(leafsList);

			for (size_t i = 0; i < leafsList.size(); i++)
			{
				TreeNode<T>* ptr = nullptr;
				T node = leafsList[i];

				List<T> leafsToRootPath;
				leafsToRootPath.insertAtBack(node);

				father(node, ptr);
				while (ptr != nullptr && ptr->data != root->data)
				{
					node = ptr->data;
					leafsToRootPath.insertAtBack(node);
					father(node, ptr);
				}
				leafsToRootPath.insertAtBack(root->data);

				paths.insertAtBack(leafsToRootPath);
			}
		}

		TreeNode<T>* binaryTreeSearch(const T& data) const
		{
			TreeNode<T>* resultPtr = nullptr;
			binaryTreeSearchHelper(&root, data, resultPtr);

			return resultPtr;
		}

		void outputTree(int totalSpaces) const
		{
			outputTreeHelper(root, totalSpaces);
		}

	private:
		void outputTreeHelper(TreeNode<T>* currentPtr, int totalSpaces) const
		{
			if (currentPtr != nullptr)
			{
				outputTreeHelper(currentPtr->right, totalSpaces+5);
				for (size_t i = 0; i < totalSpaces; ++i)
				{
					std::cout << ' ';
				}
				std::cout << currentPtr->data << std::endl;
				outputTreeHelper(currentPtr->left, totalSpaces + 5);
			}
		}

		void insertNodeHelper(TreeNode<T>** rootPtr, const T& data)
		{
			if (*rootPtr != nullptr)
			{
				if (data < (*rootPtr)->data)
				{
					insertNodeHelper(&((*rootPtr)->left), data);
				}
				else if (data > (*rootPtr)->data)
				{
					insertNodeHelper(&((*rootPtr)->right), data);
				}
				else
				{
					std::cout << "duplicate\n";
				}
			}
			else
			{
				TreeNode<T>* newNode = new TreeNode<T>(data);
				*rootPtr = newNode;
			}
		}

		void detor(TreeNode<T>** rootPtr)
		{
			if (*rootPtr != nullptr)
			{
				detor(&((*rootPtr)->left));
				detor(&((*rootPtr)->right));			
				delete *rootPtr;
				*rootPtr = nullptr;
			}
		}

		void copyHelper(TreeNode<T>** bRootPtr)
		{
			if (*bRootPtr != nullptr)
			{
				this->insertNode((*bRootPtr)->data);
				copyHelper(&((*bRootPtr)->left));
				copyHelper(&((*bRootPtr)->right));
			}
		}

		void preOrderTraverseHelper(TreeNode<T>*const * rootPtr) const
		{
			if (*rootPtr != nullptr)
			{
				std::cout << (*rootPtr)->data << ' ';
				preOrderTraverseHelper(&((*rootPtr)->left));
				preOrderTraverseHelper(&((*rootPtr)->right));
			}
		}

		void preOrderTraverseHelper(std::ostream& out, TreeNode<T>*const * rootPtr) const
		{
			if (*rootPtr != nullptr)
			{
				out << (*rootPtr)->data << ' ';
				preOrderTraverseHelper(out, &((*rootPtr)->left));
				preOrderTraverseHelper(out, &((*rootPtr)->right));
			}
		}

		void fatherHelper(TreeNode<T>* const* rootPtr, const T& data, TreeNode<T>*& father) const
		{
			if (*rootPtr != nullptr)
			{
				if (((*rootPtr)->left && (*rootPtr)->left->data == data) ||
					((*rootPtr)->right && (*rootPtr)->right->data == data))
				{
					father = *rootPtr;
					return;
				}
				fatherHelper(&((*rootPtr)->left), data, father);
				fatherHelper(&((*rootPtr)->right), data, father);
			}
		}

		void leafsHelper(TreeNode<T>* const* rootPtr, List<T>& leafsList) const
		{
			if (*rootPtr != nullptr)
			{
				if ((*rootPtr)->left == nullptr && (*rootPtr)->right == nullptr)
				{
					leafsList.insertAtBack((**rootPtr).data);
				}
				leafsHelper(&((*rootPtr)->left), leafsList);
				leafsHelper(&((*rootPtr)->right), leafsList);
			}
		}

		void binaryTreeSearchHelper(TreeNode<T>* const* rootPtr, const T& data, TreeNode<T>*& outPtr) const
		{
			if (*rootPtr != nullptr)
			{
				if (data == (*rootPtr)->data)
				{
					outPtr = *rootPtr;
				}
				binaryTreeSearchHelper(&((*rootPtr)->left), data, outPtr);
				binaryTreeSearchHelper(&((*rootPtr)->right), data, outPtr);
			}
		}

		TreeNode<T>* root;
	};
}