cmake_minimum_required(VERSION 3.2)
project(gsample)

set (Platform windows) # example
set (Arch x64) # example
set (GtkBinariesDir deps/gtk-binaries/${Platform}/${Arch})

# Include all these dirs at project scope (for any target)
include_directories ( src
                      ${GtkBinariesDir}/debug/include/wing-1.0
                      ${GtkBinariesDir}/debug/include/json-glib-1.0
                      ${GtkBinariesDir}/debug/include/cairo
                      ${GtkBinariesDir}/debug/include/libsoup-2.4
                      ${GtkBinariesDir}/debug/include/glib-2.0
                      ${GtkBinariesDir}/debug/include/gio-win32-2.0
                      ${GtkBinariesDir}/debug/include/gtk-3.0
                      ${GtkBinariesDir}/debug/include/pango-1.0
                      ${GtkBinariesDir}/debug/include/gdk-pixbuf-2.0
                      ${GtkBinariesDir}/debug/include/atk-1.0
                      ${GtkBinariesDir}/debug/include
                      ${GtkBinariesDir}/debug/lib/glib-2.0/include )

link_directories ( ${GtkBinariesDir} )

# Sources
set(SOURCES main.c
			src/gsamplederived.h
		    src/gsamplederived.c
		    src/gsamplebase.h
		    src/gsamplebase.c)

# Libraries
set (LIBRARIES_RELEASE   optimized release/lib/gdk_pixbuf-2.0
                         optimized release/lib/pango-1.0
                         optimized release/lib/gdk-3.0
                         optimized release/lib/gtk-3.0
                         optimized release/lib/glib-2.0
                         optimized release/lib/gio-2.0
                         optimized release/lib/gmodule-2.0
                         optimized release/lib/gobject-2.0
                         optimized release/lib/gthread-2.0)

set (LIBRARIES_DEBUG   debug debug/lib/gdk_pixbuf-2.0
                       debug debug/lib/pango-1.0
                       debug debug/lib/gdk-3.0
                       debug debug/lib/gtk-3.0
                       debug debug/lib/glib-2.0
                       debug debug/lib/gio-2.0
                       debug debug/lib/gmodule-2.0
                       debug debug/lib/gobject-2.0
                       debug debug/lib/gthread-2.0)

add_executable(gsample ${SOURCES})
target_link_libraries(gsample ${LIBRARIES_DEBUG} ${LIBRARIES_RELEASE})

# on windows, to copy, we need to replace the pesky forward slashes with back slashes
set(GTK_BIN_DIR ${GtkBinariesDir}/release/bin )
string(REGEX REPLACE "/" "\\\\" copySource \"${CMAKE_SOURCE_DIR}/${GTK_BIN_DIR}/*.dll\")
string(REGEX REPLACE "/" "\\\\" copyDest \"${CMAKE_CURRENT_BINARY_DIR}/$<CONFIGURATION>\")

# Copy
add_custom_command(TARGET gsample
    POST_BUILD
    COMMAND COMMAND copy ${copySource} ${copyDest}
    COMMENT "Copying GTK dlls...\n"
)
