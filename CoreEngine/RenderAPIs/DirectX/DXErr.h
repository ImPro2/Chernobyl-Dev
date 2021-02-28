#pragma once

#include <d3d11.h>
#include <iostream>

#include "CoreEngine/Core/Core.h"

void CheckHResult(HRESULT hresult, std::string_view statement, std::string_view file, uint32_t line, std::string_view function);

#ifdef CH_DEBUG
    #define DXCALL(func)\
    {\
    	HRESULT hr = func;\
    	CheckHResult(hr, #func, __FILE__, __LINE__, __FUNCTION__);\
    }
#else
    #define DXCALL(func) func
#endif

void CheckHResult(HRESULT hresult, std::string_view statement, std::string_view file, uint32_t line, std::string_view function)
{
    if (FAILED(hresult))
    {
        LPSTR buffer;
        FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, hresult, 0, reinterpret_cast<LPSTR>(&buffer), 0, nullptr);
        CH_CORE_ASSERT(SUCCEEDED(hresult), "DX11 Error:\nFile: {0}\nLine: {1}\In Function: {2}\nDX Function: {3}\nError Message: {4}", file.data(), line, function.data(), statement.data(), buffer);
    }
}