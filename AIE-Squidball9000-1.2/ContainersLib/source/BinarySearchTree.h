#pragma once

/**
* A template class binary search tree container.
* https://en.wikipedia.org/wiki/Binary_search_tree
* Used for storing key/value pairs.
* This BST does NOT allow duplicate keys. Inserting a duplicate will overwrite any existing key/value pair
* with the same key.
* NOTE: Object type used for key must have comparison operators defined. Eg: obj1 < obj2.
* This is required to determine on which side of each node a key will be placed.
* @author Ashley Flynn - AIE - 2017.
*/
namespace ContLib
{

    template <class T, class U>
    class BinarySearchTree
    {
    public:

        /**
        * Default constructor.
        */
        BinarySearchTree() { root = nullptr; };

        /**
        * Default destructor.
        */
        ~BinarySearchTree() {
            if (root) deleteRecursively(root);
			root = nullptr;
        };

        /**
        * Operator[]. Gets the value for an associated key.
        * @returns A reference to the value matching the key.
        */
        U &operator[](T key)
        {
           return searchRecursively(root, key);
        };

        /**
        * Operator[]. Gets the value for an associated key.
        * CONST SAFE version.
        * @returns The value matching the key.
        */
        U operator[](T key) const
        {
            return searchRecursively(root, key);
        };

        template <class T, class U>
        class BinarySearchTreeNode;

        /**
        * The root node of the tree.
        */
        BinarySearchTreeNode<T, U> *root;

        /**
        * Insert a key/value pair into the tree.
        * @params key The key to insert.
        * @params value The value to insert.
        * @returns void.
        */
        inline void insert(T key, U value) 
		{
            if (!root)
            {
                root = insertN(root, key, value);
            }
            else
            {
                insertN(root, key, value);
            }
        };

		/**
		* Get a count of the number of instances of a key in the tree.
		* @params The key to search for.
		* @returns The count of the number of instances of the key.
		*/
		inline int count(const T &key) const
		{
            if (!root) return 0;
			return countRecursively(root, key);
		};

        /**
        * Clear the tree.
        * @returns void.
        */
        inline void clear()
        {
            deleteRecursively(root);
            root = nullptr;
        };

    private:

        /**
        * An node of the tree.
        */
        template <class T, class U>
        class BinarySearchTreeNode
        {
        public:

            /**
            * Default constructor.
            */
            BinarySearchTreeNode() { left = nullptr; right = nullptr; };

            /**
            * Construct with key and value pair.
            */
            BinarySearchTreeNode(T newKey, U newValue) 
            { 
                 key = newKey; value = newValue; left = nullptr; right = nullptr;
            };

            /**
            * Default destructor.
            */
            ~BinarySearchTreeNode() {};

            /**
            * Key object.
            */
            T key;

            /**
            * Stored value object.
            */
            U value;

            BinarySearchTreeNode<T, U> *left;
            BinarySearchTreeNode<T, U> *right;
        };

        /**
        * Insert a key/value pair into the tree starting at a target node.
        * @params node A pointer to the target node.
        * @params key The key to insert.
        * @params value The value to insert.
        * @returns void.
        */
        inline BinarySearchTreeNode<T, U> *insertN(BinarySearchTreeNode<T, U> *node, T key, U value)
        {
            if (!node)
            {
                node = new BinarySearchTreeNode<T, U>(key, value);
            }
            else if (key < node->key)
            {
                node->left = insertN(node->left, key, value);
            }
            else if (key > node->key)
            {
                node->right = insertN(node->right, key, value);
            } 
            else
            {
                node->value = value;
            }
            return node;
        };

        /**
        * Search recusively for a key and return a reference its value.
        * @params node A pointer to the node to start searching from.
        * @params key The key to search for.
        * @returns A reference to the node's stored value, when found.
        */
        inline U &searchRecursively(BinarySearchTreeNode<T, U> *node, const T &key)
        {
            //Invalid node or key not found in the tree.
            if (!node) throw;

            if (node->key == key)
            {
                return node->value;
            }
            else if (key < node->key)
            {
                return searchRecursively(node->left, key);
            }
            else if (key > node->key)
            {
                return searchRecursively(node->right, key);
            }
            else
            {
                throw;
            }
        }

        /**
        * Search recusively for a key and return a reference its value.
        * CONST SAFE VERSION.
        * @params node A pointer to the node to start searching from.
        * @params key The key to search for.
        * @returns A reference to the node's stored value, when found.
        */
        inline U &searchRecursively(BinarySearchTreeNode<T, U> *node, const T &key) const
        {
            //Invalid node or key not found in the tree.
            if (!node) throw;

            if (node->key == key)
            {
                return node->value;
            }
            else if (key < node->key)
            {
                return searchRecursively(node->left, key);
            }
            else if (key > node->key)
            {
                return searchRecursively(node->right, key);
            }
            else
            {
                throw;
            }
        }

        /**
        * Count recursively all instances of a given key.
        * @params node A pointer to the node to start searching from.
        * @params key The key to search for.
        * @returns The count of instances of the key.
        */
        inline int countRecursively(BinarySearchTreeNode<T, U> *node, const T &key) const
        {
            int count = 0;
            if (!node) return 0;
            if (node->key == key) count++;
            if (node->left) count += countRecursively(node->left, key);
            if (node->right) count += countRecursively(node->right, key);
            return count;
        }

        /**
        * Delete all nodes starting with a given target node.
        * @params node A pointer to the node to start deleting from.
        * @returns void.
        */
        inline void deleteRecursively(BinarySearchTreeNode<T, U> *node)
        {
            if (!node) return;
           
            if (node->left) deleteRecursively(node->left);
            if (node->right) deleteRecursively(node->right);
 
            delete node;

        }
    };
}