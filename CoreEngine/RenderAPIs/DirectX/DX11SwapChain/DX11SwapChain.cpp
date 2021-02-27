#include "DX11SwapChain.h"

#include "../DX11Context/DX11Context.h"

namespace CH {

	bool DX11SwapChain::Init(void* context, void* handle, uint32_t width, uint32_t height)
	{
		ID3D11Device* device = static_cast<ID3D11Device*>(context);
		HWND hWnd = (HWND)handle;

		// get the swap chain
		device->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_DXGI_Device);
		m_DXGI_Device->GetParent(__uuidof(IDXGIAdapter), (void**)&m_DXGI_Adapter);
		m_DXGI_Adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_DXGI_Factory);

		DXGI_SWAP_CHAIN_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		// amount of buffers.
		// there is already a front buffer, so an additional back buffer is then created
		desc.BufferCount = 1;

		// the width and height to draw
		desc.BufferDesc.Width = width;
		desc.BufferDesc.Height = height;

		// the format for shaders
		desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;

		// refresh rate
		desc.BufferDesc.RefreshRate.Numerator = 60;
		desc.BufferDesc.RefreshRate.Denominator = 1;

		// uses render target output
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

		// the window to draw to
		desc.OutputWindow = hWnd;

		// dunno what this is
		desc.SampleDesc.Count = 1;
		desc.SampleDesc.Quality = 0;

		// if it is windowed
		desc.Windowed = TRUE;

		// create the swap chain
		HRESULT hr = m_DXGI_Factory->CreateSwapChain(
			device,				// pass in the device
			&desc,				// pass in the descriptor
			&m_DXGI_SwapChain	// get the swap chain as output
		);

		if (FAILED(hr))
			return false;

		// get the back buffer
		ID3D11Texture2D* buffer;
		hr = m_DXGI_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

		if (FAILED(hr))
			return false;

		// store the back buffer into the member variable
		hr = device->CreateRenderTargetView(buffer, NULL, &m_D3D_RenderTargetView);
		
		// release the back buffer because it is not needed anymore
		buffer->Release();

		if (FAILED(hr))
			return false;

		return true;
	}

	void DX11SwapChain::SetVSync(bool enabled)
	{
		m_IsVSync = enabled;
	}

	void DX11SwapChain::Destroy()
	{
		m_DXGI_Device->Release();
		m_DXGI_Adapter->Release();
		m_DXGI_Factory->Release();
		m_DXGI_SwapChain->Release();

		delete this;
	}

	bool DX11SwapChain::Present()
	{
		// swap the back and front buffers
		HRESULT hr = m_DXGI_SwapChain->Present(m_IsVSync, NULL);
	
		// i dunno how this will fail
		if (FAILED(hr))
			return false;

		return true;
	}

}