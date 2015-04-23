#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;
using namespace std;

struct PlayerControls
{
	float Movement; // przyjmuje wartosci <-1,1>. 1 - idzie w prawo, -1 idzie w lewo
	bool Jump; //True gdy gracz nacisnal przycisk skoku
	bool Attack ; //Prawda gdy gracz nacisnal przycisk ataku
	bool DebugPause:true; //Prada gdy gracz nacisnal klawisz do pauzy
	bool FrameSkip; //Prawda gdy gracz nacisnie klawisz przeskoku ramki
	bool Boost;
};

class EventHandler
{
public:
	EventHandler();
	virtual ~EventHandler();
	void readEvents(Window &window);

	//Zwroc aktualna kopie stanu klawiszy przypisanych do akcji danego gracza
	PlayerControls& GetPlayerControls(int playerIndex);
private:
	PlayerControls Controls[2];
};

