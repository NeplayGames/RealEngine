#include "Repch.h"
#include "RealEngine/Events/Event.h"

namespace RealEngine {
	class MouseMoveEvent : public Event {

		public: 
			MouseMoveEvent(const float x, const float y) : m_MouseX(x), m_MouseY(y) {

			}

			float GetMouseX() { return m_MouseX; }
			float GetMouseY() { return m_MouseY; }
			std::string ToString() const override {
				std::stringstream ss;
				ss << "The mouse move to position ( " << m_MouseX << ", " << m_MouseY << ")";
				return ss.str();
			}
			EVENT_CLASS_CATEGORY(EventMouse);
			
			EVENT_TYPE(MouseMoved);

		private:
			float m_MouseX, m_MouseY;

	};
}