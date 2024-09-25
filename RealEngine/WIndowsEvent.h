#include "Repch.h"
#include "RealEngine/Events/Event.h"

namespace RealEngine {
	class WindowCloseEvent : public Event
	{
		public:
			WindowCloseEvent() = default;
			EVENT_CLASS_CATEGORY(EventWindow);
			EVENT_TYPE(WindowClosed);
	};

	class WindowResizedEvent : public Event
	{
		public:
			WindowResizedEvent(int width, int height) : m_Width(width), m_Height(height) {

			}
			EVENT_CLASS_CATEGORY(EventWindow);
			EVENT_TYPE(WindowResized);
			virtual std::string ToString() const override 
			{
				std::stringstream ss;
				ss << "The window is resized with height = " << m_Height << "and width = " << m_Width;
				return ss.str();
			}

		private:
			int m_Width;
			int m_Height;
	};

	
}
