#pragma once
#include "Graphics.h"
#include "Vei2.h"
#include "SpriteCodex.h"
class MemeField
{
private:
	class Tile
	{
	public:
		enum class State
		{
			Hidden,
			Flagged,
			Revealed
		};
		void SpawnMeme();
		void Draw(const Vei2& screenPos, Graphics& gfx);
		bool HasMeme() const; 
	private:
		State state = State::Hidden;
		bool hasMeme = false;

	};
	static constexpr int width = 20;
	static constexpr int height = 16;
	Tile field[width*height];
private:
	Tile & TileAt(const Vei2& gridPos);
	const Tile& TileAt(const Vei2& gridPos) const;
public:
	void Draw(Graphics& gfx);
	RectI GetRect() const;
	MemeField(int nMemes);
public:
	MemeField();
	~MemeField();
};

