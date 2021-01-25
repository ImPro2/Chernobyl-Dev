#include "Events.h"

namespace CH {

	Vec2				 Event::s_MousePos = { 0.0f, 0.0f };
	Vec2				 Event::s_MouseScrollOffset = { 0.0f, 0.0f };
	Event::EventCategory Event::s_CurrentCategory = Event::EventCategory::WindowEvent;
	Event::TypeEvent     Event::s_CurrentKeyTyped = Event::TypeEvent::NONE;
	Event::TypeEvent     Event::s_CurrentKeyReleased = Event::TypeEvent::NONE;
	Event::MouseEvent    Event::s_CurrentMouseButtonClicked = Event::MouseEvent::NONE;
	Event::MouseEvent	 Event::s_CurrentMouseButtonReleased = Event::MouseEvent::NONE;
	Event::WindowEvent   Event::s_CurrentWindowEvent = Event::WindowEvent::AppTick;

}