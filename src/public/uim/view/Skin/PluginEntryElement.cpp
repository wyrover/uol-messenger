/* UOL Messenger
 * Copyright (c) 2005 Universo Online S/A
 *
 * Direitos Autorais Reservados
 * All rights reserved
 *
 * Este programa � software livre; voc� pode redistribu�-lo e/ou modific�-lo
 * sob os termos da Licen�a P�blica Geral GNU conforme publicada pela Free
 * Software Foundation; tanto a vers�o 2 da Licen�a, como (a seu crit�rio)
 * qualquer vers�o posterior.
 * Este programa � distribu�do na expectativa de que seja �til, por�m,
 * SEM NENHUMA GARANTIA; nem mesmo a garantia impl�cita de COMERCIABILIDADE
 * OU ADEQUA��O A UMA FINALIDADE ESPEC�FICA. Consulte a Licen�a P�blica Geral
 * do GNU para mais detalhes. 
 * Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral do GNU junto
 * com este programa; se n�o, escreva para a Free Software Foundation, Inc.,
 * no endere�o 59 Temple Street, Suite 330, Boston, MA 02111-1307 USA. 
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Universo Online S/A - A/C: UOL Messenger 5o. Andar
 * Avenida Brigadeiro Faria Lima, 1.384 - Jardim Paulistano
 * S�o Paulo SP - CEP 01452-002 - BRASIL  */
 
#include "stdafx.h"
#include "PluginEntryElement.h"

#include "../IPainterRepository.h"


CPluginEntryElement::CPluginEntryElement()
{
}


CPluginEntryElement::~CPluginEntryElement()
{
}


IPainter* CPluginEntryElement::GetPainter(UINT nPainterId) const
{
	CString strPainterName;

	switch (nPainterId)
	{
	case IPainterRepository::PR_PLUGIN_DEFAULT_PAINTER:
		strPainterName = "__PluginDefaultPainterInstance_";
		break;

	case IPainterRepository::PR_PLUGIN_SELECTION_PAINTER:
		strPainterName = "__PluginSelectionPainterInstance_";
		break;
	}

	return FindPainter(strPainterName);
}


CString CPluginEntryElement::GetName() const
{
	return "__PluginEntryElementInstance";
}

CFontElementPtr CPluginEntryElement::GetTitleTextFont() const
{
	return m_pTitleTextFont;
}


COLORREF CPluginEntryElement::GetTitleTextColor() const
{
	return m_clrTitleText;
}


void CPluginEntryElement::SetParameters(CString2StringMapPtr& pMapParams, IElementTable* pElementTable)
{	
	__super::SetParameters(pMapParams, pElementTable);

	try
	{
		CString strTitleFontName;
		GetParameterValue(strTitleFontName, pMapParams, "TitleFont");

		m_pTitleTextFont = ap_dynamic_cast<CFontElementPtr>(pElementTable->GetElement(strTitleFontName));
		ATLASSERT(m_pTitleTextFont.get());
	}
	catch(const CSkinException&)
	{
		ATLTRACE(_T("%s - %s\n"), __FUNCTION__, "TitleFont");
		// use default system font
		m_pTitleTextFont = new CFontElement();
	}

	try
	{
		CString strTitleTextColor;
		GetParameterValue(strTitleTextColor, pMapParams, "TitleTextColor");		

		m_clrTitleText.SetColor(strTitleTextColor);
	}
	catch(const CSkinException&)
	{
		ATLTRACE(_T("%s - %s\n"), __FUNCTION__, "TitleTextColor");
		// Use font color
		m_clrTitleText = m_pTitleTextFont->GetColor();
	}
}


IPainter* CPluginEntryElement::FindPainter(const CString& strElementName) const
{
	for (POSITION pos = m_listChilds.GetHeadPosition(); pos;)
	{
		const IElement* pElement = m_listChilds.GetNext(pos).get();

		CString strElement = pElement->GetName();
        if (-1 != strElement.Find(strElementName))
		{
			IPainter* pPainter = dynamic_cast<IPainter*>(const_cast<IElement*>(pElement));

			return pPainter;
		}
	}

	return NULL;
}