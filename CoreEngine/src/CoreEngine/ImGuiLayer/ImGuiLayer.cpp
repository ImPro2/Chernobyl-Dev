#include "ImGuiLayer.h"

// include ImGui headers
#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"
#include "examples/imgui_impl_win32.h"
#include "examples/imgui_impl_dx11.h"

#include "../Platform/Platform.h"
#include "CoreEngine/Window/WindowHandler.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace CH {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
	
		// set imgui style to dark
		// TODO: make my own style somehow
		ImGui::StyleColorsDark();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::MACOS:
		{
			GLFWwindow* window = static_cast<GLFWwindow*>(WindowHandler::GetNativeWindow());
			ImGui_ImplGlfw_InitForOpenGL(window, true);
			ImGui_ImplOpenGL3_Init("#version 430"); 
			break;
		}
		case Platforms::WINDOWS:
		{
			//HWND hwnd = static_cast<HWND>(WindowHandler::GetNativeWindow());
			//ID3D11Device* device = static_cast<ID3D11Device*>(GraphicsEngine::GetD3DDevice());
			//ID3D11DeviceContext* deviceContext = static_cast<ID3D11DeviceContext*>(GraphicsEngine::GetD3DDeviceContext());
			//
			//ImGui_ImplWin32_Init(hwnd);
			//ImGui_ImplDX11_Init(device, deviceContext);
			//break;
		}
		default:
			CH_CORE_ASSERT(false, "Unsupported platform!");
		}
	}

	void ImGuiLayer::OnDetach()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::MACOS:
		{
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
			ImGui::DestroyContext();
			break;
		}
		case Platforms::WINDOWS:
		{
			ImGui_ImplDX11_Shutdown();
			ImGui_ImplWin32_Shutdown();
			ImGui::DestroyContext();
			break;
		}
		default:
			CH_CORE_ASSERT(false, "Unsupported platform!");
		}
	}

	void ImGuiLayer::Begin()
	{
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::MACOS:
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame(); 
			break;
		}
		case Platforms::WINDOWS:
		{
			ImGui_ImplDX11_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();
			break;
		}
		default:
			CH_CORE_ASSERT(false, "Unsupported platform!");
		}
	}

	void ImGuiLayer::End()
	{
		ImGuiIO& io = ImGui::GetIO();
	
		// set the display size
		io.DisplaySize = ImVec2(WindowHandler::GetWidth(), WindowHandler::GetHeight());

		// Render
		ImGui::Render();
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::MACOS:
		{
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			// update windows
			if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				GLFWwindow* backup_current_context = glfwGetCurrentContext();
				ImGui::UpdatePlatformWindows();
				ImGui::RenderPlatformWindowsDefault();
				glfwMakeContextCurrent(backup_current_context);
			}
		}
		case Platforms::WINDOWS:
		{
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

			// update windows
			if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				ImGui::UpdatePlatformWindows();
				ImGui::RenderPlatformWindowsDefault();
			}
		}
		}
	}

	void ImGuiLayer::OnImGuiRender()
	{
		ImGui::Begin("Hello world");
		ImGui::Text("Hello world");
		ImGui::End();
	}

}