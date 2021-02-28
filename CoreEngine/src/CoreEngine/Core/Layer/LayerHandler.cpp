#include "chpch.h"
#include "LayerHandler.h"

namespace CH {

	std::vector<Layer*>				LayerHandler::m_LayerStack;
	std::vector<Layer*>::iterator	LayerHandler::m_LayerInsert;
	int								LayerHandler::m_LayerCount;

	void LayerHandler::Init()
	{
		m_LayerInsert = m_LayerStack.begin();
	}

	void LayerHandler::Destroy()
	{
		for (Layer* layer : m_LayerStack)
			delete layer;
	}

	void LayerHandler::AddFront(Layer* layer)
	{
		m_LayerInsert = m_LayerStack.emplace(m_LayerInsert, layer);
		m_LayerCount = m_LayerStack.size();
		layer->OnAttach();
	}

	void LayerHandler::AddBack(Layer* layer)
	{
		m_LayerStack.emplace_back(layer);
		m_LayerCount = m_LayerStack.size();
		layer->OnAttach();
	}

	void LayerHandler::RemoveFront(Layer* layer)
	{
		auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
		if (it != m_LayerStack.end())
		{
			m_LayerStack.erase(it);
			m_LayerInsert--;
		}
		layer->OnDetach();
	}

	void LayerHandler::RemoveBack(Layer* layer)
	{
		auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
		if (it != m_LayerStack.end())
			m_LayerStack.erase(it);
		layer->OnDetach();
	}

}