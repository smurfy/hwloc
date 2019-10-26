cmake_minimum_required(VERSION 2.8)
project(hwloc C)

include_directories(include)
include_directories(hwloc)

add_definitions(/D_CRT_SECURE_NO_WARNINGS)
if (MSVC)
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MT")
endif ()

set(HEADERS
        include/hwloc.h
        hwloc/static-components.h
        )

set(SOURCES
        hwloc/base64.c
        hwloc/bind.c
        hwloc/bitmap.c
        hwloc/components.c
        hwloc/diff.c
        hwloc/distances.c
        hwloc/misc.c
        hwloc/pci-common.c
        hwloc/shmem.c
        hwloc/topology.c
        hwloc/topology-noos.c
        hwloc/topology-synthetic.c
        hwloc/topology-x86.c
        hwloc/topology-xml.c
        hwloc/topology-xml-nolibxml.c
        hwloc/traversal.c
        )

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    set(SOURCES
            ${SOURCES}
            hwloc/topology-windows.c
            )
endif ()

if ("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
    set(SOURCES
            ${SOURCES}
            hwloc/topology-linux.c
            )
endif ()

add_library(hwloc STATIC
        ${HEADERS}
        ${SOURCES}
        )

install(TARGETS hwloc DESTINATION lib)
install(DIRECTORY include DESTINATION .)