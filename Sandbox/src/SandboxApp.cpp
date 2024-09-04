#include "RealEngine.h"

class Sandbox : public RealEngine::Application {
public:
	Sandbox() {

	}
};

RealEngine::Application* RealEngine::CreateApplication() {
	return new Sandbox();
}