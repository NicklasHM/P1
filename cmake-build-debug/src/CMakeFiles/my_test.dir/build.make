# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nhm/CLionProjects/P1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nhm/CLionProjects/P1/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/my_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/my_test.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/my_test.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/my_test.dir/flags.make

src/CMakeFiles/my_test.dir/test/test_functions.c.o: src/CMakeFiles/my_test.dir/flags.make
src/CMakeFiles/my_test.dir/test/test_functions.c.o: /Users/nhm/CLionProjects/P1/src/test/test_functions.c
src/CMakeFiles/my_test.dir/test/test_functions.c.o: src/CMakeFiles/my_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nhm/CLionProjects/P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/my_test.dir/test/test_functions.c.o"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/my_test.dir/test/test_functions.c.o -MF CMakeFiles/my_test.dir/test/test_functions.c.o.d -o CMakeFiles/my_test.dir/test/test_functions.c.o -c /Users/nhm/CLionProjects/P1/src/test/test_functions.c

src/CMakeFiles/my_test.dir/test/test_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/my_test.dir/test/test_functions.c.i"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nhm/CLionProjects/P1/src/test/test_functions.c > CMakeFiles/my_test.dir/test/test_functions.c.i

src/CMakeFiles/my_test.dir/test/test_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/my_test.dir/test/test_functions.c.s"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nhm/CLionProjects/P1/src/test/test_functions.c -o CMakeFiles/my_test.dir/test/test_functions.c.s

src/CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o: src/CMakeFiles/my_test.dir/flags.make
src/CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o: /Users/nhm/CLionProjects/P1/src/functions/scan_nmrplade.c
src/CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o: src/CMakeFiles/my_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nhm/CLionProjects/P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o -MF CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o.d -o CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o -c /Users/nhm/CLionProjects/P1/src/functions/scan_nmrplade.c

src/CMakeFiles/my_test.dir/functions/scan_nmrplade.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/my_test.dir/functions/scan_nmrplade.c.i"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nhm/CLionProjects/P1/src/functions/scan_nmrplade.c > CMakeFiles/my_test.dir/functions/scan_nmrplade.c.i

src/CMakeFiles/my_test.dir/functions/scan_nmrplade.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/my_test.dir/functions/scan_nmrplade.c.s"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nhm/CLionProjects/P1/src/functions/scan_nmrplade.c -o CMakeFiles/my_test.dir/functions/scan_nmrplade.c.s

src/CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o: src/CMakeFiles/my_test.dir/flags.make
src/CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o: /Users/nhm/CLionProjects/P1/src/functions/beregn_p_plads.c
src/CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o: src/CMakeFiles/my_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nhm/CLionProjects/P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o -MF CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o.d -o CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o -c /Users/nhm/CLionProjects/P1/src/functions/beregn_p_plads.c

src/CMakeFiles/my_test.dir/functions/beregn_p_plads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/my_test.dir/functions/beregn_p_plads.c.i"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nhm/CLionProjects/P1/src/functions/beregn_p_plads.c > CMakeFiles/my_test.dir/functions/beregn_p_plads.c.i

src/CMakeFiles/my_test.dir/functions/beregn_p_plads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/my_test.dir/functions/beregn_p_plads.c.s"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nhm/CLionProjects/P1/src/functions/beregn_p_plads.c -o CMakeFiles/my_test.dir/functions/beregn_p_plads.c.s

# Object files for target my_test
my_test_OBJECTS = \
"CMakeFiles/my_test.dir/test/test_functions.c.o" \
"CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o" \
"CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o"

# External object files for target my_test
my_test_EXTERNAL_OBJECTS =

src/my_test: src/CMakeFiles/my_test.dir/test/test_functions.c.o
src/my_test: src/CMakeFiles/my_test.dir/functions/scan_nmrplade.c.o
src/my_test: src/CMakeFiles/my_test.dir/functions/beregn_p_plads.c.o
src/my_test: src/CMakeFiles/my_test.dir/build.make
src/my_test: src/CMakeFiles/my_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/nhm/CLionProjects/P1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable my_test"
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/my_test.dir/build: src/my_test
.PHONY : src/CMakeFiles/my_test.dir/build

src/CMakeFiles/my_test.dir/clean:
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/my_test.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/my_test.dir/clean

src/CMakeFiles/my_test.dir/depend:
	cd /Users/nhm/CLionProjects/P1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nhm/CLionProjects/P1 /Users/nhm/CLionProjects/P1/src /Users/nhm/CLionProjects/P1/cmake-build-debug /Users/nhm/CLionProjects/P1/cmake-build-debug/src /Users/nhm/CLionProjects/P1/cmake-build-debug/src/CMakeFiles/my_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/my_test.dir/depend

