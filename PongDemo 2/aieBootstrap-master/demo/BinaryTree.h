#pragma once
template <class T, class U>
class BinaryTree
{
	

	struct TreeNode
	{
		T key;
		U value;


		TreeNode* left;
		TreeNode* right;

		TreeNode(T newKey, U newValue)
		{
			key = newKey;
			value = newValue;
			left = NULL;
			right = NULL;
			
		}

	};

private:
	TreeNode* root;

	void Insert(T newKey, U newValue, TreeNode* &theRoot)
	{
		if (theRoot == NULL)
		{
			theRoot = new TreeNode(newKey, newValue);
				return;
		}
		if (newKey < theRoot->key)
		{
			Insert(newKey, newValue, theRoot->left);
		}
		else if(newKey > theRoot->key)
		{
			Insert(newKey, newValue, theRoot->right);
		}
		else
		{
			theRoot->value = newValue;
		}

	}

	void PrintTree(TreeNode* theRoot)
	{
		if (theRoot != NULL)
		{
			PrintTree(theRoot->left);
			std::cout << theRoot->key << theRoot->value << std::endl;
			PrintTree(theRoot->right);
		}

	}


	void RemoveTree(TreeNode* theRoot)
	{
		if (theRoot != NULL)
		{
			RemoveTree(theRoot->left);
			RemoveTree(theRoot->right);
			delete theRoot;
		}
		
	}


	U &Search(TreeNode *theRoot, const T &key)
	{
		
		

		if (theRoot->key == key)
		{
			return theRoot->value;
		}
		else if (key < theRoot->key)
		{
			return Search(theRoot->left, key);
		}
		else if (key > theRoot->key)
		{
			return Search(theRoot->right, key);
		}
		else
		{
			throw("Out of bounds.");
		}
	}

public:
	BinaryTree()
	{
		root = NULL;
	}

	void AddItem(T newKey, U newValue)
	{
		Insert(newKey, newValue, root);
	}

	void PrintTree()
	{
		PrintTree(root);
	}

	U &operator [] (T newKey)
	{
		return Search(root, newKey);
	
	}

	void clear()
	{
		RemoveTree(root);
		root = nullptr;
	}

};