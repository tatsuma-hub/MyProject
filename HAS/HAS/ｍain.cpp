/**
 * @file	ｍain.cpp.
 *
 * @brief	Implements the ｍain class
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
	// エンジンの初期化.
	engine::MainEngine::InitData initData;
	initData.m_pHInstance = hInstance;
	initData.m_name = "HAS";
	initData.m_screenSizeW = 1920 * 0.9;
	initData.m_screenSizeH = 1080 * 0.9;
	initData.m_frameSizeW = 1920 * 8; // 4K解像度的な.
	initData.m_frameSizeH = 1080 * 8; // 4K解像度的な.
	engine::MainEngine::Get().Initialize(initData);

	// ゲームループ.
	engine::MainEngine::Get().Run();

	return 0;
}