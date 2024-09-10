#pragma once 
#include "Core.h"


namespace RealEngine {
	class REALENGINE_API Application
	{
		public: 
			void Run();
	};

	Application* CreateApplication();
}
