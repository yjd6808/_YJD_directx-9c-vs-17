#include "D3DManager.h"
#include "D3DApplication.h"

#include <iostream>

using namespace std;

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

D3DApplication * D3DManager::GetApplication()
{
	if (s_applicationInstance == nullptr) {
		cout << "D3DManager가 초기화 되지 않았습니다" << endl;
		return nullptr;
	}

	if (s_applicationInstance->m_application == nullptr) {
		cout << "현재 실행중인 어플리케이션이 없습니다." << endl;
		return nullptr;
	}

	return s_applicationInstance->m_application;
}

void D3DManager::SetApplication(D3DApplication * application)
{
	if (s_applicationInstance == nullptr) {
		s_applicationInstance = new D3DManager(application);
	}

	s_applicationInstance->m_application = application;
}

void D3DManager::ReleaseMemory()
{
	delete s_applicationInstance;
}

