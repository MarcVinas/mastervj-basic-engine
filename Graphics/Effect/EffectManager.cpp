#include "EffectManager.h"
#include "EffectTechnique.h"
#include "Effect/EffectVertexShader.h"
#include "Effect/EffectPixelShader.h"

#include <XML/XMLTreeNode.h>


CEffectManager::CEffectManager()
{
}


CEffectManager::~CEffectManager()
{
}


void CEffectManager::Reload()
{
}


void CEffectManager::load(const std::string &Filename)
{
	CXMLTreeNode l_XML;
	if (l_XML.LoadFile(Filename.c_str()))
	{
		CXMLTreeNode l_Effects = l_XML["effects"];
		if (l_Effects.Exists())
		{
			for (int i = 0; i < l_Effects.GetNumChildren(); ++i)
			{
				CXMLTreeNode l_Effect = l_Effects(i);

				if (l_Effect.GetName() == std::string("effect_technique"))
				{
					CEffectTechnique * Effect = new CEffectTechnique(l_Effect);
					add(Effect->getName(), Effect);
				}
				else if (l_Effect.GetName() == std::string("vertex_shader"))
				{
					CEffectVertexShader * Effect = new CEffectVertexShader(l_Effect);
					m_VertexShaders.add(Effect->getName(), Effect);
				}
				else if (l_Effect.GetName() == std::string("pixel_shader"))
				{
					CEffectPixelShader * Effect = new CEffectPixelShader(l_Effect);
					m_PixelShaders.add(Effect->getName(), Effect);
				}
			}
		}
	}
}


CEffectVertexShader * CEffectManager::GetVertexShader(const std::string &VertexShader)
{
	return nullptr;
}


CEffectPixelShader * CEffectManager::GetPixelShader(const std::string &PixelShader)
{
	return nullptr;
}
