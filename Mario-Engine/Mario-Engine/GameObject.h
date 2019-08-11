#pragma once
#include "Transform.h"

class Camera;

/*
 * This is the base class for every object that needs to be in the game world
 */
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	/** Called after every object has been constructed, tick has not started yet */
	virtual void Awake();

	/** Called after every object has called Awake, Update starts after each Start call has finished */
	virtual void Start();

	/** Called every frame while the GameObject is active - Renders any Sprites that the GameObject has */
	virtual void Render();

	/** Called every frame while the GameObject is active */
	virtual void Update();

	/**
	 * Sets the camera that is going to render the object
	 * @param camera The camera that is responsible for the rendering of the object
	 */
	void SetCamera(Camera* camera);

	/** @return The Camera that is rendering the GameObject */
	Camera* GetCamera() const;

	/** 
	 * Makes the GameObject active or inactive 
	 * @param isActive The new activity state of the object
	 */
	void SetIsActive(bool isActive);

	/** @return The activity state of the GameObject */
	void GetIsActive() const;

	/** Holds the position, rotation and scale data of the GameObject */
	Transform2D transform;


protected:

	/** When this is true, the GameObject gets updated and rendered, otherwise the GameObject is not part of the game loop */
	bool isActive;

	/** Each GameObject is rendered by a specific camera, this camera is set by the engine on runtime */
	Camera* camera = nullptr;

};