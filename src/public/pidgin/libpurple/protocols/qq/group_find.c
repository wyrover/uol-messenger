/**
 * @file group_find.c
 *
 * purple
 *
 * Purple is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */

#include "qq.h"

#include "conversation.h"
#include "debug.h"
#include "util.h"

#include "group_find.h"
#include "utils.h"

/* find a qq_buddy by uid, called by im.c */
qq_buddy *qq_group_find_member_by_uid(qq_group *group, guint32 uid)
{
	GList *list;
	qq_buddy *member;
	g_return_val_if_fail(group != NULL && uid > 0, NULL);

	list = group->members;
	while (list != NULL) {
		member = (qq_buddy *) list->data;
		if (member->uid == uid)
			return member;
		else
			list = list->next;
	}

	return NULL;
}

/* remove a qq_buddy by uid, called by qq_group_opt.c */
void qq_group_remove_member_by_uid(qq_group *group, guint32 uid)
{
	GList *list;
	qq_buddy *member;
	g_return_if_fail(group != NULL && uid > 0);

	list = group->members;
	while (list != NULL) {
		member = (qq_buddy *) list->data;
		if (member->uid == uid) {
			group->members = g_list_remove(group->members, member);
			return;
		} else {
			list = list->next;
		}
	}
}

qq_buddy *qq_group_find_or_add_member(PurpleConnection *gc, qq_group *group, guint32 member_uid)
{
	qq_buddy *member, *q_bud;
	PurpleBuddy *buddy;
	g_return_val_if_fail(group != NULL && member_uid > 0, NULL);

	member = qq_group_find_member_by_uid(group, member_uid);
	if (member == NULL) {	/* first appear during my session */
		member = g_new0(qq_buddy, 1);
		member->uid = member_uid;
		buddy = purple_find_buddy(purple_connection_get_account(gc), uid_to_purple_name(member_uid));
		if (buddy != NULL) {
			q_bud = (qq_buddy *) buddy->proto_data;
			if (q_bud != NULL && q_bud->nickname != NULL)
				member->nickname = g_strdup(q_bud->nickname);
			else if (buddy->alias != NULL)
				member->nickname = g_strdup(buddy->alias);
		}
		group->members = g_list_append(group->members, member);
	}

	return member;
}

/* find a qq_group by chatroom channel */
qq_group *qq_group_find_by_channel(PurpleConnection *gc, gint channel)
{
	PurpleConversation *conv;
	qq_data *qd;
	qq_group *group;
	GList *list;

	qd = (qq_data *) gc->proto_data;

	conv = purple_find_chat(gc, channel);
	g_return_val_if_fail(conv != NULL, NULL);

	list = qd->groups;
	group = NULL;
	while (list != NULL) {
		group = (qq_group *) list->data;
		if (group->title_utf8 == NULL) {
			continue;
		}
		if (!g_ascii_strcasecmp(purple_conversation_get_name(conv), group->title_utf8))
			break;
		list = list->next;
	}

	return group;
}

/* find a qq_group by its id, flag is QQ_INTERNAL_ID or QQ_EXTERNAL_ID */
qq_group *qq_room_search_ext_id(PurpleConnection *gc, guint32 ext_id)
{
	GList *list;
	qq_group *group;
	qq_data *qd;

	qd = (qq_data *) gc->proto_data;

	if (qd->groups == NULL || ext_id <= 0)
		return NULL;

	list = qd->groups;
	while (list != NULL) {
		group = (qq_group *) list->data;
		if (group->ext_id == ext_id) {
			return group;
		}
		list = list->next;
	}

	return NULL;
}

qq_group *qq_room_search_id(PurpleConnection *gc, guint32 room_id)
{
	GList *list;
	qq_group *group;
	qq_data *qd;

	qd = (qq_data *) gc->proto_data;

	if (qd->groups == NULL || room_id <= 0)
		return NULL;

	list = qd->groups;
	while (list != NULL) {
		group = (qq_group *) list->data;
		if (group->id == room_id) {
			return group;
		}
		list = list->next;
	}

	return NULL;
}

qq_group *qq_room_get_next(PurpleConnection *gc, guint32 room_id)
{
	GList *list;
	qq_group *group;
	qq_data *qd;
	gboolean is_find = FALSE;
	
	qd = (qq_data *) gc->proto_data;

	if (qd->groups == NULL) {
		return NULL;
	}
	
	 if (room_id <= 0) {
		return (qq_group *) qd->groups->data;
	}
	
	list = qd->groups;
	while (list != NULL) {
		group = (qq_group *) list->data;
		list = list->next;
		if (group->id == room_id) {
			is_find = TRUE;
			break;
		}
	}

	if ( !is_find || list == NULL) {
		return NULL;
	}

	return (qq_group *)list->data;
}

qq_group *qq_room_get_next_conv(PurpleConnection *gc, guint32 room_id)
{
	GList *list;
	qq_group *group;
	qq_data *qd;
	gboolean is_find;

	qd = (qq_data *) gc->proto_data;

 	list = qd->groups;
	if (room_id > 0) {
		/* search next room */
		is_find = FALSE;
		while (list != NULL) {
			group = (qq_group *) list->data;
			list = list->next;
			if (group->id == room_id) {
				is_find = TRUE;
				break;
			}
		}
		if ( !is_find || list == NULL) {
			return NULL;
		}
	}
	
	is_find = FALSE;
	while (list != NULL) {
		group = (qq_group *) list->data;
		if (group->my_role == QQ_ROOM_ROLE_YES || group->my_role == QQ_ROOM_ROLE_ADMIN) {
			if (NULL != purple_find_conversation_with_account(
						PURPLE_CONV_TYPE_CHAT,group->title_utf8, purple_connection_get_account(gc))) {
				/* In convseration*/
				is_find = TRUE;
				break;
			}
		}
		list = list->next;
	}

	if ( !is_find) {
		return NULL;
	}
	return group;
}
