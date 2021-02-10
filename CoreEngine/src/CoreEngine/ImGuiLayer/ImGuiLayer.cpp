#include "ImGuiLayer.h"

#include <imgui.h>
#include <examples/imgui_impl_win32.h>
#include <examples/imgui_impl_dx11.h>

#include "CoreEngine/Window/WindowHandler.h"
#include "CoreEngine/Core/Renderer2D/GraphicsEngine/GraphicsEngine.h"

namespace CH {

	void ImGuiLayer::OnAttach()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		
		ImGui::StyleColorsDark();

		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		ID3D11Device* device = static_cast<ID3D11Device*>(GraphicsEngine::GetD3DDevice());
		ID3D11DeviceContext* deviceContext = static_cast<ID3D11DeviceContext*>(GraphicsEngine::GetD3DDeviceContext());

		ImGui_ImplWin32_Init(static_cast<HWND>(WindowHandler::GetNativeWindow()));
		ImGui_ImplDX11_Init(device, deviceContext);
	}

	void ImGuiLayer::OnDetach()
	{
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnImGuiRender()
	{
		bool show = true;
		ImGui::ShowDemoWindow(&show);
	}

	void ImGuiLayer::Begin()
	{
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::End()
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(800, 600);

		// Rendering
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}
	}

}