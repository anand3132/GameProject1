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
include CMakeFiles/MyGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyGame.dir/flags.make

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o: ../Classes/AppDelegate.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o -c /home/anand3132/2LocalRepository/GameProject1/Classes/AppDelegate.cpp

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anand3132/2LocalRepository/GameProject1/Classes/AppDelegate.cpp > CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anand3132/2LocalRepository/GameProject1/Classes/AppDelegate.cpp -o CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires:

.PHONY : CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o


CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o: ../Classes/HelloWorldScene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o -c /home/anand3132/2LocalRepository/GameProject1/Classes/HelloWorldScene.cpp

CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anand3132/2LocalRepository/GameProject1/Classes/HelloWorldScene.cpp > CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.i

CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anand3132/2LocalRepository/GameProject1/Classes/HelloWorldScene.cpp -o CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.s

CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o.requires:

.PHONY : CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o.requires

CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o.provides: CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o.provides

CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o.provides.build: CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o


CMakeFiles/MyGame.dir/proj.linux/main.cpp.o: CMakeFiles/MyGame.dir/flags.make
CMakeFiles/MyGame.dir/proj.linux/main.cpp.o: ../proj.linux/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MyGame.dir/proj.linux/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyGame.dir/proj.linux/main.cpp.o -c /home/anand3132/2LocalRepository/GameProject1/proj.linux/main.cpp

CMakeFiles/MyGame.dir/proj.linux/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyGame.dir/proj.linux/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anand3132/2LocalRepository/GameProject1/proj.linux/main.cpp > CMakeFiles/MyGame.dir/proj.linux/main.cpp.i

CMakeFiles/MyGame.dir/proj.linux/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyGame.dir/proj.linux/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anand3132/2LocalRepository/GameProject1/proj.linux/main.cpp -o CMakeFiles/MyGame.dir/proj.linux/main.cpp.s

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires:

.PHONY : CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides.build
.PHONY : CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides

CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.provides.build: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o


# Object files for target MyGame
MyGame_OBJECTS = \
"CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o" \
"CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o" \
"CMakeFiles/MyGame.dir/proj.linux/main.cpp.o"

# External object files for target MyGame
MyGame_EXTERNAL_OBJECTS =

bin/MyGame: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o
bin/MyGame: CMakeFiles/MyGame.dir/build.make
bin/MyGame: lib/libcocos2d.a
bin/MyGame: lib/libcocos2dInternal.a
bin/MyGame: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/MyGame: /usr/lib/x86_64-linux-gnu/libGL.so
bin/MyGame: /usr/lib/x86_64-linux-gnu/libGLEW.so
bin/MyGame: lib/libunzip.a
bin/MyGame: lib/libtinyxml2.a
bin/MyGame: ../cocos2d/external/linux-specific/fmod/prebuilt/64-bit/libfmod.so
bin/MyGame: /usr/lib/x86_64-linux-gnu/libz.so
bin/MyGame: ../cocos2d/external/jpeg/prebuilt/linux/64-bit/libjpeg.a
bin/MyGame: /usr/lib/x86_64-linux-gnu/libpng.so
bin/MyGame: ../cocos2d/external/tiff/prebuilt/linux/64-bit/libtiff.a
bin/MyGame: ../cocos2d/external/freetype2/prebuilt/linux/64-bit/libfreetype.a
bin/MyGame: ../cocos2d/external/websockets/prebuilt/linux/64-bit/libwebsockets.a
bin/MyGame: ../cocos2d/external/linux-specific/fmod/prebuilt/64-bit/libfmod.so
bin/MyGame: /usr/lib/x86_64-linux-gnu/libz.so
bin/MyGame: ../cocos2d/external/jpeg/prebuilt/linux/64-bit/libjpeg.a
bin/MyGame: /usr/lib/x86_64-linux-gnu/libpng.so
bin/MyGame: ../cocos2d/external/tiff/prebuilt/linux/64-bit/libtiff.a
bin/MyGame: ../cocos2d/external/freetype2/prebuilt/linux/64-bit/libfreetype.a
bin/MyGame: ../cocos2d/external/websockets/prebuilt/linux/64-bit/libwebsockets.a
bin/MyGame: lib/libxxhash.a
bin/MyGame: ../cocos2d/external/webp/prebuilt/linux/64-bit/libwebp.a
bin/MyGame: ../cocos2d/external/chipmunk/prebuilt/linux/64-bit/libchipmunk.a
bin/MyGame: lib/libbullet.a
bin/MyGame: lib/librecast.a
bin/MyGame: CMakeFiles/MyGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bin/MyGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyGame.dir/build: bin/MyGame

.PHONY : CMakeFiles/MyGame.dir/build

CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/Classes/HelloWorldScene.cpp.o.requires
CMakeFiles/MyGame.dir/requires: CMakeFiles/MyGame.dir/proj.linux/main.cpp.o.requires

.PHONY : CMakeFiles/MyGame.dir/requires

CMakeFiles/MyGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyGame.dir/clean

CMakeFiles/MyGame.dir/depend:
	cd /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anand3132/2LocalRepository/GameProject1 /home/anand3132/2LocalRepository/GameProject1 /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator /home/anand3132/2LocalRepository/GameProject1/proj.linux-QtCreator/CMakeFiles/MyGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyGame.dir/depend

