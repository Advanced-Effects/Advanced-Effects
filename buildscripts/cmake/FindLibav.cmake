#
# Copyright (C) 2015-2020 Mattia Basaglia
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Tries to find libav
#
# Input:
#   Libav_PREFIX
#   Libav_LIBRARIES
#   Libav_INCLUDE_DIRS
#
# Output:
#   Libav_FOUND
#   Libav_LIBRARIES
#   Libav_INCLUDE_DIRS
# For each component:
#   Libav_<component>_FOUND
#   Libav_<component>_INCLUDE_DIR
#   Libav_<component>_LIBRARY
#
# Components:
#   codec
#   filter
#   format
#   device
#   util
#   resample
#   swscale

set(Libav_PREFIX "${CMAKE_SYSTEM_PREFIX_PATH}" CACHE PATH "libav installation prefix")

if(Libav_LIBRARIES AND Libav_INCLUDE_DIRS)
    set(Libav_FOUND TRUE)
else()
    set(Libav_LIBRARIES)
    set(Libav_INCLUDE_DIRS)

    foreach(comp_short ${Libav_FIND_COMPONENTS})
        if(comp_short MATCHES "^sw.*" )
            set(component ${comp_short})
        else()
            set(component "av${comp_short}")
        endif()

        find_path(
            Libav_${comp_short}_INCLUDE_DIR
            NAMES
                "lib${component}/${component}.h"
            PATHS
                ${Libav_PREFIX}/include
                /usr/local/include
                /usr/include
                /usr/local/homebrew/opt/ffmpeg/include/
                /usr/include/ffmpeg
        )

        find_library(
            Libav_${comp_short}_LIBRARY
            NAMES
                ${component}
            PATHS
                ${Libav_PREFIX}/lib
                /usr/local/lib
                /usr/local/lib/x86_64-linux-gnu
                /usr/lib
                /usr/lib/x86_64-linux-gnu
                /usr/local/homebrew/opt/ffmpeg/lib/
                /usr/lib64
        )

        if(Libav_${comp_short}_INCLUDE_DIR AND Libav_${comp_short}_LIBRARY)
            set(Libav_${comp_short}_FOUND TRUE)
            list(APPEND Libav_LIBRARIES ${Libav_${comp_short}_LIBRARY})
            list(APPEND Libav_INCLUDE_DIRS ${Libav_${comp_short}_INCLUDE_DIR})
        else()
            set(Libav_${comp_short}_FOUND FALSE)
        endif()
    endforeach()

    list(REMOVE_DUPLICATES Libav_INCLUDE_DIRS)

    include(FindPackageHandleStandardArgs)
    find_package_handle_standard_args(
        Libav
        REQUIRED_VARS
            Libav_LIBRARIES
            Libav_INCLUDE_DIRS
        HANDLE_COMPONENTS
    )
endif()
