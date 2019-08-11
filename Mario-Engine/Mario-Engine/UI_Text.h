#pragma once
#include "GameObject.h"

#include <string>

class Text;
struct Color;

/**
 * A class responsible for displaying text as part of the UI like Menus and subtitles
 */
class UI_Text : public GameObject
{
public:

	/**
	 * Creates a text that can be displayed on a specific point of the screen with the specified font
	 * @param text A string containing the text that you would like to display
	 * @param position A Vector2 of the text on the screen
	 * @param fontFilePath A string that holds the location of the font file
 	 */
	UI_Text(std::string text, Vector2 position, std::string fontFilePath);
	virtual ~UI_Text();

	/** Called after every object has been constructed, tick has not started yet */
	virtual void Awake() override;

	/** Called after every object has called Awake, Update starts after each Start call has finished */
	virtual void Start() override;;

	/** Called every frame while the GameObject is active - Renders any Sprites that the GameObject has */
	virtual void Render() override;

	/** Called every frame while the GameObject is active */
	virtual void Update() override;

	/**
	 * Updates the font of the text
	 * @param fontFilePath A string that holds the location of the font file
	 */
	void SetFont(std::string fontFilePath);

	/**
	 * Updates the text that is displayed on the screen
	 * @param text A string that contains the text that is to be displayed
	 */
	void SetText(std::string text);

	/**
	 * Updates the color of the text
	 * @param color A Color value - RGB
	 */
	void SetColor(Color color);

	/**
	 * Updates the scale of the text
	 * @param scale A float value, 1.0f is the default
	 * Value is clamped between 0 and 10000
	 */
	void SetScale(float scale);

private:

	Vector2 positionOnScreen;
	Text* text = NULL;
};