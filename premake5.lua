workspace "Tigris"
	architecture "x64"
	startproject "EngineEditor"

	configurations {"Debug", "Release", "Dist"}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Tigris/vendor/glad"
include "Tigris/vendor/glfw"
include "Tigris/vendor/imgui"

project "Tigris"
	location "Tigris"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	
	pchheader "TGpch.h"
	pchsource "%{prj.name}/src/TGpch.cpp"


files 
	{

	"%{prj.name}/src/**.cpp",
	"%{prj.name}/src/**.h",
	"%{prj.name}/src/Base/**.cpp",
	"%{prj.name}/src/Base/**.h",
    "%{prj.name}/src/Graphics/**.cpp",
	"%{prj.name}/src/Graphics/**.h",
	"%{prj.name}/src/Events/**.cpp",
	"%{prj.name}/src/Events/**.h",
	"%{prj.name}/vendor/stbi/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	
	}

links
	{
	"GLFW",
	"Glad",
	"opengl32.lib",
	"ImGui"

	}


includedirs 
	{

		"%{prj.name}/src",
		"%{prj.name}/vendor/glad/include",
		"%{prj.name}/vendor/glfw/include",
		"%{prj.name}/vendor/glm",
		"%{prj.name}/vendor/Math",
		"%{prj.name}/vendor/stbi",
		"%{prj.name}/vendor/imgui"

	}

	postbuildcommands
	{

		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/EngineEditor/\"")
	}

filter "system:windows"
	systemversion "latest"
	defines 
	{
	"TG_BUILD_DLL",
	"TG_PLATFORM_WINDOWS",
	"GLFW_INCLUDE_NONE"
	}

filter "configurations:Debug"
	defines "TG_DEBUG"
	symbols "on"
	optimize "off"
	runtime "Debug"
filter "configurations:Release"
	defines "TG_RELEASE"
	symbols "on"
	optimize "on"
	runtime "Release"
filter "configurations:Dist"
	defines "TG_DIST"
	runtime "Release"
	optimize "on"


project "EngineEditor"
	location "EngineEditor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	



files 
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

links
	{
		"Tigris"
	}


includedirs 
	{
		"%{prj.name}/src",
		"Tigris/src",
		"Tigris/vendor/Math",
		"Tigris/vendor/glm",
	}



filter "system:windows"
	systemversion "latest"
	defines 
	{
		"TG_PLATFORM_WINDOWS"
	}

filter "configurations:Debug"
	defines "TG_DEBUG"
	symbols "on"
	runtime "Debug"
filter "configurations:Release"
	defines "TG_RELEASE"
	symbols "on"
	optimize "on"
	runtime "Release"
filter "configurations:Dist"
	defines "TG_DIST"
	symbols "off"
	runtime "Release"
	optimize "on"


project "SandBoxApp"
	location "SandBoxApp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

	



files 
	{
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.h",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

links
	{
		"Tigris"
	}


includedirs 
	{
		"%{prj.name}/src",
		"Tigris/src",
		"Tigris/vendor/Math",
		"Tigris/vendor/glm",
	}



filter "system:windows"
	systemversion "latest"
	defines 
	{
		"TG_PLATFORM_WINDOWS"
	}

filter "configurations:Debug"
	defines "TG_DEBUG"
	symbols "on"
	runtime "Debug"
filter "configurations:Release"
	defines "TG_RELEASE"
	symbols "on"
	optimize "on"
	runtime "Release"
filter "configurations:Dist"
	defines "TG_DIST"
	symbols "off"
	runtime "Release"
	optimize "on"



