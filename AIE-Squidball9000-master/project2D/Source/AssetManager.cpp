#include <string>
#include "AssetManager.h"

AssetManager::AssetManager()
{
    exeFolder = getExecutableFolder();
}

AssetManager::~AssetManager()
{
	////Delete all textures on the heap.
	//for (auto &var : textures)
	//{
	//	delete var.second;
	//}

	////Delete all fonts on the heap.
	//for (auto &var : fonts)
	//{
	//	delete var.second;
	//}
}


AssetManager *AssetManager::getInstance()
{
    static AssetManager assetManager;

    return &assetManager;
}

aie::Texture *AssetManager::addTexture(std::string filename)
{

    //If texture already loaded, return it immediately.
    if (textures.count(filename))
    {
        return textures[filename];
    }

    aie::Texture *temp = new aie::Texture((exeFolder + filename).c_str());

    if (temp->getFilename() == "none" || temp->getWidth() == 0 || temp->getHeight() == 0) aieTHROW("ERROR: Couldn't load texture " + filename);

    //textures.insert(std::pair<std::string, aie::Texture*>(filename, temp));
	textures.insert(filename, temp);

    return temp;

}

aie::Texture *AssetManager::getTexture(std::string filename)
{
	if (!textures.count(filename))
	{
		addTexture(filename);
	}
        
    return textures[filename];
}

aie::Font *AssetManager::addFont(std::string filename, unsigned short fontHeight)
{

	//If font already loaded, return it immediately.
	if (fonts.count(filename))
	{
		return fonts[filename];
	}

	aie::Font *temp = new aie::Font((exeFolder + filename).c_str(), fontHeight);

	if (!temp->getTextureHandle()) aieTHROW("ERROR: Couldn't load font " + filename + " height " + std::to_string(fontHeight));

	//fonts.insert(std::pair<std::string, aie::Font*>(filename + std::to_string(fontHeight), temp));
	fonts.insert(filename + std::to_string(fontHeight), temp);

	return temp;

}

aie::Font *AssetManager::getFont(std::string filename, unsigned short fontHeight)
{
	if (!fonts.count(filename + std::to_string(fontHeight)))
	{
		addFont(filename, fontHeight);
	}

	return fonts[filename + std::to_string(fontHeight)];
}

std::string AssetManager::getExecutableFolder() const
{
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    char *pos;
    if (pos = strrchr(buffer, '\\'))
    {
        *pos = 0;
    }

    return buffer;
}
