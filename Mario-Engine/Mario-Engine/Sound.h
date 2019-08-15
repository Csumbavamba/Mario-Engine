#pragma once

#include "Dependencies\fmod\fmod.hpp"
#include <string>

/** An enum for determining whether a sound is looping or not  */
enum PlayMode
{
	NOTLOOPING = 0,
	LOOPING
};

/**
 * A class that can play sounds through adding it to the level or to GameObjects
 */
class AudioSound
{
	/**
	 * Creates a Sound that is loaded from the provided filepath and sets the playmode to looping or not looping
	 * @param filePath A string value for the Folder Location of the given sound
	 * @param playMode An enum that is either looping or not looping
	 */
	AudioSound(std::string filePath, PlayMode playMode);
	~AudioSound();

	/** 
	 * When called the sound plays until it's finished 
	 * If a sound is looping it can only be stopped by StopPlaying()
	 */
	void PlaySound();

	/**
	 * Stops the sound from playing immediately
	 */
	void StopPlaying();

	/**
	 * Changes the volume of the sound that is to be played or being played.
	 * @param volume A float value that is clamped between 0 and 1
	 */
	void SetVolume(float volume);

private:

	/**
	 * Releases the sound from the Audio Engine's memory. - Called by the Audio Engine
	 */
	void ReleaseSound();

	std::string filePath;
	FMOD_MODE playMode;
	FMOD::Sound* sound = NULL;
	FMOD::Channel* channel = NULL;
	int channelID;
	float volume;

};