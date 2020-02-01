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
#include "engine_stdafx.h"
#include "DXSample.h"

using namespace Microsoft::WRL;

namespace engine
{

	DXSample::DXSample(UINT width, UINT height, std::string name) :
		m_width(width),
		m_height(height),
		m_title(name),
		m_useWarpDevice(false)
	{
		char assetsPath[512];
		GetAssetsPath(assetsPath, _countof(assetsPath));
		m_assetsPath = assetsPath;

		m_aspectRatio = static_cast<float>(width) / static_cast<float>(height);
	}

	DXSample::~DXSample()
	{
	}

	// Helper function for resolving the full path of assets.
	std::string DXSample::GetAssetFullPath(const char* assetName)
	{
		return m_assetsPath + assetName;
	}

	// Helper function for acquiring the first available hardware adapter that supports Direct3D 12.
	// If no such adapter can be found, *ppAdapter will be set to nullptr.
	_Use_decl_annotations_
		void DXSample::GetHardwareAdapter(IDXGIFactory2* pFactory, IDXGIAdapter1** ppAdapter)
	{
		ComPtr<IDXGIAdapter1> adapter;
		*ppAdapter = nullptr;

		for (UINT adapterIndex = 0; DXGI_ERROR_NOT_FOUND != pFactory->EnumAdapters1(adapterIndex, &adapter); ++adapterIndex)
		{
			DXGI_ADAPTER_DESC1 desc;
			adapter->GetDesc1(&desc);

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{
				// Don't select the Basic Render Driver adapter.
				// If you want a software adapter, pass in "/warp" on the command line.
				continue;
			}

			// Check to see if the adapter supports Direct3D 12, but don't create the
			// actual device yet.
			if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, _uuidof(ID3D12Device), nullptr)))
			{
				break;
			}
		}

		*ppAdapter = adapter.Detach();
	}

	// Helper function for setting the window's title text.
	void DXSample::SetCustomWindowText(const char* text)
	{
		std::string windowText = m_title + ": " + text;
		//SetWindowText(Win32Application::GetHwnd(), windowText.c_str());
	}

	// Helper function for parsing any supplied command line args.
	_Use_decl_annotations_
		void DXSample::ParseCommandLineArgs(char* argv[], int argc)
	{
		for (int i = 1; i < argc; ++i)
		{
			if (_strnicmp(argv[i], "-warp", strlen(argv[i])) == 0 ||
				_strnicmp(argv[i], "/warp", strlen(argv[i])) == 0)
			{
				m_useWarpDevice = true;
				m_title = m_title + " (WARP)";
			}
		}
	}

}