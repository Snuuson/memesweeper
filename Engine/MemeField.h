#pragma once
#include "Graphics.h"
#include "Vei2.h"
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
public: 
	void Draw(Graphics& gfx) const;
	MemeField(int nMemes);
public:
	MemeField();
	~MemeField();
};

