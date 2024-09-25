#pragma once

#include "Event.h"

namespace RealEngine {
	class REALENGINE_API KeyEvent : public Event 
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(EventKeyboard | EventInput)

	protected:
		int m_KeyCode;
		KeyEvent(int keyCode) : m_KeyCode(keyCode){}
	};

	class REALENGINE_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode),
			m_RepeatCount(repeatCount){}
		inline int GetRepeatCount() const { return  m_RepeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent" << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		EVENT_TYPE(KeyPressed);

	private:
		int m_RepeatCount;
	};

	class REALENGINE_API KeyReleasedEvent : public KeyEvent {
		public:
			KeyReleasedEvent(int KeyCode) :KeyEvent(KeyCode) {

			}
			std::string ToString() const override {
				std::stringstream ss;
				ss << "KeyReleasedEvent" << m_KeyCode;
				return ss.str();
			}
			EVENT_TYPE(KeyReleased);
	};


	class REALENGINE_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int KeyCode) :KeyEvent(KeyCode) {

		}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent" << m_KeyCode;
			return ss.str();
		}
		EVENT_TYPE(KeyTyped);
	};
}
