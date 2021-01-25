workspace "Chernobyl-Dev"
	architecture "x64"
	startproject "Chernobyl"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Chernobyl"
    location "Chernobyl"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
	    "CoreEngine/src"
    }

    links
    {
        "CoreEngine"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "CH_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "CH_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "CH_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "CH_DIST"
        runtime "Release"
        optimize "On"


project "CoreEngine"
    location "CoreEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
	    "CoreEngine/src",
        "ExternalLibs/spdlog/include"
    }

    
    filter "system:windows"
        systemversion "latest"

        defines
        {
            "CH_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "CH_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "CH_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "CH_DIST"
        runtime "Release"
        optimize "On"