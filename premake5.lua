include "Premake/Customization/CleanBuild.lua"

workspace "Chernobyl-Dev"
	architecture "x64"
	startproject "Chernobyl"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"]		= "%{wks.location}/ExternalLibs/GLFW/include"
IncludeDir["Glad"]		= "%{wks.location}/ExternalLibs/Glad/include"
IncludeDir["ImGui"]		= "%{wks.location}/ExternalLibs/imgui"
IncludeDir["glm"]		= "%{wks.location}/ExternalLibs/glm"
IncludeDir["spdlog"]	= "%{wks.location}/ExternalLibs/spdlog/include"

group "Dependencies"
	include "ExternalLibs/GLFW"
	include "ExternalLibs/Glad"
	include "ExternalLibs/imgui"
group ""

include "CoreEngine"
include "Chernobyl"