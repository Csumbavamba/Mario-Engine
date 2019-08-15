#pragma once
#include "Transform.h"

class GameObject;

/**
 * A Class that can be attached to a GameObject to check for collisions around it
 */
class Collider_Circle
{
public:

	/**
	 * Creates an instance of the collider and attaches it to a GameObject
	 * @param owner A GameObject that the collider attaches to
	 */
	Collider_Circle(GameObject* owner);
	virtual ~Collider_Circle();

	/**
	 * Determines whether a GameObject is colliding with another GameObject
	 * @param newCenter The position data of the collider after movement (if there is movement)
	 * @param other The GameObject that is checked for collision
	 */
	bool IsColliding(Vector2 newCenter, GameObject* other);

public:

	/** @return The 2D position of the collider */
	Vector2 GetCenter() const;

	/**
	 * Updates the center position - Useful for ofsetting collisions
	 * @param center The new 2D position of the collider
	 */
	void SetCenter(Vector2 center);

	/** @return The maximum distance from the center where we check for collision */
	float GetRadius() const;

	/**
	 * Updates the maximum checking distance for collisions
	 * @param radius The updated maximum checking distance
	 */
	void SetRadius(float radius);

	/** @return The GameObject that the collider is attached to */
	GameObject* GetOwner() const;

protected:

	GameObject* owner = nullptr;
	Vector2 center;
	float radius;
};