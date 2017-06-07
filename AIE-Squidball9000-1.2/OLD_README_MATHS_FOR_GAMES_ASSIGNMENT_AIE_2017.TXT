# SQUIDBALL 9000 v1.0 by Ashley Flynn - AIE - 2017

FILES AND VISUAL STUDIO

The pre compiled game for distribution can be found under "bin" at the top level.

The game demo project is called "project2D".

My custom maths library is included as a .lib and header files under "MathsLib".

NOTE: If you delete the contents of project2D/bin, the you MUST copy the files from 
project2D/dependencies_copy into the bin folder again.


GAME RULES

Two squids are playing a very strange game of underwater soccer.

Only the large white ball will score points when it passes through a goal.

The ball speeds up over time, providing an increasing challenge as each round progresses.

The squids have randomly flailing limbs that provide the capability for steeply angled shots.

The first player to 5 points wins. The losing squid explodes into pieces out of shame.

The squids have a very messy playing field, often covered in sticky garbage that can get stuck to the ball.

We won't ask them why.

Junk makes the ball movement much harder to predict and anticipate. Junk may break off the ball at any time,
further adding to the confusion.

If the ball is held/pinned by a squid or is forced out of bounds without passing through a goal, it resets 
to the middle of the playing field automatically without a goal being scored.

The ball is slippery, so will generally wiggle itself free no matter how hard the squids try to pin it down.

The game supports play between two human players, a human and an AI, or two AI players. The player type and 
AI difficulty level can be set in the menu. 

The amount of junk randomly placed on the playing field can also be set in the menu.


GAME CONTROLS

The left player controls are W for Up and S for Down.

The right player controls are UpArrow for Up and DownArrow for down.

Press M at any time during game play to pause and return to the menu.

Onscreen hints for the keys are visible during gameplay.


# FEATURES AND ASSIGNMENT REQUIREMENTS


MATHS LIBRARY

My own maths library is used for all matrix and vector mathematics and classes.


USER INTERACTION

I have attempted to make a complete finished game, which features user interaction at its core.


MATRICES

Every entity has a local matrix and global matrix, which are concatenated to determine the entity's position
and rotation. The matrices, along with a parent/child relationship defined by pointers, are also used to 
achieve a matrix hierarchy.

Examples of this in use include:
	
	- Updating entity matrix relative to its parent entity's matrix; 
		line 241, Entity::updateMatrixHeirarchy(), Entity.cpp
	
	- Joining entities together in a matrix hierarchy; Entity::fuseTo(), line 463 in Entity.cpp.
	
	- Drawing sprites; line 412 in Entity::draw(), Entity.cpp.

My matrices are passed directly to OpenGL via bootstrap when rendering sprites.
Eg: "renderer->drawSpriteTransformed3x3(....)" line 414 in Entity::draw(), Entity.cpp.

I use complex matrix maths in many places including:

	- Using matrix inverse (not to be confused with matrix transpose) for converting between local space 
	and	world space coordinates. See Entity::fuseTo(), line 463 in Entity.cpp.

	- Using matrix decomposition (extracting rotation, translation, etc raw values out of the matrix).
	Line 114, Entity::setParent(), Entity.cpp.
	Line 189, Entity::clampRotation(), Entity.cpp.

	- Calculating and applying translation offset for sprites, so the middle of the sprite lines up with 
	object origin, rather than sprite bottom-left corner at origin which is the default.
	Line 412 in Entity::draw(), Entity.cpp.


MATRIX HIERARCHIES

As entities have the general ability to connect to any other entity (parent) in any combination, or have any
number of entities connected to them (children), they can be assembled into hierarchies of unlimited depth 
and complexity.

The core of the hierarchy system is how entities update their matrices based on their parent's global matrix,
as seen at line 241, Entity::updateMatrixHeirarchy(), Entity.cpp. This process then causes all the entity's
children to automatically update their matrices in turn.


COUPLING AND DECOUPLING

The ball couples with any junk objects it touches. Junk coupled to the ball will couple with any junk it
touches, and so on. This dynamic realtime coupling may create infinitely complex and branching matrix 
hierarchies.

Coupling occurs at line 149, PhysicsCalculator::resolveCollision(), PhysicsCalculator.cpp, where coupling is 
initiated, and Entity::fuseTo(), line 463 in Entity.cpp, where an object sets its matrices to a position
relative to the new parent's local space.

Decoupling occurs at line line 131, PhysicsCalculator::resolveCollision(), PhysicsCalculator.cpp, where
decoupling may happen at random on impact, which triggers line 114, Entity::setParent(), Entity.cpp, where 
objects set themselves as a top level entity, with no parent above them, and so their position becomes 
relative to world space once more.

The connection with coupled objects is fragile (simulated by a random chance to decouple on every impact) 
meaning that parts of the junk conglomerate may break off. One piece may break off the tip of a chain of
junk, or whole branched sections may come away as a single lump. The branched relationship is maintained 
if whole sections of junk break away, with the topmost piece of junk in the hierarchy becoming the new 
top level parent. See line 131, PhysicsCalculator::resolveCollision(), PhysicsCalculator.cpp.

The losing squid explodes (decouples) into its component entities. Each entity is then given random spin and
velocity, and the disintegrated pieces of squid automatically delete themselves after a set time.
See line 333, Squid::explode(), Squid.cpp.

I'd suggest starting a game with the maximum possible junk setting and two AI players to easily observe the 
complex and often surprising effects of dynamic coupling and decoupling of junk at its best.


COLLISION DETECTION

My game engine supports collision detection between any combination of lines, circles and convex polygons 
with any number of sides. I have included a variety of these shapes in the game to demonstrate this.

See the CollisionDetector class.

I have used a combination of AABB, Separating Axis Theorem and Support Points to achieve accurate collision 
detection. AABB is used as a broadphase detection system to quickly check what objects are likely to be 
colliding. Then a more expensive Separating Axis Theorem test determines whether objects truly collided.

Support Points are then calculated to determine an exact point of contact, which is essential information 
for an accurate physics simulation.

Collision contact points are marked on screen in real time by a small faint dull-yellow dot.

Objects in a matrix hierarchy act like a single object from the point of view of collision detection.

Entities can have any number of colliders attached to them.

NOTE: The inner two legs of the squid deliberately have no colliders, so those leg pieces will appear to 
pass through other objects without colliding when the squid explodes. This is so the ball can't hit two 
overlapped squid leg segments at once as the legs are flailing randomly.


PHYSICS AND COLLISION RESPONSE

The physics simulation in this game is detailed and fairly accurate. It includes realistic bounce/slide, 
angular velocity (spin) created by impacts, friction, inertia and mass.

See the PhysicsCalculator class.

Inertia is calculated per entity at line 220, Entity::setMass(), Entity.cpp.

I use a variation of the Runge-Kutta 4th order method for integrating acceleration and velocity. This is much
more accurate than the simple Euler method. 
See line 39, PhysicsCalculator::rk4Integrate(), PhysicsCalculator.cpp
See https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods and
https://en.wikipedia.org/wiki/List_of_Runge%E2%80%93Kutta_methods#Classic_fourth-order_method

I manage my own physics time-step, rather than relying on Bootstrap. A time accumulator method is used, which
ensures an accurate and deterministic simulation independent of CPU speed or FPS. 
See line 138 in Application2D.cpp
See http://gafferongames.com/game-physics/fix-your-timestep/

Objects in a matrix hierarchy act like a single object from the point of view of physics calculations. Each
entity refers to the top level object in its hierarchy via its "root" pointer when it is queried for details
like mass, world position, velocity, etc.


# OTHER ADVANCED FEATURES

	- An Asset Manager, which loads and stores assets such as textures and fonts in pools so that only one 
	copy of an asset is in memory at one time, allowing multiple objects to use the same copy of that 
	asset. See the AssetManager class. Loading assets into the manager, see line 52, Application2D.cpp.

	- My own rendering system with renderer and sprite structs, which allow rendered object properties to 
	be set such as line color, line thickness, sprite size (offset), sprite color tint, etc.
	See line 340, Entity::draw(), Entity.cpp
	See line 146 and 158, struct RenderShape and struct RenderSprite, Entity.h.

	- Using my own custom Shape2 class from my maths library, which represents any shape including lines,
	circles and polygons.

	- Game state managed by the game menu class (includes startup, paused/menu and playing modes).

	- A game menu with selectable and changeable options.

	- Fully const correct throughout.
	
	- Polymorphism; the Entity, Actor and Player classes are all polymorphic.

	- Factory; Entity, Actor and Player objects are created and managed in the Factory class.
	
	- Error handling (using AIE error handling class) with throws and asserts in key places. Exceptions
	are logged to the file "log.txt".
	
	- Using my own custom Mersenne Twister random number generator library as as imported .lib.
	
	- Using my own custom high accuracy clock library. See the GameClock class.


# ESSENTIAL CLASSES


	ENTITY

		Entity is the fundamental shape that can appear physically in the game world. Entities have 
		render shapes and sprites which determine their appearance. BasicShape is a derived class of 
		Entity. As the entities required in this game weren't diverse, only this one type of entity 
		was needed, but this class uses polymorphism so new entity types can easily be added.
		
		Entity <---- BasicShape
		
		
	ACTOR
	
		Actors are collections of entities that have defined behaviour such as the way they move or 
		interact with their environment. Actors may be under the control of human players or the AI.

		Two fundamental types of actor are used in this game; goalkeeper and ball. Squids are a derived 
		class of Goalkeeper, while Multiball is a derived class of of ball.
		
		Goalkeepers are controlled by a human or AI player. The squid has special physics and animated 
		random organic-looking limb movement achieved by cycling the rotation of limb joints. 
		See Squid.cpp.
		
		The ball is not controlled by a player but it has complex special physics behaviours that are 
		provided by the ball's update function. See line 40, Multiball::updatePhysics(), Multiball.cpp
		
		
		Actor <>---- Entity
		^
		|---- Ball <---- Multiball
		|
		|---- Goalkeeper <---- Squid
		
		
	PLAYER
	
		Player is the essential AI or Human controlled object that directs movement of a goalkeeper (an 
		Actor class) in the game world.
	
		Player <>---- Actor
		^
		|---- AI <---- AIHard
		|           |
		|           |- AIMedium
		|           |
		|           |- AISimple
		|
		|---- Human <---- HumanLeft
		               |
		               |- HumanRight
	
	
# THE SCOREKEEPER

One more core class that deserves a mention is the Score Keeper. It manages the game state during gameplay,
and enforces the rules including: resetting the ball after goals or when the ball has gone out of bounds, 
deciding when goals are scored or matches won and spawning junk on the game field at the start of rounds. 
It also displays the scores, the ball countdown and win/goal messages. See ScoreKeeper.cpp.

	
# ROOM FOR IMPROVEMENT

The position of the centre of mass for a hierarchy is not changed as objects are added, so collections of 
objects will continue to rotate around the top level parent's centre point regardless of the configuration 
of the collection of objects. The mass is also not changed, with collections of objects having a total mass 
of the parent object only when calculating collisions. Similarly, inertia is calculated using the parent 
object's mass and size only, not the mass and size of the combined hierarchy of objects.

The AI is very simple. It does not predict the expected position of the ball in the future, which is closer 
to what a human player does. The AI only reacts to where the ball is currently at any given time. It would 
be ideal to add a method of predicting the ball's expected position based on its velocity and likely angle 
of bounce/reflection off walls and other objects.

The window size is fixed to simplify developing the game. It would be better to allow fullscreen mode and 
to adjust the game size for any monitor size and resolution.