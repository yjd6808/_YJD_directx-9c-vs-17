#include "D3DManager.h"
#include "D3DApplication.h"

D3DManager* D3DManager::s_applicationInstance = nullptr;

D3DManager::D3DManager(D3DApplication* application)
{
	m_application = application;
}

int D3DManager::RunApplication()
{
	return m_application->Run();
}

D3DManager::~D3DManager()
{
	delete m_application;
}

int D3DManager::StartApplication(D3DApplication* application)
{
	if (s_applicationInstance == nullptr) {
		s_applicationInstance = new D3DManager(application);
	}

	return s_applicationInstance->RunApplication();
}
