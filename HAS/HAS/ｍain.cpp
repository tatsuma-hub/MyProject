/**
* ƒƒCƒ“ŠÖ”‚ÌÀ‘•.
*/
#include"stdafx.h"

/**
 * @fn	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow)
 *
 * @brief	Window main
 *
 * @author	tatsuma
 * @date	2019/12/22
 *
 * @param	hInstance	 	The instance.
 * @param	hPrevInstance	The previous instance.
 * @param	lpCmdLine	 	The command line.
 * @param	nCmdshow	 	The cmdshow.
 *
 * @returns	A WINAPI.
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdshow)
{
	//ƒGƒ“ƒWƒ“‚Ì‰Šú‰».
	engine::MainEngine::InitData initData;
	initData.m_name = "HAS";
	initData.m_screenSizeW = 1920;
	initData.m_screenSizeH = 1080;
	initData.m_frameSizeW = 7680;
	initData.m_frameSizeH = 4320;
	engine::MainEngine::Get().Initialize(initData);

	engine::MainEngine::Get().Run();

	return 0;
}