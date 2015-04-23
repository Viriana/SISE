#include "EventHandler.h"

EventHandler::EventHandler()
{
}


EventHandler::~EventHandler()
{
}

void EventHandler::readEvents(Window &window)
{
	Event event;
	
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}
		}
	}
}