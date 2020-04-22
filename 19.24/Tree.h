#pragma once
#include "TreeNode.h"
#include "List.h"
#include "Queue.h"
#include <iostream>

namespace name19_24
{
	template <class T>
	class Tree
	{
		template <class U>
		friend std::ostream& operator <<(std::ostream &out, const Tree<U>& tree)
		{
			tree.inOrderTraverse(out);
			out << std::endl;
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

		void levelOrderTraverse(void) const
		{
			Queue<TreeNode<T>> queue;
			
			queue.enqueue(*root);

			while (!queue.isEmpty())
			{
				TreeNode<T> node(0);
				queue.dequeue(node);
				std::cout << node.data << " ";
				if (node.left != nullptr)
				{
					queue.enqueue(*(node.left));
				}
				if (node.right != nullptr)
				{
					queue.enqueue(*(node.right));
				}
			}

			std::cout << std::endl;
		}

		void preOrderTraverse(void) const
		{
			preOrderTraverseHelper(&root);
		}

		void preOrderTraverse(std::ostream& out) const
		{
			preOrderTraverseHelper(out, &root);
		}

		void inOrderTraverse(void) const
		{
			inOrderTraverseHelper(std::cout, &root);
		}

		void inOrderTraverse(std::ostream& out) const
		{
			inOrderTraverseHelper(out, &root);
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

		TreeNode<T>* binaryTreeSearchParent(const T& data) const
		{
			TreeNode<T>* resultPtr = nullptr;
			binaryTreeSearchParentHelper(&root, data, resultPtr);

			return resultPtr;
		}

		void outputTree(int totalSpaces) const
		{
			outputTreeHelper(root, totalSpaces);
		}

		bool deleteNode(const T& data)
		{
			return deleteNodeHelper(&root, data);
		}

		TreeNode<T>* rightMostNode(void) const
		{
			TreeNode<T>* rightMostNodePtr = nullptr;
			rightMostNodeHelper(&root, rightMostNodePtr);

			return rightMostNodePtr;
		}

	private:
		bool deleteNodeHelper(TreeNode<T>** rootPtr, const T& data)
		{
			TreeNode<T>* toBeDeleted = binaryTreeSearch(data);
			if (toBeDeleted == nullptr)
			{
				return false;
			}
			
			TreeNode<T>* parentToBeDeleted = binaryTreeSearchParent(toBeDeleted->data);
			if (toBeDeleted->isLeaf())
			{
				if (parentToBeDeleted->data > toBeDeleted->data)
				{
					parentToBeDeleted->left = nullptr;
				}
				else
				{
					parentToBeDeleted->right = nullptr;
				}
				delete toBeDeleted;
				toBeDeleted = nullptr;
				return true;
			}
			else if (toBeDeleted->left == nullptr && toBeDeleted->right != nullptr) 
			{
				if (parentToBeDeleted->data > toBeDeleted->right->data)
				{
					parentToBeDeleted->left = toBeDeleted->right;
				}
				else
				{
					parentToBeDeleted->right = toBeDeleted->right;
				}

				delete toBeDeleted;
				toBeDeleted = nullptr;
				return true;
			}
			else if (toBeDeleted->right == nullptr && toBeDeleted->left != nullptr)
			{
				if (parentToBeDeleted->data > toBeDeleted->left->data)
				{
					parentToBeDeleted->left = toBeDeleted->left;
				}
				else
				{
					parentToBeDeleted->right = toBeDeleted->left;
				}

				delete toBeDeleted;
				toBeDeleted = nullptr;
				return true;
			}
			else 
			{
				TreeNode<T>* replacementNodePtr = nullptr;
				rightMostNodeHelper(&(toBeDeleted->left), replacementNodePtr);

				TreeNode<T>* parentReplacement = binaryTreeSearchParent(replacementNodePtr->data);

				if (parentToBeDeleted != nullptr)
				{
					if (replacementNodePtr->data > parentToBeDeleted->data)
					{
						parentToBeDeleted->right = replacementNodePtr;
					}
					else
					{
						parentToBeDeleted->left = replacementNodePtr;
					}
				}
				else
				{
					root = replacementNodePtr;
				}
				
				if (replacementNodePtr->isLeaf())
				{
					if (replacementNodePtr->data < parentReplacement->data)
					{
						parentReplacement->left = nullptr;
					}
					else
					{
						parentReplacement->right = nullptr;
					}
				}
				else
				{
					if (parentReplacement->data > replacementNodePtr->left->data)
					{
						parentReplacement->left = replacementNodePtr->left;
					}
					else
					{
						parentReplacement->right = replacementNodePtr->left;
					}
				}
				replacementNodePtr->right = toBeDeleted->right;
				replacementNodePtr->left = toBeDeleted->left;
				delete toBeDeleted;
				toBeDeleted = nullptr;
			}

			return true;
		}

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

		void rightMostNodeHelper(TreeNode<T>* const*rootPtr, TreeNode<T>*& rightMostNodePtr) const
		{
			if ((*rootPtr != nullptr) && (*rootPtr)->right != nullptr)
			{
				rightMostNodeHelper(&(*rootPtr)->right, rightMostNodePtr);
			}
			else 
			{
				rightMostNodePtr = *rootPtr;
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

		void inOrderTraverseHelper(std::ostream& out, TreeNode<T>* const* rootPtr) const
		{
			if (*rootPtr != nullptr)
			{
				inOrderTraverseHelper(out, &((*rootPtr)->left));
				out << (*rootPtr)->data << ' ';
				inOrderTraverseHelper(out, &((*rootPtr)->right));
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

		void binaryTreeSearchParentHelper(TreeNode<T>* const* rootPtr, const T& data, TreeNode<T>*& outPtr) const
		{
			if (*rootPtr != nullptr)
			{
				if (((*rootPtr)->left != nullptr && data == (*rootPtr)->left->data) || ((*rootPtr)->right != nullptr && data == (*rootPtr)->right->data))
				{
					outPtr = *rootPtr;
				}
				binaryTreeSearchParentHelper(&((*rootPtr)->left), data, outPtr);
				binaryTreeSearchParentHelper(&((*rootPtr)->right), data, outPtr);
			}
		}

		TreeNode<T>* root;
	};
}