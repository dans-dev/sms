cmake_minimum_required(VERSION 3.10)
project(sms)

# Set the C++ standard to C++11 or higher
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2 -lSDL2_image -mwindows")

if (WIN32)
    # Add all the .cpp files in the src directory and its subdirectories
    file(GLOB_RECURSE SOURCES src/*.cpp)

    # Add your source files
    add_executable(sms WIN32 ${SOURCES})


    if(NOT PNG AND WIN32 AND NOT MSVC)
        set(PNG_LIBRARY "C:/Program Files(x86)/libpng")
        set(PNG_PNG_INCLUDE_DIR "C:/Program Files(x86)/libpng/include")
    endif()

    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)

    if(WIN32 AND NOT MSVC)
        target_link_libraries(sms PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image mingw32)
    else()
        target_link_libraries(sms PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
    endif()

    file(COPY levels DESTINATION ${CMAKE_BINARY_DIR}/compile/windows)
    file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/compile/windows)

    file(GLOB LIBRARIES libraries/*)
    foreach(LIBRARY ${LIBRARIES})
        file(COPY ${LIBRARY} DESTINATION ${CMAKE_BINARY_DIR}/compile/windows)
    endforeach()

    set(source_file "sms.exe")
    set(destination_path "compile/windows")
    add_custom_target(copy_file
        COMMAND ${CMAKE_COMMAND} -E copy ${source_file} ${destination_path}
        COMMENT "Copying file: ${source_file} to ${destination_path}"
    )
    add_custom_target(end ALL DEPENDS copy_file)

    set(file_to_delete "sms.exe")

    # Create a custom target to delete the file
    add_custom_target(delete_file
        COMMAND ${CMAKE_COMMAND} -E remove ${file_to_delete}
        COMMENT "Deleting file: ${file_to_delete}"
    )

    # Add the custom target to the end of the Makefile
    add_custom_target(cp_end ALL DEPENDS delete_file)
else()
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})

    # Add the SDL_image library
    find_package(SDL2_image REQUIRED)
    include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

    # Add all the .cpp files in the src directory and its subdirectories
    file(GLOB_RECURSE SOURCES src/*.cpp)

    # Add your source files
    add_executable(sms ${SOURCES})

    # Link against the SDL2 and SDL_image libraries
    target_link_libraries(sms ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

    # Copy the levels and assets folders to the compile directory
    file(COPY levels DESTINATION ${CMAKE_BINARY_DIR}/compile/linux)
    file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/compile/linux)

    set(source_file "sms")
    set(destination_path "compile/linux")
    add_custom_target(copy_file
        COMMAND ${CMAKE_COMMAND} -E copy ${source_file} ${destination_path}
        COMMENT "Copying file: ${source_file} to ${destination_path}"
    )
    add_custom_target(end ALL DEPENDS copy_file)

    set(file_to_delete "sms")

    # Create a custom target to delete the file
    add_custom_target(delete_file
        COMMAND ${CMAKE_COMMAND} -E remove ${file_to_delete}
        COMMENT "Deleting file: ${file_to_delete}"
    )

    # Add the custom target to the end of the Makefile
    add_custom_target(cp_end ALL DEPENDS delete_file)
endif()

set(file_to_delete "CMakeCache.txt")
# Create a custom target to delete the file
add_custom_target(delete_file2
    COMMAND ${CMAKE_COMMAND} -E remove ${file_to_delete}
    COMMENT "Deleting file: ${file_to_delete}"
)
# Add the custom target to the end of the Makefile
add_custom_target(cp_end2 ALL DEPENDS delete_file2)

set(file_to_delete "cmake_install.cmake")
# Create a custom target to delete the file
add_custom_target(delete_file3
    COMMAND ${CMAKE_COMMAND} -E remove ${file_to_delete}
    COMMENT "Deleting file: ${file_to_delete}"
)
# Add the custom target to the end of the Makefile
add_custom_target(cp_end3 ALL DEPENDS delete_file3)

set(file_to_delete "Makefile")
# Create a custom target to delete the file
add_custom_target(delete_file4
    COMMAND ${CMAKE_COMMAND} -E remove ${file_to_delete}
    COMMENT "Deleting file: ${file_to_delete}"
)
# Add the custom target to the end of the Makefile
add_custom_target(cp_end4 ALL DEPENDS delete_file4)
