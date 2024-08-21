#ifndef SpriteString_H
#define SpriteString_H

#include <list>

#include "SpriteFont.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// \class	SpriteString
///
/// \brief	A string that can be displayed in a scene via sprites.
///
/// \author	Mike Piunti
/// \date	03/06/2023
////////////////////////////////////////////////////////////////////////////////////////////////////
class SpriteString {
private:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \typedef	std::list<SpriteFont::Glyph*> GlyphList
	///
	/// \brief	Defines an alias representing the list of glyphs that make up the string.
	/// 		Null glyphs represent a new line.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	typedef std::list<SpriteFont::Glyph*> GlyphList;

	/// \brief	The list of glyphs.
	GlyphList glyphs;

	/// \brief	The height of the sprite string object.
	int height;

	/// \brief	The width of the sprite string object.
	int width;

	/// \brief	The string's position's x coordinate.
	int posX;

	/// \brief	The string's position's y coordinate.
	int posY;

public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	SpriteString::SpriteString(SpriteFont* sf = nullptr, std::string s = "", int x = 0, int y = 0);
	///
	/// \brief	Constructor. Creates a renderable object of the given string in the given font and
	/// 		places it at the given (x, y) coordinates.
	///
	/// \param	sf	(Optional) If non-null, the sprite font to use.
	/// \param	s 	(Optional) The raw string to render.
	/// \param	x 	(Optional) The x coordinate.
	/// \param	y 	(Optional) The y coordinate.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	SpriteString(SpriteFont* sf = nullptr, std::string s = "",
		int x = 0, int y = 0);

	SpriteString(const SpriteString&) = delete;
	SpriteString& operator=(const SpriteString&) = delete;
	~SpriteString() = default;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	int SpriteString::GetHeight();
	///
	/// \brief	Gets the height of the sprite string.
	///
	/// \returns	The height.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int GetHeight();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	int SpriteString::GetWidth();
	///
	/// \brief	Gets the width of the sprite string.
	///
	/// \returns	The width.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	int GetWidth();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void SpriteString::SetPos(const int x, const int y);
	///
	/// \brief	Sets the position of the sprite string.
	///
	/// \param 	x	The new x coordinate.
	/// \param 	y	The new y coordinate.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetPos(const int x, const int y);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void SpriteString::Set(SpriteFont* sf = nullptr, std::string s = "", const int x = 0, const int y = 0);
	///
	/// \brief	Sets a new string to be displayed in a new font at new coordinates.
	///
	/// \param	sf	(Optional) If non-null, the sprite font to use.
	/// \param	s 	(Optional) The raw string to render.
	/// \param	x 	(Optional) The x coordinate.
	/// \param	y 	(Optional) The y coordinate.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void Set(SpriteFont* sf = nullptr, std::string s = "", const int x = 0, const int y = 0);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// \fn	void SpriteString::Render();
	///
	/// \brief	Renders the string to the display.
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void Render();
};

#endif
