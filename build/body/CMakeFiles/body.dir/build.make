# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/server/build

# Include any dependencies generated for this target.
include body/CMakeFiles/body.dir/depend.make

# Include the progress variables for this target.
include body/CMakeFiles/body.dir/progress.make

# Include the compile flags for this target's objects.
include body/CMakeFiles/body.dir/flags.make

body/CMakeFiles/body.dir/Logic.cpp.o: body/CMakeFiles/body.dir/flags.make
body/CMakeFiles/body.dir/Logic.cpp.o: ../body/Logic.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /opt/server/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object body/CMakeFiles/body.dir/Logic.cpp.o"
	cd /opt/server/build/body && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/body.dir/Logic.cpp.o -c /opt/server/body/Logic.cpp

body/CMakeFiles/body.dir/Logic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/body.dir/Logic.cpp.i"
	cd /opt/server/build/body && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /opt/server/body/Logic.cpp > CMakeFiles/body.dir/Logic.cpp.i

body/CMakeFiles/body.dir/Logic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/body.dir/Logic.cpp.s"
	cd /opt/server/build/body && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /opt/server/body/Logic.cpp -o CMakeFiles/body.dir/Logic.cpp.s

body/CMakeFiles/body.dir/Logic.cpp.o.requires:
.PHONY : body/CMakeFiles/body.dir/Logic.cpp.o.requires

body/CMakeFiles/body.dir/Logic.cpp.o.provides: body/CMakeFiles/body.dir/Logic.cpp.o.requires
	$(MAKE) -f body/CMakeFiles/body.dir/build.make body/CMakeFiles/body.dir/Logic.cpp.o.provides.build
.PHONY : body/CMakeFiles/body.dir/Logic.cpp.o.provides

body/CMakeFiles/body.dir/Logic.cpp.o.provides.build: body/CMakeFiles/body.dir/Logic.cpp.o

# Object files for target body
body_OBJECTS = \
"CMakeFiles/body.dir/Logic.cpp.o"

# External object files for target body
body_EXTERNAL_OBJECTS =

body/libbody.so: body/CMakeFiles/body.dir/Logic.cpp.o
body/libbody.so: body/CMakeFiles/body.dir/build.make
body/libbody.so: body/world/libworld.so
body/libbody.so: body/m_user/libm_user.so
body/libbody.so: body/m_shop/libm_shop.so
body/libbody.so: body/base/libbase.so
body/libbody.so: body/database/libdatabase.so
body/libbody.so: body/CMakeFiles/body.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libbody.so"
	cd /opt/server/build/body && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/body.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
body/CMakeFiles/body.dir/build: body/libbody.so
.PHONY : body/CMakeFiles/body.dir/build

body/CMakeFiles/body.dir/requires: body/CMakeFiles/body.dir/Logic.cpp.o.requires
.PHONY : body/CMakeFiles/body.dir/requires

body/CMakeFiles/body.dir/clean:
	cd /opt/server/build/body && $(CMAKE_COMMAND) -P CMakeFiles/body.dir/cmake_clean.cmake
.PHONY : body/CMakeFiles/body.dir/clean

body/CMakeFiles/body.dir/depend:
	cd /opt/server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/server /opt/server/body /opt/server/build /opt/server/build/body /opt/server/build/body/CMakeFiles/body.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : body/CMakeFiles/body.dir/depend

