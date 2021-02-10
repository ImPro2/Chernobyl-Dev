#pragma once

namespace CH {

	class SwapChain
	{
	public:
		virtual void Init() = 0;
		virtual void Present() = 0;
	};

}