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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\kuliah\Grafkom\FP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\kuliah\Grafkom\FP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FP.dir/flags.make

CMakeFiles/FP.dir/main.cpp.obj: CMakeFiles/FP.dir/flags.make
CMakeFiles/FP.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\kuliah\Grafkom\FP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FP.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FP.dir\main.cpp.obj -c D:\kuliah\Grafkom\FP\main.cpp

CMakeFiles/FP.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FP.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\kuliah\Grafkom\FP\main.cpp > CMakeFiles\FP.dir\main.cpp.i

CMakeFiles/FP.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FP.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\kuliah\Grafkom\FP\main.cpp -o CMakeFiles\FP.dir\main.cpp.s

CMakeFiles/FP.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/FP.dir/main.cpp.obj.requires

CMakeFiles/FP.dir/main.cpp.obj.provides: CMakeFiles/FP.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\FP.dir\build.make CMakeFiles/FP.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/FP.dir/main.cpp.obj.provides

CMakeFiles/FP.dir/main.cpp.obj.provides.build: CMakeFiles/FP.dir/main.cpp.obj


# Object files for target FP
FP_OBJECTS = \
"CMakeFiles/FP.dir/main.cpp.obj"

# External object files for target FP
FP_EXTERNAL_OBJECTS =

FP.exe: CMakeFiles/FP.dir/main.cpp.obj
FP.exe: CMakeFiles/FP.dir/build.make
FP.exe: CMakeFiles/FP.dir/linklibs.rsp
FP.exe: CMakeFiles/FP.dir/objects1.rsp
FP.exe: CMakeFiles/FP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\kuliah\Grafkom\FP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FP.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FP.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FP.dir/build: FP.exe

.PHONY : CMakeFiles/FP.dir/build

CMakeFiles/FP.dir/requires: CMakeFiles/FP.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/FP.dir/requires

CMakeFiles/FP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FP.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FP.dir/clean

CMakeFiles/FP.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\kuliah\Grafkom\FP D:\kuliah\Grafkom\FP D:\kuliah\Grafkom\FP\cmake-build-debug D:\kuliah\Grafkom\FP\cmake-build-debug D:\kuliah\Grafkom\FP\cmake-build-debug\CMakeFiles\FP.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FP.dir/depend

