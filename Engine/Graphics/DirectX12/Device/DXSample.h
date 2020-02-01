//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
#pragma once

#include "DXSampleHelper.h"

namespace engine
{

	class DXSample
	{
	public:
		DXSample(UINT width, UINT height, std::string name);
		virtual ~DXSample();

		virtual void OnInit() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnRender() = 0;
		virtual void OnDestroy() = 0;

		// Samples override the event handlers to handle specific messages.
		virtual void OnKeyDown(UINT8 /*key*/) {}
		virtual void OnKeyUp(UINT8 /*key*/) {}

		// Accessors.
		UINT GetWidth() const { return m_width; }
		UINT GetHeight() const { return m_height; }
		const char* GetTitle() const { return m_title.c_str(); }

		void ParseCommandLineArgs(_In_reads_(argc) char* argv[], int argc);

	protected:
		std::string GetAssetFullPath(const char* assetName);
		void GetHardwareAdapter(_In_ IDXGIFactory2* pFactory, _Outptr_result_maybenull_ IDXGIAdapter1** ppAdapter);
		void SetCustomWindowText(const char* text);

		// Viewport dimensions.
		UINT m_width;
		UINT m_height;
		float m_aspectRatio;

		// Adapter info.
		bool m_useWarpDevice;

	private:
		// Root assets path.
		std::string m_assetsPath;

		// Window title.
		std::string m_title;
	};

}