/**
 * @file	MainEngine.h.
 *
 * @brief	�G���W���N���X�̒�`.
 */
#pragma once

namespace engine {

	/**
	 * @class	MainEngine
	 *
	 * @brief	�G���W���N���X. �V���O���g���N���X.
	 *
	 * @author	tatsuma
	 * @date	2019/12/22
	 */
	class MainEngine
	{
	public:

		/**
		 * @class	InitData
		 *
		 * @brief	An initialize data.
		 *
		 * @author	tatsuma
		 * @date	2019/12/22
		 */
		class InitData
		{
		public:

			/** @brief	�X�N���[���̉���. */
			int m_screenSizeW = 1920;
			/** @brief	�X�N���[���̍���. */
			int m_screenSizeH = 1800;
			/** @brief	�����𑜓x�̉���. */
			int m_frameSizeW = 1920;
			/** @brief	�����𑜓x�̍���. */
			int m_frameSizeH = 1800;
			/** @brief	�Q�[���̕\���� */
			std::string m_name = "Game";
		};

	private:

		MainEngine();
		~MainEngine();
	
	public:

		/**
		* �C���X�^���X�̎擾.
		*/
		static MainEngine& Get()
		{
			static MainEngine instance;
			return instance;
		}

		/**
		 * @fn	bool MainEngine::Initialize(const InitData& initData);
		 *
		 * @brief	Initializes this object
		 *
		 * @author	tatsuma
		 * @date	2019/12/22
		 *
		 * @param	initData	Information describing the initialize.
		 *
		 * @returns	True if it succeeds, false if it fails.
		 */
		bool Initialize(const InitData& initData);

		/**
		 * @fn	void Run();
		 *
		 * @brief	Runs this object
		 *
		 * @author	tatsuma
		 * @date	2019/12/22
		 */
		void Run();

	private:

		/**
		 * @fn	bool MainEngine::InitWindow(const InitData& initData);
		 *
		 * @brief	Initializes the window
		 *
		 * @author	tatsuma
		 * @date	2019/12/22
		 *
		 * @param	initData	Information describing the initialize.
		 *
		 * @returns	True if it succeeds, false if it fails.
		 */
		bool InitWindow(const InitData& initData);

		/**
		 * @fn	void MainEngine::Release();
		 *
		 * @brief	�J��.
		 *
		 * @author	tatsuma
		 * @date	2019/12/22
		 */
		void Release();

		/**
		 * @fn	static LRESULT CALLBACK MainEngine::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		 *
		 * @brief	�E�B���h�E�v���V�[�W��.
		 *
		 * @author	tatsuma
		 * @date	2019/12/22
		 *
		 * @param	hWnd  	Handle of the window.
		 * @param	msg   	The message.
		 * @param	wParam	The wParam field of the message.
		 * @param	lParam	The lParam field of the message.
		 *
		 * @returns	A CALLBACK.
		 */
		static LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	private:
		/** @brief	�E�B���h�E�n���h��. */
		HWND m_pHWnd;

	};

} // namespace engine.