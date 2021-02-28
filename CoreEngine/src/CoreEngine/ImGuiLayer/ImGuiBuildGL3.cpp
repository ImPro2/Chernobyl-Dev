// Build ImGui to hopefully not get any linking errors i hope i really do

// define this so that ImGui knows glad is being used as the loader
#define IMGUI_IMPL_OPENGL_LOADER_GLAD
#include "examples/imgui_impl_opengl3.cpp"
#include "examples/imgui_impl_glfw.cpp"

// include this last because this gives errors if included before...
#include "chpch.h"