

#include <printf.h>
#include <malloc.h>
#include "gdbus/client.h"
#include "agent.h"

int get_system_dbus(DBusConnection **connection) {
    DBusError err;
    DBusConnection *conn;
    dbus_error_init(&err);
    conn = dbus_bus_get(DBUS_BUS_SYSTEM, &err);
    if (conn == NULL)return 0;
    *connection = conn;
    printf("Dbus Name %s \n", dbus_bus_get_unique_name(conn));
    return 1;
}

int main() {
    printf("Hello, World!\n");
    DBusConnection *connection;
    GDBusProxy *gdBusProxy = malloc(sizeof(struct GDBusProxy));
    if (get_system_dbus(&connection)) {
        agent_register(connection, gdBusProxy, "");
    }
}