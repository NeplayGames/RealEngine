#include "Application.h"

#include "Events/KeyEvent.h"
#include "Log.h"
namespace RealEngine {
	void Application::Run() {
		printf("Welcome to the real engine");
		KeyPressedEvent e(2, 5);
		RE_TRACE(e);
		while (true) {
		}
	}
}