#ifndef EFFECT_PIXEL_SHADER
#define EFFECT_PIXEL_SHADER

#include "Effect\EffectShader.h"

class CEffectPixelShader : public CEffectShader
{
protected:
	ID3D11PixelShader *m_PixelShader;
	void Destroy();
public:
	CEffectPixelShader(const CXMLTreeNode &TreeNode);
	virtual ~CEffectPixelShader();
	bool Load();
	ID3D11PixelShader * GetPixelShader() { return m_PixelShader; }
	ID3D11Buffer * GetConstantBuffer() { return m_ConstantBuffer; }
};

#endif