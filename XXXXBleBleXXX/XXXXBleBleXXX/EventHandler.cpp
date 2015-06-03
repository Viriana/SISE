#include "EventHandler.h"

EventHandler::EventHandler()
{
	unitSelected = false;
	fieldSelected = false;
	numberOfClicks = 0;
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

		if (event.type == Event::MouseButtonReleased)
		{
			if (event.key.code == Mouse::Left)
			{
				numberOfClicks++;

				if (numberOfClicks == 1)
				{
					unitSelected = true;
					fieldSelected = false;
				}
				else if (numberOfClicks == 2)
				{
					unitSelected = true;
					fieldSelected = true;
					numberOfClicks = 0;
				}

				//cout << "left button released" << endl;
				mousePosition.x = Mouse::getPosition(window).x;
				mousePosition.y = Mouse::getPosition(window).y;
				//cout << "clicked on " << mousePosition.x << ", " << mousePosition.y << endl;
			}
		}
	}
}