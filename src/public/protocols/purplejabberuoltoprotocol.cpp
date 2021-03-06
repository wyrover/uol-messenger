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
 
#include "purplejabberuoltoprotocol.h"

#include <string>

using namespace std;


const char* CPurpleJabberUOLTOProtocol::PURPLE_JABBER_UOLTO_PLUGIN_ID = "prpl-uolto";
const char* CPurpleJabberUOLTOProtocol::PURPLE_JABBER_UOLTO_PROTOCOL_NAME = "TodaOferta";
const char* CPurpleJabberUOLTOProtocol::PURPLE_JABBER_UOLTO_DEFAULT_RESOURCE = "todaoferta: UOL Messenger";
char CPurpleJabberUOLTOProtocol::PURPLE_JABBER_UOLTO_RESOURCE_SPLITTER = '/';


CPurpleJabberUOLTOProtocol::CPurpleJabberUOLTOProtocol() :
	CPurpleJabberUOLProtocol(PURPLE_JABBER_UOLTO_PLUGIN_ID, PURPLE_JABBER_UOLTO_PROTOCOL_NAME)
{
}


CPurpleJabberUOLTOProtocol::~CPurpleJabberUOLTOProtocol()
{
}


bool CPurpleJabberUOLTOProtocol::HasFileTransferSupport()
{
	return false;
}


bool CPurpleJabberUOLTOProtocol::HasReRequestAuthorizationSupport()
{
	return false;
}


IMProtocolError CPurpleJabberUOLTOProtocol::CanRequestContactAuthorization(const std::string& strUser, const std::string& strContact, bool& bCanRequest)
{
	return CPurpleProtocol::CanRequestContactAuthorization(strUser, strContact, bCanRequest);
}


IMProtocolError CPurpleJabberUOLTOProtocol::RequestContactAuthorization(const std::string& strUser, const std::string& strContact)
{
	return CPurpleProtocol::RequestContactAuthorization(strUser, strContact);
}


bool CPurpleJabberUOLTOProtocol::HasContactListSupport()
{
	return false;
}


bool CPurpleJabberUOLTOProtocol::IsValidUserName(const string& strUser)
{
	bool bValid = CPurpleJabberProtocol::IsValidUserName(strUser);

	if (bValid)
	{
		string::size_type npos = -1;

		npos = strUser.find("@todaoferta.uol.com.br");

		bValid = (npos == -1);
	}

	return bValid;
}


void CPurpleJabberUOLTOProtocol::Init()
{
	CPurpleJabberUOLProtocol::Init();
}


void CPurpleJabberUOLTOProtocol::Finalize()
{
	CPurpleJabberUOLProtocol::Finalize();
}


string CPurpleJabberUOLTOProtocol::GetNormalizedPurpleUserName(const string& strUserName)
{
	string strNormalizedName = strUserName;

	string::size_type indexFind;
	string::size_type npos = -1;

	indexFind = strNormalizedName.find(PURPLE_JABBER_UOLTO_RESOURCE_SPLITTER);

	if (indexFind != npos)
	{
		strNormalizedName = strNormalizedName.erase(indexFind);
	}

	strNormalizedName += PURPLE_JABBER_UOLTO_RESOURCE_SPLITTER;
	strNormalizedName += PURPLE_JABBER_UOLTO_DEFAULT_RESOURCE;

	return strNormalizedName;
}
