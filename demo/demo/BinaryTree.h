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
		else
		{
			Insert(newKey, newValue, theRoot->right);
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



};