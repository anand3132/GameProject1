# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/anand3132/2LocalRepository/GameProject1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator

# Include any dependencies generated for this target.
include cocos2d/cocos/CMakeFiles/cocos2d.dir/depend.make

# Include the progress variables for this target.
include cocos2d/cocos/CMakeFiles/cocos2d.dir/progress.make

# Include the compile flags for this target's objects.
include cocos2d/cocos/CMakeFiles/cocos2d.dir/flags.make

cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o: cocos2d/cocos/CMakeFiles/cocos2d.dir/flags.make
cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o: ../cocos2d/cocos/cc_dummy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o"
	cd /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/cocos2d/cocos && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cocos2d.dir/cc_dummy.c.o   -c /home/anand3132/2LocalRepository/GameProject1/cocos2d/cocos/cc_dummy.c

cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cocos2d.dir/cc_dummy.c.i"
	cd /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/cocos2d/cocos && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anand3132/2LocalRepository/GameProject1/cocos2d/cocos/cc_dummy.c > CMakeFiles/cocos2d.dir/cc_dummy.c.i

cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cocos2d.dir/cc_dummy.c.s"
	cd /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/cocos2d/cocos && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anand3132/2LocalRepository/GameProject1/cocos2d/cocos/cc_dummy.c -o CMakeFiles/cocos2d.dir/cc_dummy.c.s

cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o.requires:

.PHONY : cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o.requires

cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o.provides: cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o.requires
	$(MAKE) -f cocos2d/cocos/CMakeFiles/cocos2d.dir/build.make cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o.provides.build
.PHONY : cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o.provides

cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o.provides.build: cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o


# Object files for target cocos2d
cocos2d_OBJECTS = \
"CMakeFiles/cocos2d.dir/cc_dummy.c.o"

# External object files for target cocos2d
cocos2d_EXTERNAL_OBJECTS =

lib/libcocos2d.a: cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o
lib/libcocos2d.a: cocos2d/cocos/CMakeFiles/cocos2d.dir/build.make
lib/libcocos2d.a: cocos2d/cocos/CMakeFiles/cocos2d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libcocos2d.a"
	cd /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/cocos2d/cocos && $(CMAKE_COMMAND) -P CMakeFiles/cocos2d.dir/cmake_clean_target.cmake
	cd /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/cocos2d/cocos && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cocos2d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cocos2d/cocos/CMakeFiles/cocos2d.dir/build: lib/libcocos2d.a

.PHONY : cocos2d/cocos/CMakeFiles/cocos2d.dir/build

cocos2d/cocos/CMakeFiles/cocos2d.dir/requires: cocos2d/cocos/CMakeFiles/cocos2d.dir/cc_dummy.c.o.requires

.PHONY : cocos2d/cocos/CMakeFiles/cocos2d.dir/requires

cocos2d/cocos/CMakeFiles/cocos2d.dir/clean:
	cd /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/cocos2d/cocos && $(CMAKE_COMMAND) -P CMakeFiles/cocos2d.dir/cmake_clean.cmake
.PHONY : cocos2d/cocos/CMakeFiles/cocos2d.dir/clean

cocos2d/cocos/CMakeFiles/cocos2d.dir/depend:
	cd /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anand3132/2LocalRepository/GameProject1 /home/anand3132/2LocalRepository/GameProject1/cocos2d/cocos /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/cocos2d/cocos /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/cocos2d/cocos/CMakeFiles/cocos2d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cocos2d/cocos/CMakeFiles/cocos2d.dir/depend

