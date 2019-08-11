#pragma once

#include <vector>
#include <string>

class Scene;

/**
 * A Singleton class responsible for changing Scenes
 */
class SceneManager
{
public:

	/** @return The index of the currently active Scene. */
	static int GetActiveSceneIndex();

	/** @return The currently active Scene as an object. */
	static Scene* GetActiveScene();

	/**
	 * Makes the current active Scene inactive and activates the Scene with the given index.
	 * @param sceneIndex The index of the Scene that is to be activated.
	 */
	static void ChangeActiveScene(int sceneIndex);

	/** 
	 * Makes the current active Scene inactive and activates the Scene with the given name.
	 * @param sceneName The string name of the Scene that is to be activated.
	 */
	static void ChangeActiveScene(std::string sceneName);
	

public:

	/** @return The single instance of the class. */
	static SceneManager* GetInstance();

	/**
	 * Adds a Scene to the existing vector of Scenes - eliminates duplicates.
	 * @param scene A pointer to a Scene that is to be added.
	 */
	static void AddScene(Scene* scene);

	/** Frees up the memory after shutting down the game - Called by the engine */
	static void ShutDown();

private:
	
	/// Singleton Method
	SceneManager() {};
	~SceneManager() {};
	SceneManager(const SceneManager& copy) {};
	SceneManager& operator= (const SceneManager& move) {};

	static SceneManager* instance;

	std::vector<Scene*> scenes;
	Scene* activeScene = nullptr;

};