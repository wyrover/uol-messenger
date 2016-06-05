/*
 * WengoPhone, a voice over Internet phone
 * Copyright (C) 2004-2006  Wengo
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef OWSLOT_H
#define OWSLOT_H

#include <util/NonCopyable.h>

#include <boost/function.hpp>

class IPostEvent;

struct Slot : NonCopyable {

	Slot(const boost::function<Signature> & _slot, IPostEvent * _postEvent) {
		slot = _slot;
		postEvent = _postEvent;
	}

	/** Slot/observer/event handler. */
	boost::function<Signature> slot;

	/** Destination threads of the event. */
	IPostEvent * postEvent;
};

#endif	//OWSLOT_H