#pragma once

#include "Transform.h"

class Matrix4;
class GameObject;

/*
 * The Class which is responsible for assisting in the rendering of GameObjects
 * A camera can be moved on the game scene
 */
class Camera2D
{
public:
	Camera2D();
	~Camera2D();

	/** Updates the matrix values for the camera while moving - Called by the engine */
	void Update();

	/** @return The view matrix of the camera. */
	Matrix4 GetViewMatrix();

	/** @return The ortographic Projection Matrix of the camera */
	Matrix4 GetOrtoProjectionMatrix();

	/** @return A 2D position vector of the 3D camera. */
	Vector2 GetPosition();

	/** 
	 * Sets the Camera position among the X and Y axes 
	 * @param cameraPosition A 2D Vector of the new position
	 */
	void SetPosition(Vector2 cameraPosition);

	/** @return The current field of view of the camera */
	float GetFieldOfView() const;

	/**
	 * Sets a new value field of view value
	 * @param fieldOfView The extent of the observable world that is seen at any given moment.
	 */
	void SetFieldOfView(float fieldOfView);

	/** 
	 * Sets an Object that the camera should follow - it only follows it on the X axes, the Y axes doesn't move
	 * @param objectToFollow The GameObject that should be followed
	 */
	void FollowGameObject(GameObject* objectToFollow);

private:

	Vector3 position;
	Vector3 lookDirection;
	Vector3 upDirection;
	float fieldOfView;

	GameObject* objectToFollow;

};