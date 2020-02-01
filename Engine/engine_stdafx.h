/**
 * @file	engine_stdafx.h.
 *
 * @brief	プリコンパイル済みヘッダの定義.
 */
#pragma once

///<  Windows ヘッダーから使用されていない部分を除外します.
#define WIN32_LEAN_AND_MEAN

///< Win.
#include<Windows.h>

///< DirectX.
#include "Graphics/DirectX12/Device/d3dx12.h"

///< STD.
#include <string>
#include <wrl.h>
#include <shellapi.h>

#define r_cast reinterpret_cast
#define	s_cast static_cast
#define	c_cast const_cast

///< 自作ヘッダインクルード.
#include"MainEngine.h"