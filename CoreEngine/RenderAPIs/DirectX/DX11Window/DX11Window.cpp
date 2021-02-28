#include "chpch.h"
#include "DX11Window.h"

#include "CoreEngine/Core/Events/EventHandler.h"
#include "CoreEngine/Core/Log/Log.h"
#include "CoreEngine/Renderer/RenderCommand.h"

#include <WinUser.h>

// function to set events
LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wparam, LPARAM lparam)
{
    switch (Msg)
    {

    //
    //  Creation and Destruction
    //
    case WM_CREATE:
    {
        CH::DX11Window* window = (CH::DX11Window*)((LPCREATESTRUCT)lparam)->lpCreateParams;
        SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)window);
        window->SetHWND(hWnd);

        CH::Event* e = new CH::Event(CH::Event::EventTypes::WindowCreate);
        CH::EventHandler::AddEvent(e);

        break;
    }
    case WM_DESTROY:
    {

        CH::Event* e = new CH::Event(CH::Event::EventTypes::WindowClose);
        CH::EventHandler::AddEvent(e);

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
        CH::Event* e = new CH::Event(CH::Event::EventTypes::LButtonClicked);
        CH::EventHandler::AddEvent(e);
        break;
    }
    case WM_LBUTTONUP:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::LButtonReleased);
        CH::EventHandler::AddEvent(e);
        break;
    }

    // right
    case WM_RBUTTONDOWN:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::RButtonClicked);
        CH::EventHandler::AddEvent(e);
        break;
    }
    case WM_RBUTTONUP:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::RButtonReleased);
        CH::EventHandler::AddEvent(e);
        break;
    }

    // middle
    case WM_MBUTTONDOWN:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::MButtonClicked);
        CH::EventHandler::AddEvent(e);
        break;
    }
    case WM_MBUTTONUP:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::MButtonReleased);
        CH::EventHandler::AddEvent(e);
        break;
    }

    //
    // Keys
    //

    // normal keys
    case WM_KEYDOWN:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::KeyPressed);
        e->KeyPressed = wparam;

        CH::EventHandler::AddEvent(e);
        break;
    }
    case WM_KEYUP:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::KeyReleased);
        e->KeyReleased = wparam;

        CH::EventHandler::AddEvent(e);
        break;
    }

    // alt keys
    case WM_SYSKEYDOWN:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::SysKeyPressed);
        e->SysKeyPressed = wparam;

        CH::EventHandler::AddEvent(e);
        break;
    }

    // typing
    case WM_CHAR:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::KeyTyped);
        e->KeyTyped = wparam;
        CH::EventHandler::AddEvent(e);
        break;
    }

    //
    // Other mouse stuff
    //
    case WM_MOUSEWHEEL:
    {
        int delta = GET_WHEEL_DELTA_WPARAM(wparam);
       
        CH::Event* e = new CH::Event(CH::Event::EventTypes::MouseScrolled);
        e->MouseScrollOffset = delta;

        CH::EventHandler::AddEvent(e);
        break;
    }
    case WM_MOUSEMOVE:
    {
        POINTS pt = MAKEPOINTS(lparam);
        CH::Event* e = new CH::Event(CH::Event::EventTypes::MouseMoved);
        e->MousePos.x = pt.x;
        e->MousePos.y = pt.y;
        CH::EventHandler::AddEvent(e);
        break;
    }
    default:
    {
        CH::Event* e = new CH::Event(CH::Event::EventTypes::AppTick);
        CH::EventHandler::AddEvent(e);
        return DefWindowProc(hWnd, Msg, wparam, lparam);
    }
    }
    return NULL;
}

namespace CH {

    bool DX11Window::Init(DX11WindowData wndData)
    {
        m_WindowData = wndData;

        // create WNDCLASSEX for window creation
        WNDCLASSEX wc;
        wc.cbClsExtra = NULL;
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.cbWndExtra = NULL;
        wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
        wc.hInstance = NULL;
        wc.lpszClassName = L"MyWindowClass";    // this can be anything
        wc.lpszMenuName = L"";
        wc.style = NULL;
        wc.lpfnWndProc = &WndProc;

        // error checking...
        if (!::RegisterClassEx(&wc))
            return false;

        // create the window
        m_hWnd = ::CreateWindowEx(
            WS_EX_OVERLAPPEDWINDOW,
            L"MyWindowClass",       // must be the same as the 'lpszClassName'
            m_WindowData.Title,     // Winodw Title
            WS_OVERLAPPEDWINDOW,    // Window Type
            CW_USEDEFAULT, CW_USEDEFAULT,               // Window Position
            m_WindowData.Width, m_WindowData.Height,    // Window Size
            NULL,
            NULL,
            NULL,
            this
        );

        // more error checking...
        if (!m_hWnd)
            return false;

        // show and update the window
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

        // poll events
        while (::PeekMessage(&msg, m_hWnd, 0, 0, PM_REMOVE) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        RenderCommand::SwapBufers();
    }

    bool DX11Window::IsOpen()
    {
        return m_IsOpen;
    }

    DX11Window::DX11WindowData DX11Window::GetDX11WindowData()
    {
        return m_WindowData;
    }

    void DX11Window::SetDX11WindowData(DX11WindowData data)
    {
        // set window data
        m_WindowData = data;

        // get window position on the screen
        RECT rc;
        GetWindowRect(m_hWnd, &rc);

        // set the window position and width and height
        MoveWindow(m_hWnd, rc.left, rc.top, m_WindowData.Width, m_WindowData.Height, TRUE);

        // set the window text
        SetWindowText(m_hWnd, m_WindowData.Title);

        // Set VSync
        RenderCommand::SetVSync(data.isVsync);
    }

    void* DX11Window::GetNativeWindow()
    {
        return m_hWnd;
    }

    // these functions are not needed
    DX11Window::OpenGLWindowData DX11Window::GetOpenGLWindowData()
    {
        CH_CORE_WARN("Should call GetDX11WindowData()");
        return OpenGLWindowData();
    }
    
    bool DX11Window::Init(OpenGLWindowData wndData)
    {
        CH_CORE_WARN("Should call with DX11WindowData");
        return false;
    }
}