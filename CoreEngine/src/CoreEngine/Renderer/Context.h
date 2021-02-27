#pragma once

namespace CH {

	class Context
	{
	public:
		virtual bool CreateContext(void* handle) = 0;
		virtual void DestroyContext() = 0;

		virtual void* GetContext() = 0;

	protected:
		void* m_Context;
	};

}