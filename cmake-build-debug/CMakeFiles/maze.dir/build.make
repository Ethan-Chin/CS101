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
include CMakeFiles/maze.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/maze.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/maze.dir/flags.make

CMakeFiles/maze.dir/maze.c.o: CMakeFiles/maze.dir/flags.make
CMakeFiles/maze.dir/maze.c.o: ../maze.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/maze.dir/maze.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/maze.dir/maze.c.o   -c /Users/chenyc/Documents/Fall2020/CS101/Code/maze.c

CMakeFiles/maze.dir/maze.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/maze.dir/maze.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/chenyc/Documents/Fall2020/CS101/Code/maze.c > CMakeFiles/maze.dir/maze.c.i

CMakeFiles/maze.dir/maze.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/maze.dir/maze.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/chenyc/Documents/Fall2020/CS101/Code/maze.c -o CMakeFiles/maze.dir/maze.c.s

# Object files for target maze
maze_OBJECTS = \
"CMakeFiles/maze.dir/maze.c.o"

# External object files for target maze
maze_EXTERNAL_OBJECTS =

maze: CMakeFiles/maze.dir/maze.c.o
maze: CMakeFiles/maze.dir/build.make
maze: CMakeFiles/maze.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable maze"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/maze.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/maze.dir/build: maze

.PHONY : CMakeFiles/maze.dir/build

CMakeFiles/maze.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/maze.dir/cmake_clean.cmake
.PHONY : CMakeFiles/maze.dir/clean

CMakeFiles/maze.dir/depend:
	cd /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chenyc/Documents/Fall2020/CS101/Code /Users/chenyc/Documents/Fall2020/CS101/Code /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug /Users/chenyc/Documents/Fall2020/CS101/Code/cmake-build-debug/CMakeFiles/maze.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/maze.dir/depend

