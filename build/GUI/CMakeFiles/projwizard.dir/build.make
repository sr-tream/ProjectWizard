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
CMAKE_SOURCE_DIR = /home/sr-tream/Projects/workspace/ProjectWizard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sr-tream/Projects/workspace/ProjectWizard/build

# Include any dependencies generated for this target.
include GUI/CMakeFiles/projwizard.dir/depend.make

# Include the progress variables for this target.
include GUI/CMakeFiles/projwizard.dir/progress.make

# Include the compile flags for this target's objects.
include GUI/CMakeFiles/projwizard.dir/flags.make

GUI/ui_gui.h: ../GUI/src/gui.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_gui.h"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/uic -o /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI/ui_gui.h /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/gui.ui

GUI/CMakeFiles/projwizard.dir/src/main.cpp.o: GUI/CMakeFiles/projwizard.dir/flags.make
GUI/CMakeFiles/projwizard.dir/src/main.cpp.o: ../GUI/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object GUI/CMakeFiles/projwizard.dir/src/main.cpp.o"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projwizard.dir/src/main.cpp.o -c /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/main.cpp

GUI/CMakeFiles/projwizard.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projwizard.dir/src/main.cpp.i"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/main.cpp > CMakeFiles/projwizard.dir/src/main.cpp.i

GUI/CMakeFiles/projwizard.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projwizard.dir/src/main.cpp.s"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/main.cpp -o CMakeFiles/projwizard.dir/src/main.cpp.s

GUI/CMakeFiles/projwizard.dir/src/main.cpp.o.requires:

.PHONY : GUI/CMakeFiles/projwizard.dir/src/main.cpp.o.requires

GUI/CMakeFiles/projwizard.dir/src/main.cpp.o.provides: GUI/CMakeFiles/projwizard.dir/src/main.cpp.o.requires
	$(MAKE) -f GUI/CMakeFiles/projwizard.dir/build.make GUI/CMakeFiles/projwizard.dir/src/main.cpp.o.provides.build
.PHONY : GUI/CMakeFiles/projwizard.dir/src/main.cpp.o.provides

GUI/CMakeFiles/projwizard.dir/src/main.cpp.o.provides.build: GUI/CMakeFiles/projwizard.dir/src/main.cpp.o


GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o: GUI/CMakeFiles/projwizard.dir/flags.make
GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o: ../GUI/src/gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projwizard.dir/src/gui.cpp.o -c /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/gui.cpp

GUI/CMakeFiles/projwizard.dir/src/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projwizard.dir/src/gui.cpp.i"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/gui.cpp > CMakeFiles/projwizard.dir/src/gui.cpp.i

GUI/CMakeFiles/projwizard.dir/src/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projwizard.dir/src/gui.cpp.s"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/gui.cpp -o CMakeFiles/projwizard.dir/src/gui.cpp.s

GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o.requires:

.PHONY : GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o.requires

GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o.provides: GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o.requires
	$(MAKE) -f GUI/CMakeFiles/projwizard.dir/build.make GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o.provides.build
.PHONY : GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o.provides

GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o.provides.build: GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o


GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o: GUI/CMakeFiles/projwizard.dir/flags.make
GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o: GUI/projwizard_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o -c /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI/projwizard_autogen/mocs_compilation.cpp

GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.i"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI/projwizard_autogen/mocs_compilation.cpp > CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.i

GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.s"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI/projwizard_autogen/mocs_compilation.cpp -o CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.s

GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o.requires:

.PHONY : GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o.requires

GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o.provides: GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f GUI/CMakeFiles/projwizard.dir/build.make GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o.provides

GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o.provides.build: GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o


# Object files for target projwizard
projwizard_OBJECTS = \
"CMakeFiles/projwizard.dir/src/main.cpp.o" \
"CMakeFiles/projwizard.dir/src/gui.cpp.o" \
"CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o"

# External object files for target projwizard
projwizard_EXTERNAL_OBJECTS =

GUI/projwizard: GUI/CMakeFiles/projwizard.dir/src/main.cpp.o
GUI/projwizard: GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o
GUI/projwizard: GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o
GUI/projwizard: GUI/CMakeFiles/projwizard.dir/build.make
GUI/projwizard: /usr/lib/libQt5Widgets.so.5.10.0
GUI/projwizard: libProjectWizard.so
GUI/projwizard: /usr/lib/libboost_filesystem.a
GUI/projwizard: /usr/lib/libboost_system.a
GUI/projwizard: /usr/lib/libQt5Gui.so.5.10.0
GUI/projwizard: /usr/lib/libQt5Core.so.5.10.0
GUI/projwizard: GUI/CMakeFiles/projwizard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable projwizard"
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projwizard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
GUI/CMakeFiles/projwizard.dir/build: GUI/projwizard

.PHONY : GUI/CMakeFiles/projwizard.dir/build

GUI/CMakeFiles/projwizard.dir/requires: GUI/CMakeFiles/projwizard.dir/src/main.cpp.o.requires
GUI/CMakeFiles/projwizard.dir/requires: GUI/CMakeFiles/projwizard.dir/src/gui.cpp.o.requires
GUI/CMakeFiles/projwizard.dir/requires: GUI/CMakeFiles/projwizard.dir/projwizard_autogen/mocs_compilation.cpp.o.requires

.PHONY : GUI/CMakeFiles/projwizard.dir/requires

GUI/CMakeFiles/projwizard.dir/clean:
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI && $(CMAKE_COMMAND) -P CMakeFiles/projwizard.dir/cmake_clean.cmake
.PHONY : GUI/CMakeFiles/projwizard.dir/clean

GUI/CMakeFiles/projwizard.dir/depend: GUI/ui_gui.h
	cd /home/sr-tream/Projects/workspace/ProjectWizard/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sr-tream/Projects/workspace/ProjectWizard /home/sr-tream/Projects/workspace/ProjectWizard/GUI /home/sr-tream/Projects/workspace/ProjectWizard/build /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI /home/sr-tream/Projects/workspace/ProjectWizard/build/GUI/CMakeFiles/projwizard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : GUI/CMakeFiles/projwizard.dir/depend
