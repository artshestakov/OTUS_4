cmake_minimum_required(VERSION 3.12)

project(homework_4)

set (CMAKE_CXX_STANDARD 17)

add_executable(homework_4
    main.cpp
	printer.cpp
)

target_include_directories(homework_4
    PRIVATE "${CMAKE_BINARY_DIR}"
)

install(TARGETS homework_4 RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_FILE_NAME "homework_4")
set(CPACK_PACKAGE_CONTACT art.shestakov@icloud.com)
include(CPack)
