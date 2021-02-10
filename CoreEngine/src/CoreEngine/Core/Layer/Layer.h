#pragma once

#include "CoreEngine/Core/Core.h"
#include "CoreEngine/Core/Log/Log.h"

namespace CH {

	class LayerHandler;

	class Layer
	{
	public:
		Layer(std::string debugName) : m_DebugName(debugName) {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent() {}
		virtual void OnImGuiRender() {}

		int GetLayerIndex() const { return m_LayerIndex; }

	private:
		std::string m_DebugName;
		int m_LayerIndex;

		friend class LayerHandler;
	};

}