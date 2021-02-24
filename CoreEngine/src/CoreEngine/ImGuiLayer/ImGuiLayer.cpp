#include "ImGuiLayer.h"

#include "CoreEngine/Events/EventHandler.h"
#include "CoreEngine/Window/WindowHandler.h"
#include "../Platform/Platform.h"
#include "CoreEngine/Core/Renderer2D/GraphicsEngine/GraphicsEngine.h"

#define IMGUI_IMPL_API
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

#include <examples/imgui_impl_win32.h>
#include <examples/imgui_impl_dx11.h>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace CH {

	void ImGuiLayer::OnAttach()
	{
		// setup imgui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
		io.DisplaySize = ImVec2(800, 600);

		ImGui::StyleColorsDark();

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
			ImGui_ImplOpenGL3_Init("#version 410");
			break;
		}
		case Platforms::WINDOWS:
		{
			HWND* hwnd = static_cast<HWND*>(WindowHandler::GetNativeWindow());

			ID3D11Device* device = static_cast<ID3D11Device*>(GraphicsEngine::GetD3DDevice());
			ID3D11DeviceContext* deviceContext = static_cast<ID3D11DeviceContext*>(GraphicsEngine::GetD3DDeviceContext());
			
			ImGui_ImplWin32_Init(hwnd);
			ImGui_ImplDX11_Init(device, deviceContext);
			break;
		}
		}
	}

	void ImGuiLayer::Begin()
	{
		ImGui::NewFrame();
		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
			ImGui_ImplDX11_NewFrame();
			ImGui_ImplWin32_NewFrame();
			break;
		case Platforms::MACOS:
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			break;
		}
	}

	void ImGuiLayer::End()
	{
		ImGuiIO& io = ImGui::GetIO();

		switch (Platform::GetCurrentPlatform())
		{
		case Platforms::WINDOWS:
		{
			ImGui::Render();
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

			if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				ImGui::UpdatePlatformWindows();
				ImGui::RenderPlatformWindowsDefault();
			}
			break;
		}
		case Platforms::MACOS:
		{
			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
			{
				GLFWwindow* backup_current_context = glfwGetCurrentContext();
				ImGui::UpdatePlatformWindows();
				ImGui::RenderPlatformWindowsDefault();
				glfwMakeContextCurrent(backup_current_context);
			}
			break;
		}
		}
	}

	void ImGuiLayer::OnImGuiRender()
	{
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

}