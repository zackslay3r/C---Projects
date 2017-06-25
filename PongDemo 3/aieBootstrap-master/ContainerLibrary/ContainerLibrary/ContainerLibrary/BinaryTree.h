#pragma once
#include "Exeception.h"

/*
* class BinaryTree
*
* This is my BinaryTree class and is a customer container that will be used for m_registeredstates as the states that are stored in my game.
* We are using this since we doing care about the order of our registered states. we just want to check to see if we have a state of a certain name.
*
* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
*/
template <class T, class U>
class BinaryTree
{
	
	/*
	* struct TreeNode
	*
	* This is a TreeNode. This is what each item in the binaryTree is based off of.
	*
	* @author - Zackary Direen, Academy of Interactive Entertainment, 2017
	*/
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

	/*	void Insert(T newKey, U newValue, TreeNode* &theRoot)
	*	This function allows for the insertion of a new treeNode.
	*
	*
	*	@param1 newKey - the key that we want our value to have. this is for accessing it.
	*
	*	@param2 newValue - The value stored within the location for the key.
	*
	*	@param3 &theRoot - This is the root treenode of this tree.
	*
	*	@returns void.
	*/
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

	/*	void RemoveTree(TreeNode* theRoot)
	*	This function will delete a tree from theRoot downwards.
	*
	*
	*
	*	@param1 &theRoot - This is the root treenode of this tree.
	*
	*	@returns void.
	*/
	void RemoveTree(TreeNode* theRoot)
	{
		if (theRoot != NULL)
		{
			RemoveTree(theRoot->left);
			RemoveTree(theRoot->right);
			delete theRoot;
		}
		
	}

	/*	U &Search(TreeNode *theRoot, const T &key)
	*	This function will search though the tree from the root and return the value within the key if found.
	*
	*
	*
	*	@param1 *theRoot - This is the root treenode of this tree.
	*
	*	@param2 const T &key - This is the key of a treenode.
	*
	*	@returns U - a value of a treeNode.
	*/
	U &Search(TreeNode *theRoot, const T &key)
	{
		
		
		if (!theRoot)
		{
			eTHROW("Tried to access a list that doesnt exist.");
		}
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
			eTHROW("Tried to access a value in the list that is not avalible.");
		}
	}

public:
	/*
	* BinaryTree()
	*
	* This is the BinaryTree constructor.
	*
	*/
	BinaryTree()
	{
		root = NULL;
	}
	/*	void AddItem(T newKey, U newValue)
	*	This function will call the insert function with the parameters passed.
	*
	*
	*
	*	@param1 newKey - This is the key of a treenode.
	*
	*	@param2 U - a value of a treeNode.
	*
	*	@returns void.
	*/
	void AddItem(T newKey, U newValue)
	{
		Insert(newKey, newValue, root);
	}

	/*	void U &operator [] (T newKey)
	*	This function will call the search function with the parameters passed.
	*
	*
	*
	*	@param1 newKey - This is the key of a treenode.
	*
	*
	*	@returns U - a value of a treeNode.
	*/
	U &operator [] (T newKey)
	{
		return Search(root, newKey);
	
	}
	/*	void clear()
	*	This function will call the RemoveTree functiopn from the root onwards, deleting the whole tree, then sets the root to nullptr.
	*
	*	@returns void.
	*/
	void clear()
	{
		RemoveTree(root);
		root = nullptr;
	}

};