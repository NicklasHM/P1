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
CMAKE_SOURCE_DIR = /Users/frederikskipper-andersen/CLionProjects/P1Again2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DatabaseTemp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DatabaseTemp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DatabaseTemp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DatabaseTemp.dir/flags.make

CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o: CMakeFiles/DatabaseTemp.dir/flags.make
CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o: /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/database.c
CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o: CMakeFiles/DatabaseTemp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o -MF CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o.d -o CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o -c /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/database.c

CMakeFiles/DatabaseTemp.dir/src/Database/database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/DatabaseTemp.dir/src/Database/database.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/database.c > CMakeFiles/DatabaseTemp.dir/src/Database/database.c.i

CMakeFiles/DatabaseTemp.dir/src/Database/database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/DatabaseTemp.dir/src/Database/database.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/database.c -o CMakeFiles/DatabaseTemp.dir/src/Database/database.c.s

CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o: CMakeFiles/DatabaseTemp.dir/flags.make
CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o: /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/simulateLedighed.c
CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o: CMakeFiles/DatabaseTemp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o -MF CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o.d -o CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o -c /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/simulateLedighed.c

CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/simulateLedighed.c > CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.i

CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/simulateLedighed.c -o CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.s

CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o: CMakeFiles/DatabaseTemp.dir/flags.make
CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o: /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/updateLedighed.c
CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o: CMakeFiles/DatabaseTemp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o -MF CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o.d -o CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o -c /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/updateLedighed.c

CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/updateLedighed.c > CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.i

CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/frederikskipper-andersen/CLionProjects/P1Again2/src/Database/updateLedighed.c -o CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.s

# Object files for target DatabaseTemp
DatabaseTemp_OBJECTS = \
"CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o" \
"CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o" \
"CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o"

# External object files for target DatabaseTemp
DatabaseTemp_EXTERNAL_OBJECTS =

DatabaseTemp: CMakeFiles/DatabaseTemp.dir/src/Database/database.c.o
DatabaseTemp: CMakeFiles/DatabaseTemp.dir/src/Database/simulateLedighed.c.o
DatabaseTemp: CMakeFiles/DatabaseTemp.dir/src/Database/updateLedighed.c.o
DatabaseTemp: CMakeFiles/DatabaseTemp.dir/build.make
DatabaseTemp: /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/lib/libsqlite3.tbd
DatabaseTemp: CMakeFiles/DatabaseTemp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable DatabaseTemp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DatabaseTemp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DatabaseTemp.dir/build: DatabaseTemp
.PHONY : CMakeFiles/DatabaseTemp.dir/build

CMakeFiles/DatabaseTemp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DatabaseTemp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DatabaseTemp.dir/clean

CMakeFiles/DatabaseTemp.dir/depend:
	cd /Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/frederikskipper-andersen/CLionProjects/P1Again2 /Users/frederikskipper-andersen/CLionProjects/P1Again2 /Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug /Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug /Users/frederikskipper-andersen/CLionProjects/P1Again2/cmake-build-debug/CMakeFiles/DatabaseTemp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/DatabaseTemp.dir/depend

