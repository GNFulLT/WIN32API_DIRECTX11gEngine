#include <Windows.h>
#include "WindowsMessageMap.h"
#include "./CommandBase/Interfaces/ICommand.h"

#include "Engine/GameEngine.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevinstance, LPSTR lpszCmdline, int nCmdShow)
{
	std::string appName = "GNF_ENGINE";


	//Try to find if application is running
	HANDLE prevMutex = OpenMutexA(NULL, FALSE, appName.c_str());
	if (prevMutex)
		return -1;


	HANDLE mutex = CreateMutexA(NULL, FALSE,appName.c_str());

	//Mutex Error
	if(mutex == NULL)
	{
		return -1;
	}
	
	GameEngine::StartEngine(640, 480, std::wstring(appName.begin(),appName.end()).c_str(), L"Ýlk Ekraným");
	

	GameEngine* const gEngine = GameEngine::GetInstance();

	if (gEngine->IsReady()) 
	{
		int exitCode = gEngine->Run();
		return exitCode;
	}

	return  -1;

}