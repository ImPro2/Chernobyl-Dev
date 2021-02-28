-- Main project - Entry point
project "Chernobyl"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")
    disablewarnings { "4267", "4244", "4098" }
    linkoptions { "-IGNORE:4006" }
    
    files
    {
        "src/**.h",
        "src/**.cpp"
    }
    
    includedirs
    {
	    "../CoreEngine/src",
        "%{IncludeDir.spdlog}"
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