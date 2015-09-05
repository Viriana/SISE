#include "FuzzyPlayer.h"

FuzzyPlayer::FuzzyPlayer(string name, float spriteRotation) : Player(name, spriteRotation)
{
	engine = new Engine("fuzzy_player!");
	
}


FuzzyPlayer::~FuzzyPlayer()
{
}

string FuzzyPlayer::ProcessAI()
{

}

