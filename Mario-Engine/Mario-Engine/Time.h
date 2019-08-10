#pragma once

/*
 * A Singleton class responsible for managing the passing of time in game
 */
class Time
{
public:

	/** @return The time that has passed since the last frame */
	static float GetDeltaTime();

	/** @return The current scale of time */ 
	static float GetTimeScale();

	/*
	 * Sets the speed of the game
	 * Negative numbers are clamped to 0
	 * 1.0 is standard time scale
	 * Setting this to 0.0 effectively pauses the game
	 * @param timeScale A float value for the new time Scale
	 */ 
	static void SetTimeScale(float timeScale);

public:

	/** @return The single instance of the class */
	static Time* GetInstance();

	/* Keeps the deltaTime calculation updated - Called by the engine */
	static void Update();

	/** Frees up the memory after shutting down the game - Called by the engine */
	static void ShutDown();

private:

	/// Singleton Method
	Time();
	~Time() {};
	Time(const Time& copy) {};
	Time& operator= (const Time& move) {};

	/** The single instance of the Time class */
	static Time* instance;

	float deltaTime;
	float previousTimeStamp;
	float timeScale;
};