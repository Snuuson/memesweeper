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
		void Draw(const Vei2& screenPos,bool fucked, Graphics& gfx);
		bool HasMeme() const; 
		void Reveal();
		bool isRevealed() const;
		void ToggleFlag();
		bool IsFlagged() const;
		void SetNeighborMemeCount(int memeCount);
	private:
		State state = State::Hidden;
		bool hasMeme = false;
		int nNeighborMemes = -1;
		

	};
	static constexpr int width = 30;
	static constexpr int height = 30;
	
	RectI rect;
	Tile field[width*height];
	int wndScreenHeight = 800;
	int wndScreenWidth = 600;
	bool init = false;
	int nMemes = 0;
private:
	Tile & TileAt(const Vei2& gridPos);
	Vei2 ScreenToGrid(const Vei2 & screenPos);
	const Tile& TileAt(const Vei2& gridPos) const;
	void AreaReveal(const Vei2& startingGridPos);
public:
	void Draw(Graphics& gfx);
	void OnRevealClick(const Vei2& screenPos);
	void OnFlagClick(const Vei2& screenPos);
	bool HasWon();
	RectI GetRect() const;
	MemeField(int nMemes,int screenHeight,int screenWidth);
	int CountNeighborMemes(const Vei2& gridPos);
	bool isFucked = false;

public:
	
	~MemeField();
};

