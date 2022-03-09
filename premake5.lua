workspace "Damsel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Damsel"
	location "Damsel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "On"

		defines
		{
			"DM_PLATFORM_WINDOWS",
			"DM_BUILD_DLL"
		}

		postbuildcommand
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DM_DEBUG"
		symbols "On"



	filter "configurations:Release"
		defines "DM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DM_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	includedirs
	{
		"Damsel/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "On"
		defines
		{
			"DM_PLATFORM_WINDOWS",
		}
		links
		{
			"Damsel"
		}

	filter "configurations:Debug"
		defines "DM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DM_DIST"
		optimize "On"