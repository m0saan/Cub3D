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
CMAKE_SOURCE_DIR = /Users/moboustt/Desktop/VVVVV

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/moboustt/Desktop/VVVVV/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TEST.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TEST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TEST.dir/flags.make

CMakeFiles/TEST.dir/srcs/main.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/main.c.o: ../srcs/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TEST.dir/srcs/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/main.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/main.c

CMakeFiles/TEST.dir/srcs/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/main.c > CMakeFiles/TEST.dir/srcs/main.c.i

CMakeFiles/TEST.dir/srcs/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/main.c -o CMakeFiles/TEST.dir/srcs/main.c.s

CMakeFiles/TEST.dir/srcs/ray_casting.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/ray_casting.c.o: ../srcs/ray_casting.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TEST.dir/srcs/ray_casting.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/ray_casting.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/ray_casting.c

CMakeFiles/TEST.dir/srcs/ray_casting.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/ray_casting.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/ray_casting.c > CMakeFiles/TEST.dir/srcs/ray_casting.c.i

CMakeFiles/TEST.dir/srcs/ray_casting.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/ray_casting.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/ray_casting.c -o CMakeFiles/TEST.dir/srcs/ray_casting.c.s

CMakeFiles/TEST.dir/srcs/cube3d_utils.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/cube3d_utils.c.o: ../srcs/cube3d_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TEST.dir/srcs/cube3d_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/cube3d_utils.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/cube3d_utils.c

CMakeFiles/TEST.dir/srcs/cube3d_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/cube3d_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/cube3d_utils.c > CMakeFiles/TEST.dir/srcs/cube3d_utils.c.i

CMakeFiles/TEST.dir/srcs/cube3d_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/cube3d_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/cube3d_utils.c -o CMakeFiles/TEST.dir/srcs/cube3d_utils.c.s

CMakeFiles/TEST.dir/srcs/sprite.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/sprite.c.o: ../srcs/sprite.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/TEST.dir/srcs/sprite.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/sprite.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/sprite.c

CMakeFiles/TEST.dir/srcs/sprite.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/sprite.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/sprite.c > CMakeFiles/TEST.dir/srcs/sprite.c.i

CMakeFiles/TEST.dir/srcs/sprite.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/sprite.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/sprite.c -o CMakeFiles/TEST.dir/srcs/sprite.c.s

CMakeFiles/TEST.dir/srcs/events.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/events.c.o: ../srcs/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/TEST.dir/srcs/events.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/events.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/events.c

CMakeFiles/TEST.dir/srcs/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/events.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/events.c > CMakeFiles/TEST.dir/srcs/events.c.i

CMakeFiles/TEST.dir/srcs/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/events.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/events.c -o CMakeFiles/TEST.dir/srcs/events.c.s

CMakeFiles/TEST.dir/srcs/map_file_parser.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/map_file_parser.c.o: ../srcs/map_file_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/TEST.dir/srcs/map_file_parser.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/map_file_parser.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/map_file_parser.c

CMakeFiles/TEST.dir/srcs/map_file_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/map_file_parser.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/map_file_parser.c > CMakeFiles/TEST.dir/srcs/map_file_parser.c.i

CMakeFiles/TEST.dir/srcs/map_file_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/map_file_parser.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/map_file_parser.c -o CMakeFiles/TEST.dir/srcs/map_file_parser.c.s

CMakeFiles/TEST.dir/srcs/parse_textures.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/parse_textures.c.o: ../srcs/parse_textures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/TEST.dir/srcs/parse_textures.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/parse_textures.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/parse_textures.c

CMakeFiles/TEST.dir/srcs/parse_textures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/parse_textures.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/parse_textures.c > CMakeFiles/TEST.dir/srcs/parse_textures.c.i

CMakeFiles/TEST.dir/srcs/parse_textures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/parse_textures.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/parse_textures.c -o CMakeFiles/TEST.dir/srcs/parse_textures.c.s

CMakeFiles/TEST.dir/srcs/parse_map.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/parse_map.c.o: ../srcs/parse_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/TEST.dir/srcs/parse_map.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/parse_map.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/parse_map.c

CMakeFiles/TEST.dir/srcs/parse_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/parse_map.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/parse_map.c > CMakeFiles/TEST.dir/srcs/parse_map.c.i

CMakeFiles/TEST.dir/srcs/parse_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/parse_map.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/parse_map.c -o CMakeFiles/TEST.dir/srcs/parse_map.c.s

CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.o: ../srcs/parse_floor_ceilling_resolution.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/parse_floor_ceilling_resolution.c

CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/parse_floor_ceilling_resolution.c > CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.i

CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/parse_floor_ceilling_resolution.c -o CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.s

CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.o: ../srcs/map_file_parser_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/map_file_parser_utils.c

CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/map_file_parser_utils.c > CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.i

CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/map_file_parser_utils.c -o CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.s

CMakeFiles/TEST.dir/srcs/render.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/render.c.o: ../srcs/render.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/TEST.dir/srcs/render.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/render.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/render.c

CMakeFiles/TEST.dir/srcs/render.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/render.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/render.c > CMakeFiles/TEST.dir/srcs/render.c.i

CMakeFiles/TEST.dir/srcs/render.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/render.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/render.c -o CMakeFiles/TEST.dir/srcs/render.c.s

CMakeFiles/TEST.dir/srcs/utils.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/utils.c.o: ../srcs/utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/TEST.dir/srcs/utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/utils.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/utils.c

CMakeFiles/TEST.dir/srcs/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/utils.c > CMakeFiles/TEST.dir/srcs/utils.c.i

CMakeFiles/TEST.dir/srcs/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/utils.c -o CMakeFiles/TEST.dir/srcs/utils.c.s

CMakeFiles/TEST.dir/srcs/screenshot.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/screenshot.c.o: ../srcs/screenshot.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/TEST.dir/srcs/screenshot.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/screenshot.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/screenshot.c

CMakeFiles/TEST.dir/srcs/screenshot.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/screenshot.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/screenshot.c > CMakeFiles/TEST.dir/srcs/screenshot.c.i

CMakeFiles/TEST.dir/srcs/screenshot.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/screenshot.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/screenshot.c -o CMakeFiles/TEST.dir/srcs/screenshot.c.s

CMakeFiles/TEST.dir/srcs/walls.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/walls.c.o: ../srcs/walls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/TEST.dir/srcs/walls.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/walls.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/walls.c

CMakeFiles/TEST.dir/srcs/walls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/walls.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/walls.c > CMakeFiles/TEST.dir/srcs/walls.c.i

CMakeFiles/TEST.dir/srcs/walls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/walls.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/walls.c -o CMakeFiles/TEST.dir/srcs/walls.c.s

CMakeFiles/TEST.dir/srcs/intersection.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/intersection.c.o: ../srcs/intersection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/TEST.dir/srcs/intersection.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/intersection.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/intersection.c

CMakeFiles/TEST.dir/srcs/intersection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/intersection.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/intersection.c > CMakeFiles/TEST.dir/srcs/intersection.c.i

CMakeFiles/TEST.dir/srcs/intersection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/intersection.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/intersection.c -o CMakeFiles/TEST.dir/srcs/intersection.c.s

CMakeFiles/TEST.dir/srcs/sprite_utils.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/sprite_utils.c.o: ../srcs/sprite_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/TEST.dir/srcs/sprite_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/sprite_utils.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/sprite_utils.c

CMakeFiles/TEST.dir/srcs/sprite_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/sprite_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/sprite_utils.c > CMakeFiles/TEST.dir/srcs/sprite_utils.c.i

CMakeFiles/TEST.dir/srcs/sprite_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/sprite_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/sprite_utils.c -o CMakeFiles/TEST.dir/srcs/sprite_utils.c.s

CMakeFiles/TEST.dir/srcs/sprite_utils2.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/sprite_utils2.c.o: ../srcs/sprite_utils2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/TEST.dir/srcs/sprite_utils2.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/sprite_utils2.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/sprite_utils2.c

CMakeFiles/TEST.dir/srcs/sprite_utils2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/sprite_utils2.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/sprite_utils2.c > CMakeFiles/TEST.dir/srcs/sprite_utils2.c.i

CMakeFiles/TEST.dir/srcs/sprite_utils2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/sprite_utils2.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/sprite_utils2.c -o CMakeFiles/TEST.dir/srcs/sprite_utils2.c.s

CMakeFiles/TEST.dir/srcs/wall_utils.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/wall_utils.c.o: ../srcs/wall_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/TEST.dir/srcs/wall_utils.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/wall_utils.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/wall_utils.c

CMakeFiles/TEST.dir/srcs/wall_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/wall_utils.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/wall_utils.c > CMakeFiles/TEST.dir/srcs/wall_utils.c.i

CMakeFiles/TEST.dir/srcs/wall_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/wall_utils.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/wall_utils.c -o CMakeFiles/TEST.dir/srcs/wall_utils.c.s

CMakeFiles/TEST.dir/srcs/init_data.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/init_data.c.o: ../srcs/init_data.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building C object CMakeFiles/TEST.dir/srcs/init_data.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/init_data.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/init_data.c

CMakeFiles/TEST.dir/srcs/init_data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/init_data.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/init_data.c > CMakeFiles/TEST.dir/srcs/init_data.c.i

CMakeFiles/TEST.dir/srcs/init_data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/init_data.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/init_data.c -o CMakeFiles/TEST.dir/srcs/init_data.c.s

CMakeFiles/TEST.dir/srcs/utils2.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/utils2.c.o: ../srcs/utils2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building C object CMakeFiles/TEST.dir/srcs/utils2.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/utils2.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/utils2.c

CMakeFiles/TEST.dir/srcs/utils2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/utils2.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/utils2.c > CMakeFiles/TEST.dir/srcs/utils2.c.i

CMakeFiles/TEST.dir/srcs/utils2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/utils2.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/utils2.c -o CMakeFiles/TEST.dir/srcs/utils2.c.s

CMakeFiles/TEST.dir/srcs/map_error_handling.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/map_error_handling.c.o: ../srcs/map_error_handling.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building C object CMakeFiles/TEST.dir/srcs/map_error_handling.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/map_error_handling.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/map_error_handling.c

CMakeFiles/TEST.dir/srcs/map_error_handling.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/map_error_handling.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/map_error_handling.c > CMakeFiles/TEST.dir/srcs/map_error_handling.c.i

CMakeFiles/TEST.dir/srcs/map_error_handling.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/map_error_handling.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/map_error_handling.c -o CMakeFiles/TEST.dir/srcs/map_error_handling.c.s

CMakeFiles/TEST.dir/srcs/hud.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/hud.c.o: ../srcs/hud.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building C object CMakeFiles/TEST.dir/srcs/hud.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/hud.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/hud.c

CMakeFiles/TEST.dir/srcs/hud.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/hud.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/hud.c > CMakeFiles/TEST.dir/srcs/hud.c.i

CMakeFiles/TEST.dir/srcs/hud.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/hud.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/hud.c -o CMakeFiles/TEST.dir/srcs/hud.c.s

CMakeFiles/TEST.dir/srcs/misc.c.o: CMakeFiles/TEST.dir/flags.make
CMakeFiles/TEST.dir/srcs/misc.c.o: ../srcs/misc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Building C object CMakeFiles/TEST.dir/srcs/misc.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TEST.dir/srcs/misc.c.o   -c /Users/moboustt/Desktop/VVVVV/srcs/misc.c

CMakeFiles/TEST.dir/srcs/misc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TEST.dir/srcs/misc.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/moboustt/Desktop/VVVVV/srcs/misc.c > CMakeFiles/TEST.dir/srcs/misc.c.i

CMakeFiles/TEST.dir/srcs/misc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TEST.dir/srcs/misc.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/moboustt/Desktop/VVVVV/srcs/misc.c -o CMakeFiles/TEST.dir/srcs/misc.c.s

# Object files for target TEST
TEST_OBJECTS = \
"CMakeFiles/TEST.dir/srcs/main.c.o" \
"CMakeFiles/TEST.dir/srcs/ray_casting.c.o" \
"CMakeFiles/TEST.dir/srcs/cube3d_utils.c.o" \
"CMakeFiles/TEST.dir/srcs/sprite.c.o" \
"CMakeFiles/TEST.dir/srcs/events.c.o" \
"CMakeFiles/TEST.dir/srcs/map_file_parser.c.o" \
"CMakeFiles/TEST.dir/srcs/parse_textures.c.o" \
"CMakeFiles/TEST.dir/srcs/parse_map.c.o" \
"CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.o" \
"CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.o" \
"CMakeFiles/TEST.dir/srcs/render.c.o" \
"CMakeFiles/TEST.dir/srcs/utils.c.o" \
"CMakeFiles/TEST.dir/srcs/screenshot.c.o" \
"CMakeFiles/TEST.dir/srcs/walls.c.o" \
"CMakeFiles/TEST.dir/srcs/intersection.c.o" \
"CMakeFiles/TEST.dir/srcs/sprite_utils.c.o" \
"CMakeFiles/TEST.dir/srcs/sprite_utils2.c.o" \
"CMakeFiles/TEST.dir/srcs/wall_utils.c.o" \
"CMakeFiles/TEST.dir/srcs/init_data.c.o" \
"CMakeFiles/TEST.dir/srcs/utils2.c.o" \
"CMakeFiles/TEST.dir/srcs/map_error_handling.c.o" \
"CMakeFiles/TEST.dir/srcs/hud.c.o" \
"CMakeFiles/TEST.dir/srcs/misc.c.o"

# External object files for target TEST
TEST_EXTERNAL_OBJECTS =

TEST: CMakeFiles/TEST.dir/srcs/main.c.o
TEST: CMakeFiles/TEST.dir/srcs/ray_casting.c.o
TEST: CMakeFiles/TEST.dir/srcs/cube3d_utils.c.o
TEST: CMakeFiles/TEST.dir/srcs/sprite.c.o
TEST: CMakeFiles/TEST.dir/srcs/events.c.o
TEST: CMakeFiles/TEST.dir/srcs/map_file_parser.c.o
TEST: CMakeFiles/TEST.dir/srcs/parse_textures.c.o
TEST: CMakeFiles/TEST.dir/srcs/parse_map.c.o
TEST: CMakeFiles/TEST.dir/srcs/parse_floor_ceilling_resolution.c.o
TEST: CMakeFiles/TEST.dir/srcs/map_file_parser_utils.c.o
TEST: CMakeFiles/TEST.dir/srcs/render.c.o
TEST: CMakeFiles/TEST.dir/srcs/utils.c.o
TEST: CMakeFiles/TEST.dir/srcs/screenshot.c.o
TEST: CMakeFiles/TEST.dir/srcs/walls.c.o
TEST: CMakeFiles/TEST.dir/srcs/intersection.c.o
TEST: CMakeFiles/TEST.dir/srcs/sprite_utils.c.o
TEST: CMakeFiles/TEST.dir/srcs/sprite_utils2.c.o
TEST: CMakeFiles/TEST.dir/srcs/wall_utils.c.o
TEST: CMakeFiles/TEST.dir/srcs/init_data.c.o
TEST: CMakeFiles/TEST.dir/srcs/utils2.c.o
TEST: CMakeFiles/TEST.dir/srcs/map_error_handling.c.o
TEST: CMakeFiles/TEST.dir/srcs/hud.c.o
TEST: CMakeFiles/TEST.dir/srcs/misc.c.o
TEST: CMakeFiles/TEST.dir/build.make
TEST: ../libmlx.a
TEST: ../libft.a
TEST: CMakeFiles/TEST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_24) "Linking C executable TEST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TEST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TEST.dir/build: TEST

.PHONY : CMakeFiles/TEST.dir/build

CMakeFiles/TEST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TEST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TEST.dir/clean

CMakeFiles/TEST.dir/depend:
	cd /Users/moboustt/Desktop/VVVVV/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/moboustt/Desktop/VVVVV /Users/moboustt/Desktop/VVVVV /Users/moboustt/Desktop/VVVVV/cmake-build-debug /Users/moboustt/Desktop/VVVVV/cmake-build-debug /Users/moboustt/Desktop/VVVVV/cmake-build-debug/CMakeFiles/TEST.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TEST.dir/depend

