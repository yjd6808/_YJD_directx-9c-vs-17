#include "D3DManager.h"
#include "D3DConsole.h"

#include "_���ο�_3D���ø����̼�.h"
#include "_3D_���ð���.h"

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
	cout << "���� > ";
	cin >> choose;
	return choose;
}

using namespace std;


//���� ������� �����ҷ��� ���� �ڵ带 ���� �ٲ���� �������Ƿ� ���ο� �ٰܳ־���. �ڵ尡 ����� �������� �н����̹Ƿ� �Ѿ��...
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPWSTR    lpCmdLine, 
	_In_ int       nCmdShow) {

	D3DConsole::Initialize();
	D3DConsole::MoveTo(0, 0);
	D3DConsole::SetWidth(300);
	D3DConsole::SetHeight(200);

	appVec.push_back(new _���ο�_3D���ø����̼�(hInstance, hPrevInstance, lpCmdLine, nCmdShow));
	appVec.push_back(new _3D_���ð���(hInstance, hPrevInstance, lpCmdLine, nCmdShow));

	while (true) {
		int choose = selectMenu();
		if (choose >= appVec.size() || choose < 0)
			cout << "�ٽ� �������ּ���." << endl;
		else {
			system("cls");
			D3DManager::SetApplication(appVec[choose]);
			
			std::thread th([&]() {appVec[choose]->Run(); });
			std::string anyMsg;
			cout << "�ƹ�Ű�� �Է��ϼ���." << endl;
			cin >> anyMsg;
			appVec[choose]->Close ();
			th.join();

			system("cls");
		}
	}


	int _exitCode = D3DManager::StartApplication(new _���ο�_3D���ø����̼�(hInstance, hPrevInstance, lpCmdLine, nCmdShow));
	D3DManager::ReleaseMemory();
	return _exitCode;
}