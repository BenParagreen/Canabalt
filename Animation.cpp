// Project includes
#include "Animation.h"

Animation::Animation()
	: m_frames()
	, m_sprite(nullptr)
	, m_playBackSpeed(10)
	, m_loop(false)
	, m_playing(false)
	, m_nextFrameChange()
	, m_currentFrame(0)
{

}

void Animation::Update(sf::Time _frameTime)
{
	//Only Process Animtaion if it is playing

	if (m_playing)
	{
		//Is it time to change to a new frame?
		m_nextFrameChange -= _frameTime;
		if (m_nextFrameChange.asSeconds() <= 0)
		{
			// Its time to change the frame

			// change to next frame
			++m_currentFrame;

			// Did we reach the end/
			if (m_currentFrame >= m_frames.size())
			{
				// We reached the end
				// should it loop?
				if (m_loop)
				{
					//We should loop
					//Wrap around to the beginning
				    m_currentFrame = 0;
				}
				else
				{
					//We should not loop

					//Set frame as the last in the list
					m_currentFrame = m_frames.size() - 1;
					//Stop Playback
					m_playing = false;
				}
			}

			//Does sprite Exist
			if (m_sprite) //Is not = 0 aka null aka nullptr
			{
				m_sprite->setTexture(*m_frames[m_currentFrame]);
			}

			//Determine time for next frame change
			// converts frames per second to seconds per frame
			float timeToChange = 1.0f / m_playBackSpeed;
			m_nextFrameChange = sf::seconds(timeToChange);
		}
	}	
}

void Animation::Play()
{
	// Update our sprite to the current frame
	if (m_sprite)
	{
		m_sprite->setTexture(*m_frames[m_currentFrame]);
	}

	//Only start playing and set next frame time if playbackspeed does not = 0
	// this avoids dividing by 0
	if (m_playBackSpeed != 0)
	{
		//Set playback to true
		m_playing = true;

		//Determine time for next frame change
		// converts frames per second to seconds per frame
		float timeToChange = 1.0f / m_playBackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}
}

void Animation::Pause()
{
	m_playing = false;
}

void Animation::Stop()
{
	m_playing = false;
	m_currentFrame = 0;
}

bool Animation::Isplaying()
{
	return m_playing;
}

void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(&_newFrame);
}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;
}

void Animation::SetPlayBackSpeed(float _framesPerSecond)
{
	m_playBackSpeed = _framesPerSecond;

	if (m_playBackSpeed == 0)
		Pause();
}

void Animation::SetLoop(bool _loop)
{
	m_loop = _loop;
}