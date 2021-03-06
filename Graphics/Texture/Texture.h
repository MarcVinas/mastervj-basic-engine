#pragma once

#include <Utils/Named.h>

class ID3D11ShaderResourceView;
class ID3D11SamplerState;

class CTexture : CNamed
{
private:
	ID3D11ShaderResourceView *m_Texture;
	ID3D11SamplerState *m_SamplerState;

	virtual bool LoadFile();
	void Unload();
public:
	CTexture();
	virtual ~CTexture();
	bool load(const std::string &Filename);
	void Activate(unsigned int StageId);
	bool Reload();
};

