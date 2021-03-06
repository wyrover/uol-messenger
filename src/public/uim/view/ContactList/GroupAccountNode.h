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
 
#pragma once

#include "../GroupListCtrl/EntryGroup.h"
#include "../IPainterRepository.h"
#include "ComparatorAdapter.h"
#include "GroupNode.h"
#include "../FindContactPanel.h"

#include "../skin/FontElement.h"

#include <interfaces/IUOLMessengerAccount.h>
#include <interfaces/IUOLMessengerAccountConnectionManager.h>


using namespace GroupListCtrl;


class CGroupAccountNode : 
		public CGroupNode,
		public CUOLMessengerAccountObserver,
		public CUOLMessengerAccountListEventListener, 
		public CUOLMessengerAccountConnectionManagerObserver
{
public:
	
	CGroupAccountNode(IUOLMessengerAccountPtr pAccount);
	virtual ~CGroupAccountNode();
	
	IUOLMessengerAccountPtr GetAccount() const;
	void SetFindContactPanel(CFindContactPanelPtr pFindContactPanel);
	
protected:
	
	virtual CString GetName() const;
	
	virtual BOOL IsVisible() const;
	
	virtual int Compare(const CEntryGroup* pEntryGroup) const;
	
	virtual void Paint(CDCHandle& dc);
	
	// CUOLMessengerAccountObserver interface
	virtual void OnNickNameChanged(IUOLMessengerAccount* pAccount);
	
	// CUOLMessengerAccountListEventListener interface.
	virtual void OnRemoveAccount(IUOLMessengerAccountPtr pAccount);
	
	// CUOLMessengerAccountConnectionManagerObserver interface
	virtual void OnConnected(IUOLMessengerAccountPtr pAccount);
	virtual void OnDisconnected(IUOLMessengerAccountPtr pAccount);
	virtual void OnReportDisconnect(IUOLMessengerAccountPtr pAccount, ConnectionError error, const CString& strMessage);
	virtual void OnStatusChanged(IUOLMessengerAccountPtr pAccount);
	
private:
	void DrawStatus(CDCHandle& dc);
	void DrawText(CDCHandle& dc);
	
private:
#ifdef _LEAKDEBUG
	static LONG ms_nRefs;
#endif
	
	IUOLMessengerAccountPtr		m_pAccount;
	CRect						m_rectStatus;
	CFindContactPanelPtr		m_pFindContactPanel;
}; 

MAKEAUTOPTR(CGroupAccountNode);

