#include "Repch.h"
#include "Application.h"

#include "Events/KeyEvent.h"
#include "Log.h"
namespace RealEngine {
	void Application::Run() {
		printf("Welcome to the real engine");
		KeyPressedEvent e(2, 5);
		if (e.IsCategory(EventInput)) {
			RE_TRACE(e.ToString());
		}
		
		while (true) {
		}
	}
}