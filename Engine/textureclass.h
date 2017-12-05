////////////////////////////////////////////////////////////////////////////////
// Filename: textureclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TEXTURECLASS_H_
#define _TEXTURECLASS_H_

#pragma comment ( lib, "d3dcompiler.lib" )
#pragma comment ( lib, "d3d11.lib" )

//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <wrl/client.h>

//#include <d3dx11tex.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: TextureClass
////////////////////////////////////////////////////////////////////////////////
class TextureClass
{
public:
	TextureClass();
	TextureClass(const TextureClass&);
	~TextureClass();

	bool Initialize(ID3D11Device* device, ID3D11DeviceContext* d3dContext, WCHAR* filename, ID3D11ShaderResourceView** textureView);
	void Shutdown();

	ID3D11ShaderResourceView* GetTexture();

private:
	//ID3D11Resource* m_texture;
	Microsoft::WRL::ComPtr <ID3D11Resource> m_texture;
	//Microsoft::WRL::ComPtr <ID3D11Texture2D> m_texture;

	//ID3D11ShaderResourceView* m_textureView;
	Microsoft::WRL::ComPtr <ID3D11ShaderResourceView> m_textureView;

};

#endif