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
include Network/CMakeFiles/NetworkLib.dir/depend.make

# Include the progress variables for this target.
include Network/CMakeFiles/NetworkLib.dir/progress.make

# Include the compile flags for this target's objects.
include Network/CMakeFiles/NetworkLib.dir/flags.make

Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj: Network/CMakeFiles/NetworkLib.dir/flags.make
Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj: ../Network/Bundle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Solo\Solo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj"
	cd /d E:\Solo\Solo\cmake-build-debug\Network && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NetworkLib.dir\Bundle.cpp.obj -c E:\Solo\Solo\Network\Bundle.cpp

Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkLib.dir/Bundle.cpp.i"
	cd /d E:\Solo\Solo\cmake-build-debug\Network && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Solo\Solo\Network\Bundle.cpp > CMakeFiles\NetworkLib.dir\Bundle.cpp.i

Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkLib.dir/Bundle.cpp.s"
	cd /d E:\Solo\Solo\cmake-build-debug\Network && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Solo\Solo\Network\Bundle.cpp -o CMakeFiles\NetworkLib.dir\Bundle.cpp.s

Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj.requires:

.PHONY : Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj.requires

Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj.provides: Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj.requires
	$(MAKE) -f Network\CMakeFiles\NetworkLib.dir\build.make Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj.provides.build
.PHONY : Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj.provides

Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj.provides.build: Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj


# Object files for target NetworkLib
NetworkLib_OBJECTS = \
"CMakeFiles/NetworkLib.dir/Bundle.cpp.obj"

# External object files for target NetworkLib
NetworkLib_EXTERNAL_OBJECTS =

Network/libNetworkLib.a: Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj
Network/libNetworkLib.a: Network/CMakeFiles/NetworkLib.dir/build.make
Network/libNetworkLib.a: Network/CMakeFiles/NetworkLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Solo\Solo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libNetworkLib.a"
	cd /d E:\Solo\Solo\cmake-build-debug\Network && $(CMAKE_COMMAND) -P CMakeFiles\NetworkLib.dir\cmake_clean_target.cmake
	cd /d E:\Solo\Solo\cmake-build-debug\Network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NetworkLib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Network/CMakeFiles/NetworkLib.dir/build: Network/libNetworkLib.a

.PHONY : Network/CMakeFiles/NetworkLib.dir/build

Network/CMakeFiles/NetworkLib.dir/requires: Network/CMakeFiles/NetworkLib.dir/Bundle.cpp.obj.requires

.PHONY : Network/CMakeFiles/NetworkLib.dir/requires

Network/CMakeFiles/NetworkLib.dir/clean:
	cd /d E:\Solo\Solo\cmake-build-debug\Network && $(CMAKE_COMMAND) -P CMakeFiles\NetworkLib.dir\cmake_clean.cmake
.PHONY : Network/CMakeFiles/NetworkLib.dir/clean

Network/CMakeFiles/NetworkLib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Solo\Solo E:\Solo\Solo\Network E:\Solo\Solo\cmake-build-debug E:\Solo\Solo\cmake-build-debug\Network E:\Solo\Solo\cmake-build-debug\Network\CMakeFiles\NetworkLib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Network/CMakeFiles/NetworkLib.dir/depend
