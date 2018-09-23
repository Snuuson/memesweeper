#pragma once
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
public:
	MemeField();
	MemeField(int nMemes);
	~MemeField();
};

