#include "D3DManager.h"
#include "D3DConsole.h"

#include "_공부용_3D어플리케이션.h"
#include "_3D_슈팅게임.h"

#include <iostream>
#include <thread>
#include <vector>
#include <iostream>

using namespace std;

vector<D3DApplication*> appVec;

int selectMenu()
{
	int choose = -1;
	for (int i = 0; i < appVec.size(); i++)
		cout << i << ". " << appVec[i]->GetApplicationName() << endl;
	cout << "선택 > ";
	cin >> choose;
	return choose;
}

using namespace std;


//다중 윈도우로 구현할려니 이전 코드를 많이 바꿔야함 귀찮으므로 메인에 꾸겨넣었다. 코드가 상당히 더럽지만 학습용이므로 넘어가자...
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPWSTR    lpCmdLine, 
	_In_ int       nCmdShow) {

	D3DConsole::Initialize();
	D3DConsole::MoveTo(0, 0);
	D3DConsole::SetWidth(300);
	D3DConsole::SetHeight(200);

	appVec.push_back(new _공부용_3D어플리케이션(hInstance, hPrevInstance, lpCmdLine, nCmdShow));
	appVec.push_back(new _3D_슈팅게임(hInstance, hPrevInstance, lpCmdLine, nCmdShow));

	while (true) {
		int choose = selectMenu();
		if (choose >= appVec.size() || choose < 0)
			cout << "다시 선택해주세요." << endl;
		else {
			system("cls");
			D3DManager::SetApplication(appVec[choose]);
			
			std::thread th([&]() {appVec[choose]->Run(); });
			std::string anyMsg;
			cout << "아무키나 입력하세요." << endl;
			cin >> anyMsg;
			appVec[choose]->Close ();
			th.join();

			system("cls");
		}
	}


	int _exitCode = D3DManager::StartApplication(new _공부용_3D어플리케이션(hInstance, hPrevInstance, lpCmdLine, nCmdShow));
	D3DManager::ReleaseMemory();
	return _exitCode;
}