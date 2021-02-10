#pragma once

#include "CoreEngine/Core/Layer/Layer.h"

namespace CH {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer() : Layer("ImGuiLayer")	{}
		~ImGuiLayer() {}

		void OnAttach() override;
		void OnDetach() override;
		void OnImGuiRender() override;

		void Begin();
		void End();
	};

}