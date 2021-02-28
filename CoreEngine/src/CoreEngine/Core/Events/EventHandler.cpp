#include "chpch.h"
#include "EventHandler.h"

namespace CH {

	std::queue<Event*> EventHandler::s_EventQueue;

	int EventHandler::s_CurrentKeyPressed		= CH_KEY_UNKNOWN;
	int EventHandler::s_CurrentKeyReleased		= CH_KEY_UNKNOWN;
	int EventHandler::s_CurrentKeyTyped			= CH_KEY_UNKNOWN;
	int EventHandler::s_CurrentSysKeyPressed	= CH_KEY_UNKNOWN;
	bool	   EventHandler::s_LButtonClicked	= false;
	bool	   EventHandler::s_LButtonReleased	= false;
	bool	   EventHandler::s_RButtonClicked	= false;
	bool	   EventHandler::s_RButtonReleased	= false;
	bool	   EventHandler::s_MButtonClicked	= false;
	bool	   EventHandler::s_MButtonReleased	= false;
	Vec2	   EventHandler::s_MousePos			= { 0.0f, 0.0f };
	float	   EventHandler::s_MouseScrollOffset = 0.0f;

	void EventHandler::AddEvent(Event* e)
	{
		s_EventQueue.push(e);
	}

	void EventHandler::Update()
	{
		s_CurrentKeyPressed = CH_KEY_UNKNOWN;
		s_CurrentKeyReleased = CH_KEY_UNKNOWN;
		s_CurrentKeyTyped = CH_KEY_UNKNOWN;
		s_CurrentSysKeyPressed = CH_KEY_UNKNOWN;
		s_LButtonClicked = false;
		s_LButtonReleased = false;
		s_RButtonClicked = false;
		s_RButtonReleased = false;
		s_MButtonClicked = false;
		s_MButtonReleased = false;

		for (int i = 0; i < s_EventQueue.size(); i++)
		{
			HandleEvent(s_EventQueue.front());
			s_EventQueue.pop();
		}
	}

	int EventHandler::GetKeyPressed()
	{
		return s_CurrentKeyPressed;
	}

	int EventHandler::GetKeyReleased()
	{
		return s_CurrentKeyReleased;
	}

	char EventHandler::GetKeyTyped()
	{
		return static_cast<char>(s_CurrentKeyTyped);
	}

	int EventHandler::GetSysKeyPressed()
	{
		return s_CurrentSysKeyPressed;
	}

	int EventHandler::GetMouseButtonClicked()
	{
		int button = 0;

		if (s_LButtonClicked)	button = CH_MOUSE_BUTTON_LEFT;
		else if (s_RButtonClicked)	button = CH_MOUSE_BUTTON_RIGHT;
		else if (s_MButtonClicked)	button = CH_MOUSE_BUTTON_MIDDLE;
		else button = CH_MOUSE_BUTTON_UNKNOWN;

		return button;
	}

	int EventHandler::GetMouseButtonReleased()
	{
		int button = 0;

		if (s_LButtonReleased)	button = CH_MOUSE_BUTTON_LEFT;
		else if (s_RButtonReleased)	button = CH_MOUSE_BUTTON_RIGHT;
		else if (s_MButtonReleased)	button = CH_MOUSE_BUTTON_MIDDLE;
		else button = CH_MOUSE_BUTTON_UNKNOWN;

		return button;
	}

	Vec2 EventHandler::GetMousePos()
	{
		return s_MousePos;
	}

	float EventHandler::GetMouseScrollOffset()
	{
		return s_MouseScrollOffset;
	}

	void EventHandler::HandleEvent(Event* e)
	{
		switch (e->GetType())
		{
		case CH::Event::EventTypes::AppTick:
			break;
		case CH::Event::EventTypes::WindowCreate:
			break;
		case CH::Event::EventTypes::WindowClose:
			break;
		case CH::Event::EventTypes::WindowResize:
			break;
		case CH::Event::EventTypes::WindowMove:
			break;
		case CH::Event::EventTypes::KeyPressed:
			s_CurrentKeyPressed = e->KeyPressed;
			break;
		case CH::Event::EventTypes::KeyReleased:
			s_CurrentKeyReleased = e->KeyReleased;
			break;
		case CH::Event::EventTypes::KeyTyped:
			s_CurrentKeyTyped = e->KeyTyped;
			break;
		case CH::Event::EventTypes::SysKeyPressed:
			s_CurrentSysKeyPressed = e->SysKeyPressed;
			break;
		case CH::Event::EventTypes::LButtonClicked:
			s_LButtonClicked = true;
			break;
		case CH::Event::EventTypes::LButtonReleased:
			s_LButtonReleased = true;
			break;
		case CH::Event::EventTypes::RButtonClicked:
			s_RButtonClicked = true;
			break;
		case CH::Event::EventTypes::RButtonReleased:
			s_RButtonReleased = true;
			break;
		case CH::Event::EventTypes::MButtonClicked:
			s_MButtonClicked = true;
			break;
		case CH::Event::EventTypes::MButtonReleased:
			s_MButtonReleased = true;
			break;
		case CH::Event::EventTypes::MouseMoved:
			s_MousePos = e->MousePos;
			break;
		case CH::Event::EventTypes::MouseScrolled:
			s_MouseScrollOffset = e->MouseScrollOffset;
			break;
		}
	}

}