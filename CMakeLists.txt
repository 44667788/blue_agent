cmake_minimum_required(VERSION 3.8)
project(bt_agent)

set(DBUS_INC /home/zeke/devTool/dbus-install/include/dbus-1.0)
set(BLUEZ_INC /home/zeke/devTool/bluez-install/include/bluetooth)
set(GDBUS_INC /home/zeke/devTool/dbus-glib-install/include/dbus-1.0/dbus)
set(GLIB_INC /home/zeke/devTool/glib_install/include/glib-2.0)
set(READLINE_INC /home/zeke/devTool/readlin-install/include)
include_directories(${DBUS_INC} ${BLUEZ_INC} ${GDBUS_INC} ${GLIB_INC} ${READLINE_INC})

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_COMPILER mipsel-linux-gcc)
set(LIBS_PATH /home/zeke/project/fiio_playerv6/out/product/halley2/system/usr/lib)
link_directories(${LIBS_PATH})


set(SOURCE_FILES main.c agent.h agent.c gdbus/gdbus.h gdbus/client.c gdbus/mainloop.c gdbus/object.c gdbus/polkit.c gdbus/watch.c
        display.c display.h gdbus/client.h)
add_executable(bt_agent ${SOURCE_FILES})
target_link_libraries(bt_agent dbus-1 glib-2.0 readline-7)