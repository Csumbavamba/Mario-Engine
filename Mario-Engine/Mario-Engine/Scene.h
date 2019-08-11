#pragma once
#include <string>
#include <vector>

class GameObject;
class Camera;

/**
 * An abstract base class for every different scene the game will have
 */
class Scene
{
public:

	Scene();
	virtual~Scene();

	/** Calls the corresponding GameObject Awake functions after each object has been constructed */
	virtual void Awake();

	/** After each GameObject has run their Awake functions this is called (in case any construction happens at Awake) */
	virtual void Start();

	/** Renders every GameObject on the Scene that is active, taking depth into consideration */
	virtual void Render();

	/** Updates every GameObject on the Scene that is active */
	virtual void Update();

	/** Resets the Scene completely to the end of the Start call */
	virtual void Reset();

	/** @return a bool that is true if the current scene is active*/
	bool IsActiveScene() const;

	/**
	 * Makes this scene active
	 * @param isActiveScene A bool for a new activity state
	 */
	void SetIsActiveScene(bool isActiveScene);

	/** @return the string name of the Scene */
	std::string GetSceneName() const;

protected:

	/** If this is true, the SceneManager will update and render this scene only */
	bool isActiveScene = false;

	/** The camera that is responsible for rendering objects for this scene */
	Camera* mainCamera = NULL;

	/** The string name of the Scene - used by the SceneManager */
	std::string sceneName = "";

	/** This holds every GameObject that is on this scene - Used for Awake, Start, Render and Update calls */
	std::vector<GameObject*> gameObjects;

};