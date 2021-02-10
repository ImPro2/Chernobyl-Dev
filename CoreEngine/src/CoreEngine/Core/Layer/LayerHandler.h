#pragma once

#include "Layer.h"

namespace CH {

	class LayerHandler
	{
	public:
		static void Init();
		static void Destroy();

		static void AddFront(Layer* layer);
		static void AddBack(Layer* layer);

		static void RemoveFront(Layer* layer);
		static void RemoveBack(Layer* layer);

		static std::vector<Layer*>::iterator begin() { return m_LayerStack.begin(); }
		static std::vector<Layer*>::iterator end() { return m_LayerStack.end(); }

		static std::vector<Layer*> GetLayerStack() { return m_LayerStack; }

	private:
		static std::vector<Layer*> m_LayerStack;
		static std::vector<Layer*>::iterator m_LayerInsert;
		static int m_LayerCount;
	};

}