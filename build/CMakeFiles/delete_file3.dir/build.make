# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Development\Repos\sms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Development\Repos\sms\build

# Utility rule file for delete_file3.

# Include any custom commands dependencies for this target.
include CMakeFiles/delete_file3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/delete_file3.dir/progress.make

CMakeFiles/delete_file3:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\Development\Repos\sms\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Deleting file: cmake_install.cmake"
	"C:\Program Files\CMake\bin\cmake.exe" -E remove cmake_install.cmake

delete_file3: CMakeFiles/delete_file3
delete_file3: CMakeFiles/delete_file3.dir/build.make
.PHONY : delete_file3

# Rule to build all files generated by this target.
CMakeFiles/delete_file3.dir/build: delete_file3
.PHONY : CMakeFiles/delete_file3.dir/build

CMakeFiles/delete_file3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\delete_file3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/delete_file3.dir/clean

CMakeFiles/delete_file3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Development\Repos\sms D:\Development\Repos\sms D:\Development\Repos\sms\build D:\Development\Repos\sms\build D:\Development\Repos\sms\build\CMakeFiles\delete_file3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/delete_file3.dir/depend

