#include "DX11Window.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wparam, LPARAM lparam)
{
    switch (Msg)
    {
    case WM_CREATE:
    {
        CH::DX11Window* window = (CH::DX11Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)window);
        window->SetHWND(hWnd);
        break;
    }
    case WM_DESTROY:
    {
        CH::DX11Window* window = (CH::DX11Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
        window->SetOpen(false);
        ::PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, Msg, wparam, lparam);
    }
    return NULL;
}

namespace CH {


    bool DX11Window::Init(DX11WindowData wndData)
    {
        m_WindowData = wndData;

        WNDCLASSEX wc;
        wc.cbClsExtra = NULL;
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.cbWndExtra = NULL;
        wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
        wc.hInstance = NULL;
        wc.lpszClassName = L"MyWindowClass";
        wc.lpszMenuName = L"";
        wc.style = NULL;
        wc.lpfnWndProc = &WndProc;

        if (!::RegisterClassEx(&wc))
            return false;

        m_hWnd = ::CreateWindowEx(
            WS_EX_OVERLAPPEDWINDOW,
            L"MyWindowClass",
            m_WindowData.Title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            m_WindowData.Width, m_WindowData.Height,
            NULL,
            NULL,
            NULL,
            this
        );

        if (!m_hWnd)
            return false;

        ::ShowWindow(m_hWnd, SW_SHOW);
        ::UpdateWindow(m_hWnd);

        return true;
    }

    void DX11Window::Destroy()
    {
        DestroyWindow(m_hWnd);
    }

    void DX11Window::Update()
    {
        MSG msg;

        while (::PeekMessage(&msg, m_hWnd, 0, 0, PM_REMOVE) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    bool DX11Window::IsOpen()
    {
        return m_IsOpen;
    }


    DX11Window::DX11WindowData DX11Window::GetDX11WindowData()
    {
        return m_WindowData;
    }

    void* DX11Window::GetNativeWindow()
    {
        return m_hWnd;
    }

    DX11Window::OpenGLWindowData DX11Window::GetOpenGLWindowData()
    {
        return OpenGLWindowData();
    }
    
    bool DX11Window::Init(OpenGLWindowData wndData)
    {
        return false;
    }
}