#pragma once
#include <Tigris.h>


class MenuLayer : public Tigris::Layer
{

public:
	void OnAtach() override;


	void OnDetach() override;


	void OnEvent(Tigris::Event& e) override;


	void OnUpdate(Tigris::TimeInterval dt) override;

private:
	Tigris::Camera m_Camera;
};