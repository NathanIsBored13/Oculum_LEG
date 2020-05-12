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

project "Oculum"
	location "Oculum"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

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
			"%{prj.name}/vendors/spdlog/include"
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