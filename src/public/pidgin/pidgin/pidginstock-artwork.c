/**
 * @file pidginstock.c GTK+ Stock resources
 * @ingroup pidgin
 */

/* pidgin
 *
 * Pidgin is the legal property of its developers, whose names are too numerous
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
 *
 */
#include "internal.h"
#include "pidgin.h"

#include "pidginstock.h"

static struct StockIcon
{
	const char *name;
	const char *dir;
	const char *filename;

} const stock_icons[] =
{
	{ PIDGIN_STOCK_ACTION,          NULL,      GTK_STOCK_EXECUTE          },
#if GTK_CHECK_VERSION(2,6,0)
	{ PIDGIN_STOCK_ALIAS,           NULL,      GTK_STOCK_EDIT             },
#else
	{ PIDGIN_STOCK_ALIAS,           "buttons", "edit.png"                 },
#endif
	{ PIDGIN_STOCK_CHAT,            NULL,      GTK_STOCK_JUMP_TO          },
	{ PIDGIN_STOCK_CLEAR,           NULL,      GTK_STOCK_CLEAR            },
	{ PIDGIN_STOCK_CLOSE_TABS,      NULL,      GTK_STOCK_CLOSE            },
	{ PIDGIN_STOCK_DEBUG,           NULL,      GTK_STOCK_PROPERTIES       },
	{ PIDGIN_STOCK_DOWNLOAD,        NULL,      GTK_STOCK_GO_DOWN          },
#if GTK_CHECK_VERSION(2,6,0)
	{ PIDGIN_STOCK_DISCONNECT,      NULL,      GTK_STOCK_DISCONNECT       },
#else
	{ PIDGIN_STOCK_DISCONNECT,      "icons",   "stock_disconnect_16.png"  },
#endif
	{ PIDGIN_STOCK_FGCOLOR,         "buttons", "change-fgcolor-small.png" },
#if GTK_CHECK_VERSION(2,6,0)
	{ PIDGIN_STOCK_EDIT,            NULL,      GTK_STOCK_EDIT             },
#else
	{ PIDGIN_STOCK_EDIT,            "buttons", "edit.png"                 },
#endif
	{ PIDGIN_STOCK_FILE_CANCELED,   NULL,      GTK_STOCK_CANCEL           },
	{ PIDGIN_STOCK_FILE_DONE,       NULL,      GTK_STOCK_APPLY            },
	{ PIDGIN_STOCK_IGNORE,          NULL,      GTK_STOCK_DIALOG_ERROR     },
	{ PIDGIN_STOCK_INVITE,          NULL,      GTK_STOCK_JUMP_TO          },
	{ PIDGIN_STOCK_MODIFY,          NULL,      GTK_STOCK_PREFERENCES      },
#if GTK_CHECK_VERSION(2,6,0)
	{ PIDGIN_STOCK_PAUSE,           NULL,      GTK_STOCK_MEDIA_PAUSE      },
#else
	{ PIDGIN_STOCK_PAUSE,           "buttons", "pause.png"                },
#endif
	{ PIDGIN_STOCK_POUNCE,          NULL,      GTK_STOCK_REDO             },
	{ PIDGIN_STOCK_OPEN_MAIL,       NULL,      GTK_STOCK_JUMP_TO          },
	{ PIDGIN_STOCK_SIGN_ON,         NULL,      GTK_STOCK_EXECUTE          },
	{ PIDGIN_STOCK_SIGN_OFF,        NULL,      GTK_STOCK_CLOSE            },
	{ PIDGIN_STOCK_TYPED,           "pidgin",  "typed.png"                },
	{ PIDGIN_STOCK_UPLOAD,          NULL,      GTK_STOCK_GO_UP            },
#if GTK_CHECK_VERSION(2,8,0)
	{ PIDGIN_STOCK_INFO,            NULL,      GTK_STOCK_INFO             },
#else
	{ PIDGIN_STOCK_INFO,            "buttons", "info.png"                 },
#endif
};

static const GtkStockItem stock_items[] =
{
	{ PIDGIN_STOCK_ALIAS,               N_("_Alias"),      0, 0, NULL },
	{ PIDGIN_STOCK_CHAT,                N_("_Join"),       0, 0, NULL },
	{ PIDGIN_STOCK_CLOSE_TABS,          N_("Close _tabs"), 0, 0, NULL },
	{ PIDGIN_STOCK_TOOLBAR_MESSAGE_NEW, N_("I_M"),         0, 0, NULL },
	{ PIDGIN_STOCK_TOOLBAR_USER_INFO,   N_("_Get Info"),   0, 0, NULL },
	{ PIDGIN_STOCK_INVITE,              N_("_Invite"),     0, 0, NULL },
	{ PIDGIN_STOCK_MODIFY,              N_("_Modify"),     0, 0, NULL },
	{ PIDGIN_STOCK_OPEN_MAIL,           N_("_Open Mail"),  0, 0, NULL },
	{ PIDGIN_STOCK_PAUSE,               N_("_Pause"),      0, 0, NULL },
	{ PIDGIN_STOCK_EDIT,                N_("_Edit"),       0, 0, NULL }
};

static struct SizedStockIcon {
  const char *name;
  const char *dir;
  const char *filename;
  gboolean microscopic;
  gboolean extra_small;
  gboolean small;
  gboolean medium;
  gboolean large;
  gboolean huge;
  gboolean rtl;
  const char *translucent_name;
} const sized_stock_icons [] = {


        /* Status icons */

	{ PIDGIN_STOCK_STATUS_AVAILABLE, "status", "pidgin-available.png", 	TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, PIDGIN_STOCK_STATUS_AVAILABLE_I },
	{ PIDGIN_STOCK_STATUS_AWAY, 	 "status", "pidgin-away.png",		TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, PIDGIN_STOCK_STATUS_AWAY_I },
	{ PIDGIN_STOCK_STATUS_BUSY, 	 "status", "pidgin-busy.png", 		TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, PIDGIN_STOCK_STATUS_BUSY_I },
	{ PIDGIN_STOCK_STATUS_CHAT, 	 "status", "pidgin-chat.png",		TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL },
	{ PIDGIN_STOCK_STATUS_INVISIBLE, "status", "pidgin-invisible.png",	TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL },
	{ PIDGIN_STOCK_STATUS_XA, 	 "status", "pidgin-extended-away.png",	TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, PIDGIN_STOCK_STATUS_XA_I },
	{ PIDGIN_STOCK_STATUS_LOGIN, 	 "status", "pidgin-log-in.png",		TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL },
	{ PIDGIN_STOCK_STATUS_LOGOUT, 	 "status", "pidgin-log-out.png",	TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL },
	{ PIDGIN_STOCK_STATUS_OFFLINE, 	 "status", "pidgin-offline.png",	TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, PIDGIN_STOCK_STATUS_OFFLINE_I  },
	{ PIDGIN_STOCK_STATUS_PERSON, 	 "status", "pidgin-person.png",		TRUE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_STATUS_MESSAGE, 	 "actions", "pidgin-message-new.png",   TRUE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	

        /* Chatroom icons */

	{ PIDGIN_STOCK_STATUS_IGNORED,	 "status", "pidgin-blocked.png",	FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_STATUS_FOUNDER,	 "status", "pidgin-founder.png",	FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_STATUS_OPERATOR,	 "status", "pidgin-operator.png",	FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_STATUS_HALFOP, 	 "status", "pidgin-half-operator.png",	FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_STATUS_VOICE, 	 "status", "pidgin-voice.png",		FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },


        /* Dialog icons */

	{ PIDGIN_STOCK_DIALOG_AUTH,	"status", "pidgin-auth.png",		FALSE, TRUE, FALSE, FALSE, FALSE, TRUE, FALSE, NULL  },
	{ PIDGIN_STOCK_DIALOG_COOL,	"status", "pidgin-cool.png", 		FALSE, FALSE, FALSE, FALSE, FALSE, TRUE, FALSE, NULL  },
	{ PIDGIN_STOCK_DIALOG_ERROR,	"status", "pidgin-error.png",		FALSE, TRUE, FALSE, FALSE, FALSE, TRUE, FALSE, NULL  },
	{ PIDGIN_STOCK_DIALOG_INFO,	"status", "pidgin-info.png",		FALSE, TRUE, FALSE, FALSE, FALSE, TRUE, FALSE, NULL  },
	{ PIDGIN_STOCK_DIALOG_MAIL,	"status", "pidgin-mail.png",		FALSE, TRUE, FALSE, FALSE, FALSE, TRUE, FALSE, NULL  },
	{ PIDGIN_STOCK_DIALOG_QUESTION,	"status", "pidgin-question.png",	FALSE, TRUE, FALSE, FALSE, FALSE, TRUE, FALSE, NULL  },
	{ PIDGIN_STOCK_DIALOG_WARNING,	"status", "pidgin-warning.png",		FALSE, FALSE, FALSE, FALSE, FALSE, TRUE, FALSE, NULL  },


        /* Animations */

	{ PIDGIN_STOCK_ANIMATION_CONNECT0, "animations", "process-working0.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT1, "animations", "process-working1.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT2, "animations", "process-working2.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT3, "animations", "process-working3.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT4, "animations", "process-working4.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT5, "animations", "process-working5.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT6, "animations", "process-working6.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT7, "animations", "process-working7.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT8, "animations", "process-working8.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT9, "animations", "process-working9.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT10, "animations", "process-working10.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT11, "animations", "process-working11.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT12, "animations", "process-working12.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT13, "animations", "process-working13.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT14, "animations", "process-working14.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT15, "animations", "process-working15.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT16, "animations", "process-working16.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT17, "animations", "process-working17.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT18, "animations", "process-working18.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT19, "animations", "process-working19.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT20, "animations", "process-working20.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT21, "animations", "process-working21.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT22, "animations", "process-working22.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT23, "animations", "process-working23.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT24, "animations", "process-working24.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT25, "animations", "process-working25.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT26, "animations", "process-working26.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT27, "animations", "process-working27.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT28, "animations", "process-working28.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT29, "animations", "process-working29.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_CONNECT30, "animations", "process-working30.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_TYPING0,  "animations", "typing0.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_TYPING1,  "animations", "typing1.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_TYPING2,  "animations", "typing2.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_TYPING3,  "animations", "typing3.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_TYPING4,  "animations", "typing4.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_ANIMATION_TYPING5,  "animations", "typing5.png",FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },


        /* Conversation toolbar icons */

	{ PIDGIN_STOCK_TOOLBAR_BGCOLOR, "actions", "pidgin-change-bgcolor.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_FGCOLOR, "actions", "pidgin-change-fgcolor.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_TEXT_SMALLER, "actions", "pidgin-font-size-down.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_TEXT_LARGER, "actions", "pidgin-font-size-up.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_SMILEY, "actions", "pidgin-emote-select.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_FONT_FACE, "actions", "pidgin-font-face.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_INSERT, "actions", "pidgin-insert.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_INSERT_IMAGE, "actions", "pidgin-insert-image.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_INSERT_LINK, "actions", "pidgin-insert-link.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },


        /* Menu icons */

	{ PIDGIN_STOCK_TOOLBAR_BLOCK, "status", "pidgin-blocked.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_MESSAGE_NEW, "actions", "pidgin-message-new.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_PENDING, "status", "pidgin-tray-new-im.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_PLUGINS, "actions", "pidgin-view-plugins.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_UNBLOCK, "actions", "pidgin-unblock.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_SELECT_AVATAR, "actions", "pidgin-select-avatar.png", FALSE, FALSE, FALSE, TRUE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_SEND_FILE, "actions", "pidgin-send-file.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TOOLBAR_TRANSFER, "actions", "pidgin-view-transfer.png", FALSE, TRUE, FALSE, FALSE, FALSE, FALSE, FALSE, NULL  },


        /* Tray icons */

	{ PIDGIN_STOCK_TRAY_AVAILABLE, "status", "pidgin-tray-online.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TRAY_INVISIBLE, "status", "pidgin-tray-invisible.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TRAY_AWAY, "status", "pidgin-tray-away.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TRAY_BUSY, "status", "pidgin-tray-busy.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TRAY_XA, "status", "pidgin-tray-extended-away.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TRAY_OFFLINE, "status", "pidgin-tray-offline.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TRAY_CONNECT, "status", "pidgin-tray-connecting.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TRAY_PENDING, "status", "pidgin-tray-new-im.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  },
	{ PIDGIN_STOCK_TRAY_EMAIL, "status", "pidgin-tray-message.png", FALSE, TRUE, TRUE, TRUE, TRUE, FALSE, FALSE, NULL  }

};

static gchar *
find_file(const char *dir, const char *base)
{
	char *filename;

	if (base == NULL)
		return NULL;

	if (!strcmp(dir, "pidgin"))
		filename = g_build_filename(DATADIR, "pixmaps", "pidgin", base, NULL);
	else
	{
		filename = g_build_filename(DATADIR, "pixmaps", "pidgin", dir,
									base, NULL);
	}

	return filename;
}

static void
add_sized_icon(GtkIconSet *iconset, GtkIconSize sizeid, const char *dir, 
	       gboolean rtl, const char *size, const char *file)
{
	char *filename;
	GtkIconSource *source;	

	filename = g_build_filename(DATADIR, "pixmaps", "pidgin", dir, size, file, NULL);
	source = gtk_icon_source_new();
        gtk_icon_source_set_filename(source, filename);
	gtk_icon_source_set_direction(source, GTK_TEXT_DIR_LTR);
        gtk_icon_source_set_direction_wildcarded(source, !rtl);
	gtk_icon_source_set_size(source, sizeid);
        gtk_icon_source_set_size_wildcarded(source, FALSE);
        gtk_icon_source_set_state_wildcarded(source, TRUE);
        gtk_icon_set_add_source(iconset, source);
	gtk_icon_source_free(source);

	if (sizeid == gtk_icon_size_from_name(PIDGIN_ICON_SIZE_TANGO_EXTRA_SMALL)) {
		source = gtk_icon_source_new();
	        gtk_icon_source_set_filename(source, filename);
        	gtk_icon_source_set_direction_wildcarded(source, TRUE);
	        gtk_icon_source_set_size(source, GTK_ICON_SIZE_MENU);
	        gtk_icon_source_set_size_wildcarded(source, FALSE);
        	gtk_icon_source_set_state_wildcarded(source, TRUE);
	        gtk_icon_set_add_source(iconset, source);
	        gtk_icon_source_free(source);
	}
        g_free(filename);

       if (rtl) {
		filename = g_build_filename(DATADIR, "pixmaps", "pidgin", dir, size, "rtl", file, NULL);
                source = gtk_icon_source_new();
                gtk_icon_source_set_filename(source, filename);
                gtk_icon_source_set_direction(source, GTK_TEXT_DIR_RTL);
                gtk_icon_source_set_size(source, sizeid);
                gtk_icon_source_set_size_wildcarded(source, FALSE);
                gtk_icon_source_set_state_wildcarded(source, TRUE);
                gtk_icon_set_add_source(iconset, source);
		g_free(filename);
		gtk_icon_source_free(source);
        }


}

/* Altered from do_colorshift in gnome-panel */
static void
do_alphashift (GdkPixbuf *dest, GdkPixbuf *src)
{
        gint i, j;
        gint width, height, has_alpha, srcrowstride, destrowstride;
        guchar *target_pixels;
        guchar *original_pixels;
        guchar *pixsrc;
        guchar *pixdest;
        guchar a;

        has_alpha = gdk_pixbuf_get_has_alpha (src);
        if (!has_alpha)
          return;

        width = gdk_pixbuf_get_width (src);
        height = gdk_pixbuf_get_height (src);
        srcrowstride = gdk_pixbuf_get_rowstride (src);
        destrowstride = gdk_pixbuf_get_rowstride (dest);
        target_pixels = gdk_pixbuf_get_pixels (dest);
        original_pixels = gdk_pixbuf_get_pixels (src);

        for (i = 0; i < height; i++) {
                pixdest = target_pixels + i*destrowstride;
                pixsrc = original_pixels + i*srcrowstride;
                for (j = 0; j < width; j++) {
                        *(pixdest++) = *(pixsrc++);
                        *(pixdest++) = *(pixsrc++);
                        *(pixdest++) = *(pixsrc++);
                        a = *(pixsrc++);
                        *(pixdest++) = a / 2;
                }
        }
}

/* TODO: This is almost certainly not the best way to do this, but it's late, I'm tired,
 * we're a few hours from getting this thing out, and copy/paste is EASY.
 */
static void
add_translucent_sized_icon(GtkIconSet *iconset, GtkIconSize sizeid, const char *dir,
	       gboolean rtl, const char *size, const char *file)
{
	char *filename;
	GtkIconSource *source;	
	GdkPixbuf *pixbuf;

	filename = g_build_filename(DATADIR, "pixmaps", "pidgin", dir, size, file, NULL);
	pixbuf = gdk_pixbuf_new_from_file(filename, NULL);
	do_alphashift(pixbuf, pixbuf);

	source = gtk_icon_source_new();
        gtk_icon_source_set_pixbuf(source, pixbuf);
	gtk_icon_source_set_direction(source, GTK_TEXT_DIR_LTR);
        gtk_icon_source_set_direction_wildcarded(source, !rtl);
	gtk_icon_source_set_size(source, sizeid);
        gtk_icon_source_set_size_wildcarded(source, FALSE);
        gtk_icon_source_set_state_wildcarded(source, TRUE);
        gtk_icon_set_add_source(iconset, source);
	gtk_icon_source_free(source);

	if (sizeid == gtk_icon_size_from_name(PIDGIN_ICON_SIZE_TANGO_EXTRA_SMALL)) {
		source = gtk_icon_source_new();
	        gtk_icon_source_set_pixbuf(source, pixbuf);
        	gtk_icon_source_set_direction_wildcarded(source, TRUE);
	        gtk_icon_source_set_size(source, GTK_ICON_SIZE_MENU);
	        gtk_icon_source_set_size_wildcarded(source, FALSE);
        	gtk_icon_source_set_state_wildcarded(source, TRUE);
	        gtk_icon_set_add_source(iconset, source);
	        gtk_icon_source_free(source);
	}
        g_free(filename);
	g_object_unref(pixbuf);

       if (rtl) {
		filename = g_build_filename(DATADIR, "pixmaps", "pidgin", dir, size, "rtl", file, NULL);
 		pixbuf = gdk_pixbuf_new_from_file(filename, NULL);
		do_alphashift(pixbuf, pixbuf);
		source = gtk_icon_source_new();
                gtk_icon_source_set_pixbuf(source, pixbuf);
                gtk_icon_source_set_direction(source, GTK_TEXT_DIR_RTL);
                gtk_icon_source_set_size(source, sizeid);
                gtk_icon_source_set_size_wildcarded(source, FALSE);
                gtk_icon_source_set_state_wildcarded(source, TRUE);
                gtk_icon_set_add_source(iconset, source);
		g_free(filename);
		g_object_unref(pixbuf);
		gtk_icon_source_free(source);
        }


}


void
pidgin_stock_init(void)
{
	static gboolean stock_initted = FALSE;
	GtkIconFactory *icon_factory;
	size_t i;
	GtkWidget *win;
	GtkIconSize microscopic, extra_small, small, medium, large, huge;

	if (stock_initted)
		return;

	stock_initted = TRUE;

	/* Setup the icon factory. */
	icon_factory = gtk_icon_factory_new();

	gtk_icon_factory_add_default(icon_factory);

	/* Er, yeah, a hack, but it works. :) */
	win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_realize(win);

	for (i = 0; i < G_N_ELEMENTS(stock_icons); i++)
	{
		GtkIconSource *source;
		GtkIconSet *iconset;
		gchar *filename;

		if (stock_icons[i].dir == NULL)
		{
			/* GTK+ Stock icon */
			iconset = gtk_style_lookup_icon_set(gtk_widget_get_style(win),
					stock_icons[i].filename);
		}
		else
		{
			filename = find_file(stock_icons[i].dir, stock_icons[i].filename);

			if (filename == NULL)
				continue;

			source = gtk_icon_source_new();
			gtk_icon_source_set_filename(source, filename);
			gtk_icon_source_set_direction_wildcarded(source, TRUE);
			gtk_icon_source_set_size_wildcarded(source, TRUE);
			gtk_icon_source_set_state_wildcarded(source, TRUE);


			iconset = gtk_icon_set_new();
			gtk_icon_set_add_source(iconset, source);

			gtk_icon_source_free(source);
			g_free(filename);
		}

		gtk_icon_factory_add(icon_factory, stock_icons[i].name, iconset);

		gtk_icon_set_unref(iconset);
	}

	/* register custom icon sizes */

	microscopic =  gtk_icon_size_register(PIDGIN_ICON_SIZE_TANGO_MICROSCOPIC, 11, 11);
	extra_small =  gtk_icon_size_register(PIDGIN_ICON_SIZE_TANGO_EXTRA_SMALL, 16, 16);
	small =        gtk_icon_size_register(PIDGIN_ICON_SIZE_TANGO_SMALL, 22, 22);
	medium =       gtk_icon_size_register(PIDGIN_ICON_SIZE_TANGO_MEDIUM, 32, 32);
	large =        gtk_icon_size_register(PIDGIN_ICON_SIZE_TANGO_LARGE, 48, 48);
	huge =         gtk_icon_size_register(PIDGIN_ICON_SIZE_TANGO_HUGE, 64, 64);

	for (i = 0; i < G_N_ELEMENTS(sized_stock_icons); i++)
	{
		GtkIconSet *iconset;

		iconset = gtk_icon_set_new();

#define ADD_SIZED_ICON(name, size) do { \
		if (sized_stock_icons[i].name)  \
			add_sized_icon(iconset, name,  \
					sized_stock_icons[i].dir, sized_stock_icons[i].rtl, \
					size, sized_stock_icons[i].filename); \
		} while (0)
		ADD_SIZED_ICON(microscopic, "11");
		ADD_SIZED_ICON(extra_small, "16");
		ADD_SIZED_ICON(small, "22");
		ADD_SIZED_ICON(medium, "32");
		ADD_SIZED_ICON(large, "48");
		ADD_SIZED_ICON(huge, "64");
#undef ADD_SIZED_ICON

		gtk_icon_factory_add(icon_factory, sized_stock_icons[i].name, iconset);
		gtk_icon_set_unref(iconset);

		if (sized_stock_icons[i].translucent_name) {
			iconset = gtk_icon_set_new();

#define ADD_TRANS_ICON(name, size) do { \
			if (sized_stock_icons[i].name) \
				add_translucent_sized_icon(iconset, name, \
						sized_stock_icons[i].dir, sized_stock_icons[i].rtl, \
						size, sized_stock_icons[i].filename); \
			} while (0)
			ADD_TRANS_ICON(microscopic, "11");
			ADD_TRANS_ICON(extra_small, "16");
			ADD_TRANS_ICON(small, "22");
			ADD_TRANS_ICON(medium, "32");
			ADD_TRANS_ICON(large, "48");
			ADD_TRANS_ICON(huge, "64");
#undef ADD_TRANS_ICON

			gtk_icon_factory_add(icon_factory, sized_stock_icons[i].translucent_name, iconset);
			gtk_icon_set_unref(iconset);
		}
	}

	gtk_widget_destroy(win);
	g_object_unref(G_OBJECT(icon_factory));

	/* Register the stock items. */
	gtk_stock_add_static(stock_items, G_N_ELEMENTS(stock_items));
}
