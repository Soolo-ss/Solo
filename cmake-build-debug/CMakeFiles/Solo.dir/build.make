# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Solo\Solo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Solo\Solo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Solo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Solo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Solo.dir/flags.make

CMakeFiles/Solo.dir/main.cpp.obj: CMakeFiles/Solo.dir/flags.make
CMakeFiles/Solo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Solo\Solo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Solo.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Solo.dir\main.cpp.obj -c E:\Solo\Solo\main.cpp

CMakeFiles/Solo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Solo.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Solo\Solo\main.cpp > CMakeFiles\Solo.dir\main.cpp.i

CMakeFiles/Solo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Solo.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Solo\Solo\main.cpp -o CMakeFiles\Solo.dir\main.cpp.s

CMakeFiles/Solo.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Solo.dir/main.cpp.obj.requires

CMakeFiles/Solo.dir/main.cpp.obj.provides: CMakeFiles/Solo.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Solo.dir\build.make CMakeFiles/Solo.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Solo.dir/main.cpp.obj.provides

CMakeFiles/Solo.dir/main.cpp.obj.provides.build: CMakeFiles/Solo.dir/main.cpp.obj


# Object files for target Solo
Solo_OBJECTS = \
"CMakeFiles/Solo.dir/main.cpp.obj"

# External object files for target Solo
Solo_EXTERNAL_OBJECTS =

Solo.exe: CMakeFiles/Solo.dir/main.cpp.obj
Solo.exe: CMakeFiles/Solo.dir/build.make
Solo.exe: Components/Network/libNetworkLib.a
Solo.exe: CMakeFiles/Solo.dir/linklibs.rsp
Solo.exe: CMakeFiles/Solo.dir/objects1.rsp
Solo.exe: CMakeFiles/Solo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Solo\Solo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Solo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Solo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Solo.dir/build: Solo.exe

.PHONY : CMakeFiles/Solo.dir/build

CMakeFiles/Solo.dir/requires: CMakeFiles/Solo.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Solo.dir/requires

CMakeFiles/Solo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Solo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Solo.dir/clean

CMakeFiles/Solo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Solo\Solo E:\Solo\Solo E:\Solo\Solo\cmake-build-debug E:\Solo\Solo\cmake-build-debug E:\Solo\Solo\cmake-build-debug\CMakeFiles\Solo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Solo.dir/depend

