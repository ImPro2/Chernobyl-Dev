-- Premake file for CoreEngine project
project "CoreEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    disablewarnings { "4267", "4244", "4302", "4311", "4312" }
    linkoptions { "-IGNORE:4006" }
    
    pchheader "chpch.h"
    pchsource "src/chpch.cpp"

    files
    {
        "src/**.h",
        "src/**.cpp",
        "RenderAPIs/**.h",
        "RenderAPIs/**.cpp",
        "Platform/**.h",
        "Platform/**.cpp"
    }
    
    includedirs
    {
        -- Include directories in the engine
        "src",
        "RenderAPIs",
        "RenderAPIs/DirectX",

        -- Other include directories
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.Glad}",
    }

    links
    {
        "ImGui",
        "GLFW",
        "Glad"
    }
    
    filter "system:windows"
        systemversion "latest"

        defines
        {
            "CH_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

        links
        {
            "d3d11.lib",
            "d3dcompiler.lib"
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