/**
 * @file	engine_stdafx.h.
 *
 * @brief	�v���R���p�C���ς݃w�b�_�̒�`.
 */
#pragma once

///<  Windows �w�b�_�[����g�p����Ă��Ȃ����������O���܂�.
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

///< ����w�b�_�C���N���[�h.
#include"MainEngine.h"