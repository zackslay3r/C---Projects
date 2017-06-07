# TODO!

# CUSTOM CONTAINERS

	Binary Search Tree

	Stack

	Doubly Linked List
	
		LinkedList.h, LinkedListIterator.h
		
		- Copy constructor and Assignment operators defined.
		
		- Accepts construction by Initialiser List http://www.cplusplus.com/reference/initializer_list/initializer_list/
			Eg: 
				LinkedList<int> fred; 
				fred = { 1, 2, 3 };
		
		- LinkedList uses begin() and end() functions that return iterators set to start and end of the list. The end
		of the list is a sentinel node past the last element in the list. 
		Iterators may be dereferenced to access the stored node value.
		https://en.wikipedia.org/wiki/Linked_list#Sentinel_nodes
		This is required for compatibility with C++11 features such as the "auto" keyword for use in loops.
		http://en.cppreference.com/w/cpp/language/range-for
		
		Eg:
			
			//Iterate over every element in myLinkedList.
			for (auto &var : myLinkedList)
			{
				//Do stuff here where "var" is each element.
				//...
			}
			
			//Iterate over every element in myLinkedList.
			for (it = myLinkedList.begin(); it != myLinkedList.begin(); it++)
			{
				//Do stuff here where "*it" is each element.
				//...
			}
			
	NOTE: std::vector is used in some limited places where external libraries require a std::vector for input.
	In particular this applies to any functions dealing with the Maths Library class "Shape2" which requires a
	std::vector as input for the list of shape vertices.

# OTHER NOTABLE FEATURES

	- The object pooler uses a binary tree of stacks, combining two of my custom containers into one data structure.

	- I use a custom namespace "ContLib" to ensure my custom container classes don't conflict with other libraries.
	
	- All functions are const correct where appropriate.
	

# UPDATES TO THE GAME

Other update since the last version of the game include:

- The asset manager now loads fonts and textures automatically into the pool the first time they are 
requested, so they no longer need to be pre loaded.

- The game window now adapts to the detected screen resolution, rather than being a fixed size.

- Full screen mode is now available.

- Physics updates are now synced with the monitor refresh rate to eliminate stuttering.

- Mouse cursor is hidden during full screen mode.

- Complex objects have been added, utilising the full capability of the SAT collision detection system. 
Some of the new objects that have up to 8 sides on a single collider polygon (such as the crumpled
paper ball), or multiple colliders per single object (such as the computer) which is required when the 
overall object shape is concave (which breaks SAT), so it needs to be broken down into a number of smaller 
convex shapes.

- Added a variety of new junk objects including crumpled paper, pizza slices, the Mona Lisa, a meat cleaver, 
a basket ball, a computer, canned squid, a wooden ruler, a chip packet and a tennis ball.