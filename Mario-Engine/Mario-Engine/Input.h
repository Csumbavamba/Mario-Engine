#pragma once

struct KeyCode;

/** An Enum for determining the state of a keyboard key */
enum InputState
{	
	DOWN,	// 0
	HELD,	// 1
	UP		// 2
};

/**
 * A singleton class that is responsible for processing Keyboard inputs
 */
class Input
{

public:

	/** 
	 * Returns a boolean based on whether the specified key has just been pressed
	 * @return a bool that is true when the specified key has just been pressed
	 * @param keyCode A char that can be retrieved from the provided KeyCode value
	 */
	static bool GetKeyDown(char keyCode);

	/**
	 * Returns a boolean based on whether the specified key is held
	 * @return a bool that is true when the specified key is held
	 * @param keyCode A char that can be retrieved from the provided KeyCode value
	 */
	static bool GetKeyHeld(char keyCode);

	/**
	 * Returns a boolean based on whether the specified key has just been released
	 * @return a bool that is true when the specified key has just been released
	 * @param keyCode A char that can be retrieved from the provided KeyCode value
	 */
	static bool GetKeyUp(char keyCode);

	

public:

	/** @return The single instance of the class */
	static Input* GetInstance();

	/** Frees up the memory after shutting down the game - Called by the engine */
	static void ShutDown();

private:
	/// Singleton Method
	Input();
	~Input();
	Input(const Input& copy);
	Input& operator= (const Input& move);

	static Input* instance;

	InputState keyState[255];
	InputState specialKeys[255]; 

};