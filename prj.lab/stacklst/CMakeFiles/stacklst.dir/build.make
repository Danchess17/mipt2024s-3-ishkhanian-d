# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/daniel/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/daniel/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d"

# Include any dependencies generated for this target.
include prj.lab/stacklst/CMakeFiles/stacklst.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include prj.lab/stacklst/CMakeFiles/stacklst.dir/compiler_depend.make

# Include the progress variables for this target.
include prj.lab/stacklst/CMakeFiles/stacklst.dir/progress.make

# Include the compile flags for this target's objects.
include prj.lab/stacklst/CMakeFiles/stacklst.dir/flags.make

prj.lab/stacklst/CMakeFiles/stacklst.dir/stacklst.cpp.o: prj.lab/stacklst/CMakeFiles/stacklst.dir/flags.make
prj.lab/stacklst/CMakeFiles/stacklst.dir/stacklst.cpp.o: prj.lab/stacklst/stacklst.cpp
prj.lab/stacklst/CMakeFiles/stacklst.dir/stacklst.cpp.o: prj.lab/stacklst/CMakeFiles/stacklst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj.lab/stacklst/CMakeFiles/stacklst.dir/stacklst.cpp.o"
	cd "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT prj.lab/stacklst/CMakeFiles/stacklst.dir/stacklst.cpp.o -MF CMakeFiles/stacklst.dir/stacklst.cpp.o.d -o CMakeFiles/stacklst.dir/stacklst.cpp.o -c "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst/stacklst.cpp"

prj.lab/stacklst/CMakeFiles/stacklst.dir/stacklst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stacklst.dir/stacklst.cpp.i"
	cd "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst/stacklst.cpp" > CMakeFiles/stacklst.dir/stacklst.cpp.i

prj.lab/stacklst/CMakeFiles/stacklst.dir/stacklst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stacklst.dir/stacklst.cpp.s"
	cd "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst/stacklst.cpp" -o CMakeFiles/stacklst.dir/stacklst.cpp.s

# Object files for target stacklst
stacklst_OBJECTS = \
"CMakeFiles/stacklst.dir/stacklst.cpp.o"

# External object files for target stacklst
stacklst_EXTERNAL_OBJECTS =

prj.lab/stacklst/libstacklst.a: prj.lab/stacklst/CMakeFiles/stacklst.dir/stacklst.cpp.o
prj.lab/stacklst/libstacklst.a: prj.lab/stacklst/CMakeFiles/stacklst.dir/build.make
prj.lab/stacklst/libstacklst.a: prj.lab/stacklst/CMakeFiles/stacklst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libstacklst.a"
	cd "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst" && $(CMAKE_COMMAND) -P CMakeFiles/stacklst.dir/cmake_clean_target.cmake
	cd "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stacklst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj.lab/stacklst/CMakeFiles/stacklst.dir/build: prj.lab/stacklst/libstacklst.a
.PHONY : prj.lab/stacklst/CMakeFiles/stacklst.dir/build

prj.lab/stacklst/CMakeFiles/stacklst.dir/clean:
	cd "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst" && $(CMAKE_COMMAND) -P CMakeFiles/stacklst.dir/cmake_clean.cmake
.PHONY : prj.lab/stacklst/CMakeFiles/stacklst.dir/clean

prj.lab/stacklst/CMakeFiles/stacklst.dir/depend:
	cd "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d" "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst" "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d" "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst" "/home/daniel/smart engines/mipt2024s-3-ishkhanian-d/prj.lab/stacklst/CMakeFiles/stacklst.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : prj.lab/stacklst/CMakeFiles/stacklst.dir/depend

