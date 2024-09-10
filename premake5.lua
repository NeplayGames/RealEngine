workspace "RealEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}~%{cfg.system}~%{cfg.architecture}"
project "RealEngine"
	location "RealEngine"
	kind "SharedLib"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Repch.h"
	pchsource "RealEngine/src/Repch.cpp"
	 
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
	
	defines
	{
		"RE_PLATFORM_WINDOWS";
		"RE_BUILD_DLL";
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.realpath} ../bin/" .. outputdir .. "/Sandbox")
	}

filter	"configurations:Debug"
	defines "RE_DEBUG"
	symbols "On"


filter	"configurations:Release"
	defines "RE_RELEASE"
	optimize "On"


filter	"configurations:Dist"
	defines "RE_Dist"
	optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/RealEngine")
	objdir ("bin-int/" .. outputdir .. "/RealEngine")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"RealEngine/vendor/spdlog/include",
		"RealEngine/src",
	}

	links{
		"RealEngine"
	}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"
	
	defines
	{
		"RE_PLATFORM_WINDOWS";
	}


filter	"configurations:Debug"
	defines "RE_DEBUG"
	symbols "On"


filter	"configurations:Release"
	defines "RE_RELEASE"
	optimize "On"


filter	"configurations:Dist"
	defines "RE_Dist"
	optimize "On"