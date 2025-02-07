/*
 * Copyright (c) 2007 The Xfce Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#ifndef _ETKACTION_H_
#define _ETKACTION_H_

#include <gtk/gtk.h>

typedef enum
{
    ETK_MENU_ITEM,
    ETK_MENU_ITEM_IMAGE,
    ETK_MENU_ITEM_CHECK,
    ETK_MENU_ITEM_RADIO,

} EtkMenuItem;

/**
 * Replacement for the deprecated #GtkActionEntry.
 * The idea is to provide a fixed list of #XfceGtkActionEntrys:
 * - use etk_translate_action_entries() once to translate the list
 * - use etk_accel_map_add_entries() once to register the provided accelerators
 * - use etk_get_action_entry_by_id() to find a single entry, e.g. by using
 *   a enumeration
 * - use etk_*_new_from_action_entry() to create the specific menu-
 *   or tool-items from the entry
 **/

typedef struct _EtkActionEntry EtkActionEntry;

struct _EtkActionEntry
{
    guint       id;

    const gchar *accel_path;
    const gchar *default_accelerator;

    // menu_item data is optional, only relevant if there exists a menu_item
    // for that accelerator
    EtkMenuItem item_type;
    gchar       *label_text;
    gchar       *tooltip_text;
    const gchar *icon_name;

    GCallback   callback;
};

GtkAccelGroup* etk_actions_init(GtkWindow *window, EtkActionEntry *actions);
void etk_actions_map_accels(const EtkActionEntry *action_entries);
void etk_actions_connect_accels(const EtkActionEntry *action_entries,
                                GtkAccelGroup        *accel_group,
                                gpointer             callback_data);
void etk_actions_translate(EtkActionEntry *action_entries);

void etk_actions_dispose(GtkWindow *window, GtkAccelGroup *accel_group);
void etk_actions_disconnect_accels(const EtkActionEntry *action_entries,
                                   GtkAccelGroup        *accel_group);

const EtkActionEntry* etk_actions_get_entry(const EtkActionEntry *action_entries,
                                            guint                id);
void etk_menu_item_set_accel_label(GtkMenuItem *menu_item, const gchar *accel_path);

GtkWidget* etk_menu_item_new(GtkMenuShell *menu,
                             const gchar  *label_text,
                             const gchar  *tooltip_text,
                             const gchar  *accel_path,
                             GCallback    callback,
                             GObject      *callback_param);

GtkWidget* etk_image_menu_item_new(GtkMenuShell *menu,
                                   const gchar  *label_text,
                                   const gchar  *tooltip_text,
                                   GtkWidget    *image,
                                   const gchar  *accel_path,
                                   GCallback    callback,
                                   GObject      *callback_param);

GtkWidget* etk_image_menu_item_new_from_icon_name(GtkMenuShell *menu,
                                                  const gchar  *label_text,
                                                  const gchar  *tooltip_text,
                                                  const gchar  *icon_name,
                                                  const gchar  *accel_path,
                                                  GCallback    callback,
                                                  GObject      *callback_param);

GtkWidget* etk_check_menu_item_new(GtkMenuShell *menu,
                                   const gchar  *label_text,
                                   const gchar  *tooltip_text,
                                   gboolean     active,
                                   const gchar  *accel_path,
                                   GCallback    callback,
                                   GObject      *callback_param);

GtkWidget* etk_radio_menu_item_new(GtkMenuShell *menu,
                                   const gchar  *label_text,
                                   const gchar  *tooltip_text,
                                   gboolean     active,
                                   const gchar  *accel_path,
                                   GCallback    callback,
                                   GObject      *callback_param);

GtkWidget* etk_menu_item_new_from_action(GtkMenuShell         *menu,
                                         int                  id,
                                         const EtkActionEntry *action_entries,
                                         GObject              *callback_param);

GtkWidget* etk_toggle_menu_item_new_from_action(GtkMenuShell         *menu,
                                                int                  id,
                                                const EtkActionEntry *action_entries,
                                                gboolean             active,
                                                GObject              *callback_param);

void etk_menu_append_separator(GtkMenuShell *menu);


GtkWidget* etk_tool_button_new_from_action(GtkToolbar           *toolbar,
                                           int                  id,
                                           const EtkActionEntry *action_entries,
                                           GObject              *callback_param);

GtkWidget* etk_toggle_tool_button_new_from_action(GtkToolbar           *toolbar,
                                                  int                  id,
                                                  const EtkActionEntry *action_entries,
                                                  gboolean             active,
                                                  GObject              *callback_param);

#endif // _ETKACTION_H_


