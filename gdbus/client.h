//
// Created by zeke on 17-7-27.
//

#ifndef BT_AGENT_CLIENT_H
#define BT_AGENT_CLIENT_H

#include <stdio.h>
#include <glib.h>
#include <dbus/dbus.h>
#include "gdbus.h"

struct GDBusClient {
    int ref_count;
    DBusConnection *dbus_conn;
    char *service_name;
    char *base_path;
    char *root_path;
    guint watch;
    guint added_watch;
    guint removed_watch;
    GPtrArray *match_rules;
    DBusPendingCall *pending_call;
    DBusPendingCall *get_objects_call;
    GDBusWatchFunction connect_func;
    void *connect_data;
    GDBusWatchFunction disconn_func;
    gboolean connected;
    void *disconn_data;
    GDBusMessageFunction signal_func;
    void *signal_data;
    GDBusProxyFunction proxy_added;
    GDBusProxyFunction proxy_removed;
    GDBusClientFunction ready;
    void *ready_data;
    GDBusPropertyFunction property_changed;
    void *user_data;
    GList *proxy_list;
};

struct GDBusProxy {
    int ref_count;
    GDBusClient *client;
    char *obj_path;
    char *interface;
    GHashTable *prop_list;
    guint watch;
    GDBusPropertyFunction prop_func;
    void *prop_data;
    GDBusProxyFunction removed_func;
    void *removed_data;
};
#endif //BT_AGENT_CLIENT_H
