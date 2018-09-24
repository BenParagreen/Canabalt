#pragma once

//Library Includes
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
public:
	//public Interface/ Behaviours 

	//Constructor
	AssetManager();

	//Get a texture based on a file name
	static sf::Texture& GetTexture(std::string _filename);
	//Get a soundbuffer based on a file name
	//static sf::SoundBuffer& GetSoundBuffer(std::string _filename);
	//Get a font based on a file name
	//static sf::Font& GetFont(std::string _filename);

private:
	//private data for this class

	//Pointer to the class itself
	//For the singleton design pattern
	//The one and only instance of this class
	static AssetManager* s_instance;

	//List of Textures
	std::map<std::string, sf::Texture> m_textures;
	//List of SoundBuffers
	std::map<std::string, sf::SoundBuffer> m_soundBuffers;
	//List of Fonts
	std::map<std::string, sf::Font> m_fonts;

};