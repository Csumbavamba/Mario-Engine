#pragma once

 /* 
  * Every GameObject has a transform, that holds position, 
  * rotation and scale, that can be modified in order to achieve 
  * movement and transformations for the object
  */
struct Transform2D
{
	/** Creates a Transform that is positioned at the origin, has 0 rotation and is scaled 1 * 1 */
	Transform2D();

	Vector2 position;
	float rotation;
	Vector2 scale;

	/** 
	 * Calculates the distance between two 2D points
	 * @param position1, position2 The Position data of the two points
	 */
	static float GetDistance2D(Vector2 position1, Vector2 position2);
};

/** A container that holds vector coordinates x and y */
struct Vector2
{
	/** Creates a Vector2 where both x and y are 0 */
	Vector2();

	float x;
	float y;

	/**
	 * Converts the Vector2 to a unit Vector
	 * @return The converted 2D unit Vector
	 */
	Vector2 Normalize();
};

/** A container that holds vector coordinates x, y and z */
struct Vector3
{
	/** Creates a Vector3 where x, y and z are 0 */
	Vector3();

	float x;
	float y;
	float z;

	/** 
	 * Converts the Vector3 to a unit Vector 
	 * @return The converted 3D unit Vector
	 */
	Vector3 Normalize();
};
