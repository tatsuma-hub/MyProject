/**
 * @file	MainEngine.cpp.
 *
 * @brief	エンジンクラスの実装.
 */
#include"engine_stdafx.h"
#include"MainEngine.h"

namespace engine {

	MainEngine::MainEngine()
		: m_pHWnd(nullptr)
	{
	}

	MainEngine::~MainEngine()
	{
	}

	bool MainEngine::Initialize(const InitData & initData)
	{
		//ウィンドウの初期化.
		if (!InitWindow(initData))
		{
			_ASSERT(false, "Window初期化できねぇ.");
			return false;
		}

		return true;
	}

	void MainEngine::Run()
	{
		MSG msg = { 0 };
		while (WM_QUIT != msg.message)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
			}
		}
	}

	bool MainEngine::InitWindow(const InitData & initData)
	{
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX),
			CS_CLASSDC,
			MsgProc,
			0L, 0L,
			GetModuleHandle(nullptr),
			nullptr,
			LoadCursor(NULL, IDC_ARROW),
			nullptr,
			nullptr,
			(LPCSTR)initData.m_name.c_str(),
			nullptr
		};
		RegisterClassEx(&wc);

		RECT rd;
		HWND hDeskWnd = GetDesktopWindow();
		GetWindowRect(hDeskWnd, &rd);

		//ウィンドウ作成
		m_pHWnd = CreateWindow(
			(LPCSTR)initData.m_name.c_str(),
			(LPCSTR)initData.m_name.c_str(),
			WS_SYSMENU | WS_MINIMIZEBOX,
			(rd.right - initData.m_screenSizeW) / 2,
			(rd.bottom - initData.m_screenSizeH) / 2,
			initData.m_screenSizeW,
			initData.m_screenSizeH,
			nullptr,
			nullptr,
			wc.hInstance,
			nullptr
		);

		RECT rw, cw;
		GetWindowRect(m_pHWnd, &rw);
		GetClientRect(m_pHWnd, &cw);

		//ウィンドウの初期位置計算
		int new_width = (rw.right - rw.left) - (cw.right - cw.left) + initData.m_screenSizeW;
		int new_height = (rw.bottom - rw.top) - (cw.bottom - cw.top) + initData.m_screenSizeH;

		//スクリーン座標（0,0）にウィンドウを初期配置
		SetWindowPos(m_pHWnd, NULL, (rd.right - new_width) / 2, 0, new_width, new_height, SWP_SHOWWINDOW);

		ShowWindow(m_pHWnd, SW_SHOWDEFAULT);

		return (m_pHWnd != nullptr);
	}

	void MainEngine::Release()
	{
	}

	/**
	* ウィンドウプロシージャ.
	*/
	LRESULT MainEngine::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_KEYDOWN: // キーを押したとき
			switch (wParam)
			{
			case VK_ESCAPE: // エスケープキー
				Get().Release();
				PostQuitMessage(0);
				return 0;
			}
			break;
		case WM_DESTROY: // 削除.
			Get().Release();
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
		return 0L;
	}

} // namespace engine.