#pragma once

#include <string>
#include <vector>

class GameObject;

/**
 * A struct that is used for customising Sprite Animations
 */
struct AnimationSettings
{
	/**
	 * Creates an animation setting that can be used for animating sprites
	 * @param startFrame The first frame of the animation
	 * @param endFrame The last frame of the animation
	 * @param isLooping Determines whether an animation should play again after the last frame is reached
	 * @param playSpeed A float value that determines how fast an animation should play
	 */
	AnimationSettings(int startFrame, int endFrame, bool isLooping, float playSpeed);

	int startFrame = 0;
	int endFrame = 0;
	bool isLooping = true;
	float playSpeed = 1.0f;
};

/**
 * A class that is used for animating sprites.
 */
class SpriteAnimation
{
public:
	/**
	 * Creates a sprite animation that is from the given file path and animation settings
	 * @param filePath A string reference to the file location.
	 */
	SpriteAnimation(std::string filePath, AnimationSettings settings);
	~SpriteAnimation();

	/**
	 * Updates the current frame of the animation.
	 */
	void Play();
	

private:

	AnimationSettings settings;
	unsigned int texture;
};

class Sprite
{
public:

	/**
	 * Creates a Sprite object and attaches it to a GameObject.
	 * @param owner The GameObject that the Sprite attaches itself to.
	 */
	Sprite(GameObject* owner);
	virtual ~Sprite();

	/** 
	 * Renders the current animation of the sprite.
	 * Called every frame while the GameObject that the Sprite is attachted to is active. 
	 */
	virtual void Render();

	/**
	 * Plays the current animation.
	 * Called every frame while the GameObject that the sprite is attachted to is active. 
	 */
	virtual void Update();

	/** @return The current animation that is being played. */
	SpriteAnimation* GetCurrentAnimation() const;

	/**
	 * Updates the animation that the sprite should be playing
	 * @param spriteAnimation A sprite animation that is to be played
	 */
	void SetCurrentAnimation(SpriteAnimation* spriteAnimation);

	/**
	 * Stores a sprite animation in a vector
	 * @param spriteAnimation A sprite animation that should be stored
	 */
	void AddAnimation(SpriteAnimation* spriteAnimation);

private:

	std::vector<SpriteAnimation*> animations;
	SpriteAnimation* currentAnimation;

	GameObject* owner = nullptr;
};