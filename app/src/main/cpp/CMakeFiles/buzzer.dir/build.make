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
CMAKE_SOURCE_DIR = /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp

# Include any dependencies generated for this target.
include CMakeFiles/buzzer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/buzzer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/buzzer.dir/flags.make

CMakeFiles/buzzer.dir/buzzer.c.o: CMakeFiles/buzzer.dir/flags.make
CMakeFiles/buzzer.dir/buzzer.c.o: buzzer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/buzzer.dir/buzzer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/buzzer.dir/buzzer.c.o   -c /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp/buzzer.c

CMakeFiles/buzzer.dir/buzzer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/buzzer.dir/buzzer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp/buzzer.c > CMakeFiles/buzzer.dir/buzzer.c.i

CMakeFiles/buzzer.dir/buzzer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/buzzer.dir/buzzer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp/buzzer.c -o CMakeFiles/buzzer.dir/buzzer.c.s

CMakeFiles/buzzer.dir/buzzer.c.o.requires:

.PHONY : CMakeFiles/buzzer.dir/buzzer.c.o.requires

CMakeFiles/buzzer.dir/buzzer.c.o.provides: CMakeFiles/buzzer.dir/buzzer.c.o.requires
	$(MAKE) -f CMakeFiles/buzzer.dir/build.make CMakeFiles/buzzer.dir/buzzer.c.o.provides.build
.PHONY : CMakeFiles/buzzer.dir/buzzer.c.o.provides

CMakeFiles/buzzer.dir/buzzer.c.o.provides.build: CMakeFiles/buzzer.dir/buzzer.c.o


# Object files for target buzzer
buzzer_OBJECTS = \
"CMakeFiles/buzzer.dir/buzzer.c.o"

# External object files for target buzzer
buzzer_EXTERNAL_OBJECTS =

libbuzzer.so: CMakeFiles/buzzer.dir/buzzer.c.o
libbuzzer.so: CMakeFiles/buzzer.dir/build.make
libbuzzer.so: CMakeFiles/buzzer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libbuzzer.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/buzzer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/buzzer.dir/build: libbuzzer.so

.PHONY : CMakeFiles/buzzer.dir/build

CMakeFiles/buzzer.dir/requires: CMakeFiles/buzzer.dir/buzzer.c.o.requires

.PHONY : CMakeFiles/buzzer.dir/requires

CMakeFiles/buzzer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/buzzer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/buzzer.dir/clean

CMakeFiles/buzzer.dir/depend:
	cd /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp /home/jaehyeon/Downloads/AndroidStudioProjects/Blockinger-master/app/src/main/cpp/CMakeFiles/buzzer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/buzzer.dir/depend
