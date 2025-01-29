#include "InputManager.h"

void Input::InputManager::UpdateActionMaps(const EventInfo& _event)
{
    for (ActionMap* _map : actionsMaps)
    {
        _map->Update(_event);
    }
}

void Input::InputManager::Update(RenderWindow& _window)
{
    while (const optional _event = _window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            _window.close();
            return;
        }
        UpdateActionMaps(_event);
    }
}

/*
*
*       - WIDGET => CANVA, SCROLL BAR, SIZE BOX, IMAGE, INPUT FILED, COMBO BOX
*       - SETUP LEVEL ANGRY BIRD
*       - MOVEMENT ANGRY BIRD
*       - COLLISION COMPONENT
*       - ANIMATION => DURATION PAS VALIDE MAIS TIMEBETWEEN OUI
*       - DISPLAY NAME => M_ACTOR.GETAVAILABLENAME(NAME);
*       - PLAYERCONTROLLER
* 
* 
*/