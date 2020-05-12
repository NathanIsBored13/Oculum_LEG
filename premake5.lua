workspace "Oculum"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SPDLOG"] = "Oculum/vendors/spdlog/include"
IncludeDir["GLFW"] = "Oculum/vendors/GLFW/include"

project "GLFW"
	kind "StaticLib"
	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Oculum/vendors/GLFW/include/GLFW/glfw3.h",
		"Oculum/vendors/GLFW/include/GLFW/glfw3native.h",
		"Oculum/vendors/GLFW/src/glfw_config.h",
		"Oculum/vendors/GLFW/src/context.c",
		"Oculum/vendors/GLFW/src/init.c",
		"Oculum/vendors/GLFW/src/input.c",
		"Oculum/vendors/GLFW/src/monitor.c",
		"Oculum/vendors/GLFW/src/vulkan.c",
		"Oculum/vendors/GLFW/src/window.c"
	}
	filter "system:linux"
		pic "On"

		systemversion "latest"
		staticruntime "On"

		files
		{
			"Oculum/vendors/GLFW/src/x11_init.c",
			"Oculum/vendors/GLFW/src/x11_monitor.c",
			"Oculum/vendors/GLFW/src/x11_window.c",
			"Oculum/vendors/GLFW/src/xkb_unicode.c",
			"Oculum/vendors/GLFW/src/posix_time.c",
			"Oculum/vendors/GLFW/src/posix_thread.c",
			"Oculum/vendors/GLFW/src/glx_context.c",
			"Oculum/vendors/GLFW/src/egl_context.c",
			"Oculum/vendors/GLFW/src/osmesa_context.c",
			"Oculum/vendors/GLFW/src/linux_joystick.c"
		}

		defines
		{
			"_GLFW_X11"
		}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files
		{
			"Oculum/vendors/GLFW/src/win32_init.c",
			"Oculum/vendors/GLFW/src/win32_joystick.c",
			"Oculum/vendors/GLFW/src/win32_monitor.c",
			"Oculum/vendors/GLFW/src/win32_time.c",
			"Oculum/vendors/GLFW/src/win32_thread.c",
			"Oculum/vendors/GLFW/src/win32_window.c",
			"Oculum/vendors/GLFW/src/wgl_context.c",
			"Oculum/vendors/GLFW/src/egl_context.c",
			"Oculum/vendors/GLFW/src/osmesa_context.c"
		}

		defines 
		{ 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

project "Oculum"
	location "Oculum"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	pchheader "ocpch.h"
	pchsource "Oculum/src/ocpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OC_PLATFORM_WINDOWS",
			"OC_BUILD_DLL"
		}
		
			includedirs
		{
			"%{prj.name}/src",
			"%{IncludeDir.SPDLOG}",
			"%{IncludeDir.GLFW}"
		}
		
		links
		{
			"GLFW",
			"opengl32.lib"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OC_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Oculum/src",
		"Oculum/vendors/spdlog/include"
	}

	links
	{
		"Oculum"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OC_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "OC_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OC_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OC_DIST"
		optimize "On"