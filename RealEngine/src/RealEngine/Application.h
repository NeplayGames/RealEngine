#pragma once 
#include "Core.h"
#include "stdio.h"
namespace RealEngine {
	class REALENGINE_API Application
	{
		public: 
			void Run();
	};

	Application* CreateApplication();
}
