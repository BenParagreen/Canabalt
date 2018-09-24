// Library includes
#include <assert.h>

// Project includes
#include "AssetManager.h"

//Intialise the static reference to our instance - to nullptr (aka zero)
AssetManager* AssetManager::s_instance = nullptr;

//Constructor
AssetManager::AssetManager()
	: m_textures()
	, m_soundBuffers()
    , m_fonts()
{
	//Throw an error and stop execution (in debug mode) if a copy
	// of this class has already been created
	assert(s_instance == nullptr);

	// Assign ourselves to the instance pointer
	// - this is the new instance of the class that has just been created
	s_instance = this;
}

sf::Texture& AssetManager::GetTexture(std::string _filename)
{
	//Create an iterator to hold a key and value pair
	// and search for the required key
	// using the passed in file name
	auto keyValuePair = s_instance->m_textures.find(_filename);
		// "auto in this case is equivalent to writing
		// std ::map(std::string, sf::Texture>::iterator
		// this keyword can be used in cases where the
		// compiler can figure out the type of a variable for you
		// \\ONLY USE THIS FOR ITERATORS\\ 

    // Did we find the texture? (Aka was it already loaded?)
    // (iterator will be at the end if we did NOT find it)
    if (keyValuePair != s_instance->m_textures.end())
    {
	    // We found it
	    return keyValuePair->second;
    }
    else
    {
	//We did not find it

	//Create a new key value pair using the filename
	//The subscript [] operator creates an entry in
	// the map if there is not already one there

	sf::Texture& texture = s_instance->m_textures[_filename];

	//Blank texture has been created
	//Now just load it from file using sfml
	texture.loadFromFile(_filename);

	return texture;
    }


}

