#pragma once

#include "CoreEngine/Core/Layer/Layer.h"

namespace CH {

	class ImGuiLayer : public Layer
	{
	public:
		// constructor and destructor
		ImGuiLayer();
		~ImGuiLayer();

		// initializations and destruction
		void OnAttach() override;
		void OnDetach() override;

		// called before and after OnImGuiRender() to actually render stuff
		void Begin();
		void End();

		// called when something can be rendered
		void OnImGuiRender() override;
	};

}