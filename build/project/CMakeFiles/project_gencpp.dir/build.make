# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zommi/Desktop/robotics-project-2019/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zommi/Desktop/robotics-project-2019/build

# Utility rule file for project_gencpp.

# Include the progress variables for this target.
include project/CMakeFiles/project_gencpp.dir/progress.make

project_gencpp: project/CMakeFiles/project_gencpp.dir/build.make

.PHONY : project_gencpp

# Rule to build all files generated by this target.
project/CMakeFiles/project_gencpp.dir/build: project_gencpp

.PHONY : project/CMakeFiles/project_gencpp.dir/build

project/CMakeFiles/project_gencpp.dir/clean:
	cd /home/zommi/Desktop/robotics-project-2019/build/project && $(CMAKE_COMMAND) -P CMakeFiles/project_gencpp.dir/cmake_clean.cmake
.PHONY : project/CMakeFiles/project_gencpp.dir/clean

project/CMakeFiles/project_gencpp.dir/depend:
	cd /home/zommi/Desktop/robotics-project-2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zommi/Desktop/robotics-project-2019/src /home/zommi/Desktop/robotics-project-2019/src/project /home/zommi/Desktop/robotics-project-2019/build /home/zommi/Desktop/robotics-project-2019/build/project /home/zommi/Desktop/robotics-project-2019/build/project/CMakeFiles/project_gencpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project/CMakeFiles/project_gencpp.dir/depend
