# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/sr-tream/Projects/workspace/ProjectWizard/GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build

# Include any dependencies generated for this target.
include CMakeFiles/gui.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gui.dir/flags.make

ui_gui.h: ../src/gui.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ui_gui.h"
	/usr/bin/uic -o /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/ui_gui.h /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/gui.ui

CMakeFiles/gui.dir/src/main.cpp.o: CMakeFiles/gui.dir/flags.make
CMakeFiles/gui.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gui.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/src/main.cpp.o -c /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/main.cpp

CMakeFiles/gui.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/main.cpp > CMakeFiles/gui.dir/src/main.cpp.i

CMakeFiles/gui.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/main.cpp -o CMakeFiles/gui.dir/src/main.cpp.s

CMakeFiles/gui.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/gui.dir/src/main.cpp.o.requires

CMakeFiles/gui.dir/src/main.cpp.o.provides: CMakeFiles/gui.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/gui.dir/src/main.cpp.o.provides

CMakeFiles/gui.dir/src/main.cpp.o.provides.build: CMakeFiles/gui.dir/src/main.cpp.o


CMakeFiles/gui.dir/src/gui.cpp.o: CMakeFiles/gui.dir/flags.make
CMakeFiles/gui.dir/src/gui.cpp.o: ../src/gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gui.dir/src/gui.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/src/gui.cpp.o -c /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/gui.cpp

CMakeFiles/gui.dir/src/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/src/gui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/gui.cpp > CMakeFiles/gui.dir/src/gui.cpp.i

CMakeFiles/gui.dir/src/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/src/gui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sr-tream/Projects/workspace/ProjectWizard/GUI/src/gui.cpp -o CMakeFiles/gui.dir/src/gui.cpp.s

CMakeFiles/gui.dir/src/gui.cpp.o.requires:

.PHONY : CMakeFiles/gui.dir/src/gui.cpp.o.requires

CMakeFiles/gui.dir/src/gui.cpp.o.provides: CMakeFiles/gui.dir/src/gui.cpp.o.requires
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/src/gui.cpp.o.provides.build
.PHONY : CMakeFiles/gui.dir/src/gui.cpp.o.provides

CMakeFiles/gui.dir/src/gui.cpp.o.provides.build: CMakeFiles/gui.dir/src/gui.cpp.o


CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o: CMakeFiles/gui.dir/flags.make
CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o: gui_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o -c /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/gui_autogen/mocs_compilation.cpp

CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/gui_autogen/mocs_compilation.cpp > CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.i

CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/gui_autogen/mocs_compilation.cpp -o CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.s

CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o.requires:

.PHONY : CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o.requires

CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o.provides: CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f CMakeFiles/gui.dir/build.make CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o.provides

CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o.provides.build: CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o


# Object files for target gui
gui_OBJECTS = \
"CMakeFiles/gui.dir/src/main.cpp.o" \
"CMakeFiles/gui.dir/src/gui.cpp.o" \
"CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o"

# External object files for target gui
gui_EXTERNAL_OBJECTS =

gui: CMakeFiles/gui.dir/src/main.cpp.o
gui: CMakeFiles/gui.dir/src/gui.cpp.o
gui: CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o
gui: CMakeFiles/gui.dir/build.make
gui: /usr/lib/libQt5Widgets.so.5.9.2
gui: /usr/lib/libQt5Gui.so.5.9.2
gui: /usr/lib/libQt5Core.so.5.9.2
gui: CMakeFiles/gui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable gui"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gui.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gui.dir/build: gui

.PHONY : CMakeFiles/gui.dir/build

CMakeFiles/gui.dir/requires: CMakeFiles/gui.dir/src/main.cpp.o.requires
CMakeFiles/gui.dir/requires: CMakeFiles/gui.dir/src/gui.cpp.o.requires
CMakeFiles/gui.dir/requires: CMakeFiles/gui.dir/gui_autogen/mocs_compilation.cpp.o.requires

.PHONY : CMakeFiles/gui.dir/requires

CMakeFiles/gui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gui.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gui.dir/clean

CMakeFiles/gui.dir/depend: ui_gui.h
	cd /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sr-tream/Projects/workspace/ProjectWizard/GUI /home/sr-tream/Projects/workspace/ProjectWizard/GUI /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build /home/sr-tream/Projects/workspace/ProjectWizard/GUI/build/CMakeFiles/gui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gui.dir/depend
