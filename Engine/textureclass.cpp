////////////////////////////////////////////////////////////////////////////////
// Filename: textureclass.cpp
////////////////////////////////////////////////////////////////////////////////
#pragma comment(lib, "DirectXTK.lib")

#include "textureclass.h"
#include "DDSTextureLoader.h"

using namespace DirectX;

TextureClass::TextureClass()
{
	m_texture = 0;
}


TextureClass::TextureClass(const TextureClass& other)
{}


TextureClass::~TextureClass()
{
}


bool TextureClass::Initialize(ID3D11Device* device, ID3D11DeviceContext* d3dContext, WCHAR* filename, ID3D11ShaderResourceView** textureView)
{
	HRESULT result;

	// Load the texture in.
	result = CreateDDSTextureFromFile(device, d3dContext, filename, &m_texture, &m_textureView);

		//@REFERENCE
		//HRESULT __cdecl CreateDDSTextureFromFile(
		//	_In_ ID3D11Device* d3dDevice,
		//	_In_opt_ ID3D11DeviceContext* d3dContext,
		//	_In_z_ const wchar_t* szFileName,
		//	_Outptr_opt_ ID3D11Resource** texture,
		//	_Outptr_opt_ ID3D11ShaderResourceView** textureView,
		//	_In_ size_t maxsize = 0,
		//	_Out_opt_ DDS_ALPHA_MODE* alphaMode = nullptr);

	//D3DX11CreateShaderResourceViewFromFile(device, filename, NULL, NULL, &m_texture, NULL);
	if(FAILED(result))
	{
		return false;
	}

	return true;
}


void TextureClass::Shutdown()
{
	// Release the texture resource.
	if(m_texture)
	{
		m_texture->Release();
		m_texture = 0;
	}

	if (m_textureView)
	{
		m_textureView->Release();
		m_textureView = 0;
	}

	return;
}


ID3D11ShaderResourceView* TextureClass::GetTexture()
{
	return m_textureView;
}