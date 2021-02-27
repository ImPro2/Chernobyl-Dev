#pragma once

#include "CoreEngine/Renderer/SwapChain.h"

#include <d3d11.h>

namespace CH {

	class DX11SwapChain : public SwapChain
	{
	public:
		bool Init(void* context, void* handle, uint32_t width, uint32_t height) override;
		void Destroy() override;

		void SetVSync(bool enabled) override;

		bool Present() override;

		ID3D11RenderTargetView* GetD3DRenderTargetView() { return m_D3D_RenderTargetView; }

	private:
		IDXGIDevice* m_DXGI_Device;
		IDXGIAdapter* m_DXGI_Adapter;
		IDXGIFactory* m_DXGI_Factory;

		IDXGISwapChain* m_DXGI_SwapChain;

		ID3D11RenderTargetView* m_D3D_RenderTargetView;
	};

}