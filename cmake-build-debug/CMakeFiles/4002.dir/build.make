# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chenyc/Documents/Fall2020/CS101/Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4002.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4002.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4002.dir/flags.make

CMakeFiles/4002.dir/4002.cpp.o: CMakeFiles/4002.dir/flags.make
CMakeFiles/4002.dir/4002.cpp.o: ../4002.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/4002.dir/4002.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/4002.dir/4002.cpp.o -c /Users/chenyc/Documents/Fall2020/CS101/Code/4002.cpp

CMakeFiles/4002.dir/4002.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/4002.dir/4002.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chenyc/Documents/Fall2020/CS101/Code/4002.cpp > CMakeFiles/4002.dir/4002.cpp.i

CMakeFiles/4002.dir/4002.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/4002.dir/4002.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chenyc/Documents/Fall2020/CS101/Code/4002.cpp -o CMakeFiles/4002.dir/4002.cpp.s

# Object files for target 4002
4002_OBJECTS = \
"CMakeFiles/4002.dir/4002.cpp.o"

# External object files for target 4002
4002_EXTERNAL_OBJECTS =

4002: CMakeFiles/4002.dir/4002.cpp.o
4002: CMakeFiles/4002.dir/build.make
4002: CMakeFiles/4002.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 4002"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/4002.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4002.dir/build: 4002

.PHONY : CMakeFiles/4002.dir/build

CMakeFiles/4002.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/4002.dir/cmake_clean.cmake
.PHONY : CMakeFiles/4002.dir/clean

CMakeFiles/4002.dir/depend:
	cd /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chenyc/Documents/Fall2020/CS101/Code /Users/chenyc/Documents/Fall2020/CS101/Code /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug/CMakeFiles/4002.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4002.dir/depend

