#pragma once

/////////////////////////////////////////////////////
// Precompiled header for Chernobyl Engine
/////////////////////////////////////////////////////

// includes in the engine
#include "CoreEngine/Core/Core.h"

// standard library includes
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <functional>
#include <vector>	
#include <unordered_map>
#include <map>
#include <stack>

// Window includes
#ifdef CH_PLATFORM_WINDOWS
	#include <Windows.h>
	#include <d3d11.h>
#endif

// OpenGL includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>