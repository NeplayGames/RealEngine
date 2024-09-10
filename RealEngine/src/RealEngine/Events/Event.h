#pragma once
#include "../Core.h"
#include <string>

namespace RealEngine {
	enum class EventType {
		None = 0,
		WindowClosed, WindowResized, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventApplication    = BIT(0),
		EventInput          = BIT(1),
		EventKeyboard       = BIT(2),
		EventMouse			= BIT(3),
		EventMouseButton	= BIT(4)
	};

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override{return category;}
#define EVENT_TYPE(type) static EventType GetStaticType() { return EventType:: ##type;}\
						virtual EventType GetEventType() const override { return GetStaticType(); }\
						virtual const char* GetName() const override {return #type;}
	class REALENGINE_API Event {
		public: 
			virtual ~Event() = default;
			virtual EventType GetEventType() const = 0;
			virtual const char* GetName() const = 0;
			virtual int GetCategoryFlags() const = 0;
			virtual std::string ToString() const { return GetName(); }

			inline bool IsCategory(EventCategory category) {
				return GetCategoryFlags() & category;
			}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher {
	public:
		EventDispatcher(Event& event) : m_Event(event) {

		}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	 };

	std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}
