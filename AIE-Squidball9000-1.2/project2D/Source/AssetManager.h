#pragma once
#include <Windows.h>
//#include <map>
//#include <vector>
#include <BinarySearchTree.h>
#include <LinkedList.h>
#include <LinkedListIterator.h>
#include <algorithm>
#include <string>
#include "Texture.h"
#include "Font.h"
#include "aieException.h"



#define AMAN AssetManager::getInstance()



/**
* AssetManager loads and stores assets such as textures and fonts in pools so that only one 
* copy of an asset is in memory at one time, allowing multiple objects to use the same copy of 
* that asset.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class AssetManager
{

public:

    /**
    * Create or get static instance.
    * @returns A pointer to the single AssetManager object.
    */
    static AssetManager *getInstance();

    /**
    * Add a texture by file name.
    * @params filename The file name of the texture.
    * @returns A pointer to the texture.
    */
    aie::Texture *addTexture(std::string filename);

    /**
    * Get a pointer to a texture by file name.
	* Automatically calls addTexture if the texture is not currently loaded.
    * @params filename The file name of the texture.
    * @returns A pointer to the texture. Returns nullptr if no texture found with that file name.
    */
    aie::Texture *getTexture(std::string filename);

	/**
	* Add a font by file name.
	* @params filename The file name of the font.
	* @params fontHeight The font height.
	* @returns A pointer to the font.
	*/
	aie::Font *addFont(std::string filename, unsigned short fontHeight);

	/**
	* Get a pointer to a font by file name.
	* Automatically calls addFont if the font with specified height is not currently loaded.
	* @params filename The file name of the font.
	* @returns A pointer to the font. Returns nullptr if no font found with that file name.
	*/
	aie::Font *getFont(std::string filename, unsigned short fontHeight);

private:

    /**
    * Default constructor.
    * Private to prevent class being created on the stack.
    */
	AssetManager();

    /**
    * Default destructor.
    * Private to prevent class being created on the stack.
    */
    ~AssetManager();

    /**
    * Textures indexed by file name.
    */
    /*std::map*/ContLib::BinarySearchTree<std::string, aie::Texture*> textures;

	/**
	* Fonts indexed by file name.
	*/
	/*std::map*/ContLib::BinarySearchTree<std::string, aie::Font*> fonts;

    /**
    * The program executable folder.
    */
    std::string exeFolder;

    /**
    * Get the path to the executable file's folder.
    * @returns The path.
    */
    std::string getExecutableFolder() const;
};