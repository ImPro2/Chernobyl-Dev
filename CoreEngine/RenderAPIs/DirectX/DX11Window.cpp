#include "DX11Window.h"

#include "CoreEngine/Events/Events.h"
#include "CoreEngine/Log/Log.h"

#include <WinUser.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wparam, LPARAM lparam)
{
    switch (Msg)
    {

    //
    //  Creation and Destruction
    //
    case WM_CREATE:
    {
        CH::Event::s_CurrentWindowEvent = CH::Event::WindowEvent::Create;
        CH::DX11Window* window = (CH::DX11Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)window);
        window->SetHWND(hWnd);
        break;
    }
    case WM_DESTROY:
    {
        CH::Event::s_CurrentWindowEvent = CH::Event::WindowEvent::Close;
        CH::DX11Window* window = (CH::DX11Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
        window->SetOpen(false);
        ::PostQuitMessage(0);
        break;
    }

    //
    // Mouse Buttons
    //

    // left
    case WM_LBUTTONDOWN:
    {
        CH::Event::s_CurrentMouseButtonClicked = CH::Event::MouseEvent::LEFT;
        break;
    }
    case WM_LBUTTONUP:
    {
        CH::Event::s_CurrentMouseButtonReleased = CH::Event::MouseEvent::LEFT;
        break;
    }

    // right
    case WM_RBUTTONDOWN:
    {
        CH::Event::s_CurrentMouseButtonClicked = CH::Event::MouseEvent::RIGHT;
        break;
    }
    case WM_RBUTTONUP:
    {
        CH::Event::s_CurrentMouseButtonReleased = CH::Event::MouseEvent::RIGHT;
        break;
    }

    // middle
    case WM_MBUTTONDOWN:
    {
        CH::Event::s_CurrentMouseButtonClicked = CH::Event::MouseEvent::MIDDLE;
        break;
    }
    case WM_MBUTTONUP:
    {
        CH::Event::s_CurrentMouseButtonReleased = CH::Event::MouseEvent::MIDDLE;
        break;
    }

    //
    // Keys
    //

    // normal keys
    case WM_KEYDOWN:
    {
        CH::Event::s_CurrentKeyPressed = wparam;
        break;
    }
    case WM_KEYUP:
    {
        CH::Event::s_CurrentKeyReleased = wparam;
        break;
    }

    // alt keys
    case WM_SYSKEYDOWN:
    {
        CH::Event::s_CurrentSysKeyDown = wparam;
        break;
    }
    case WM_SYSKEYUP:
    {
        CH::Event::s_CurrentSysKeyUp = wparam;
        break;
    }

    // typing
    case WM_CHAR:
    {
        CH::Event::s_CurrentKeyTyped = wparam;
        break;
    }

    //
    // Other mouse stuff
    //
    case WM_MOUSEWHEEL:
    {
        int delta = GET_WHEEL_DELTA_WPARAM(wparam);
        CH::Event::s_MouseScrollOffset.x = delta;
        break;
    }
    case WM_MOUSEMOVE:
    {
        POINTS pt = MAKEPOINTS(lparam);
        CH::Event::s_MousePos.x = pt.x;
        CH::Event::s_MousePos.y = pt.y;
        break;
    }
    default:
    {
        CH::Event::s_CurrentWindowEvent = CH::Event::WindowEvent::AppTick;
        return DefWindowProc(hWnd, Msg, wparam, lparam);
    }
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