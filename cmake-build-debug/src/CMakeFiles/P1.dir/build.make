# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\patri\CLionProjects\P1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\patri\CLionProjects\P1\cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/P1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/P1.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/P1.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/P1.dir/flags.make

src/CMakeFiles/P1.dir/main.c.obj: src/CMakeFiles/P1.dir/flags.make
src/CMakeFiles/P1.dir/main.c.obj: C:/Users/patri/CLionProjects/P1/src/main.c
src/CMakeFiles/P1.dir/main.c.obj: src/CMakeFiles/P1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\patri\CLionProjects\P1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/P1.dir/main.c.obj"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/P1.dir/main.c.obj -MF CMakeFiles\P1.dir\main.c.obj.d -o CMakeFiles\P1.dir\main.c.obj -c C:\Users\patri\CLionProjects\P1\src\main.c

src/CMakeFiles/P1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/P1.dir/main.c.i"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\patri\CLionProjects\P1\src\main.c > CMakeFiles\P1.dir\main.c.i

src/CMakeFiles/P1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/P1.dir/main.c.s"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\patri\CLionProjects\P1\src\main.c -o CMakeFiles\P1.dir\main.c.s

src/CMakeFiles/P1.dir/functions/scan_nmrplade.c.obj: src/CMakeFiles/P1.dir/flags.make
src/CMakeFiles/P1.dir/functions/scan_nmrplade.c.obj: C:/Users/patri/CLionProjects/P1/src/functions/scan_nmrplade.c
src/CMakeFiles/P1.dir/functions/scan_nmrplade.c.obj: src/CMakeFiles/P1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\patri\CLionProjects\P1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/P1.dir/functions/scan_nmrplade.c.obj"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/P1.dir/functions/scan_nmrplade.c.obj -MF CMakeFiles\P1.dir\functions\scan_nmrplade.c.obj.d -o CMakeFiles\P1.dir\functions\scan_nmrplade.c.obj -c C:\Users\patri\CLionProjects\P1\src\functions\scan_nmrplade.c

src/CMakeFiles/P1.dir/functions/scan_nmrplade.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/P1.dir/functions/scan_nmrplade.c.i"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\patri\CLionProjects\P1\src\functions\scan_nmrplade.c > CMakeFiles\P1.dir\functions\scan_nmrplade.c.i

src/CMakeFiles/P1.dir/functions/scan_nmrplade.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/P1.dir/functions/scan_nmrplade.c.s"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\patri\CLionProjects\P1\src\functions\scan_nmrplade.c -o CMakeFiles\P1.dir\functions\scan_nmrplade.c.s

src/CMakeFiles/P1.dir/functions/beregn_p_plads.c.obj: src/CMakeFiles/P1.dir/flags.make
src/CMakeFiles/P1.dir/functions/beregn_p_plads.c.obj: C:/Users/patri/CLionProjects/P1/src/functions/beregn_p_plads.c
src/CMakeFiles/P1.dir/functions/beregn_p_plads.c.obj: src/CMakeFiles/P1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\patri\CLionProjects\P1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/P1.dir/functions/beregn_p_plads.c.obj"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/P1.dir/functions/beregn_p_plads.c.obj -MF CMakeFiles\P1.dir\functions\beregn_p_plads.c.obj.d -o CMakeFiles\P1.dir\functions\beregn_p_plads.c.obj -c C:\Users\patri\CLionProjects\P1\src\functions\beregn_p_plads.c

src/CMakeFiles/P1.dir/functions/beregn_p_plads.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/P1.dir/functions/beregn_p_plads.c.i"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\patri\CLionProjects\P1\src\functions\beregn_p_plads.c > CMakeFiles\P1.dir\functions\beregn_p_plads.c.i

src/CMakeFiles/P1.dir/functions/beregn_p_plads.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/P1.dir/functions/beregn_p_plads.c.s"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\patri\CLionProjects\P1\src\functions\beregn_p_plads.c -o CMakeFiles\P1.dir\functions\beregn_p_plads.c.s

# Object files for target P1
P1_OBJECTS = \
"CMakeFiles/P1.dir/main.c.obj" \
"CMakeFiles/P1.dir/functions/scan_nmrplade.c.obj" \
"CMakeFiles/P1.dir/functions/beregn_p_plads.c.obj"

# External object files for target P1
P1_EXTERNAL_OBJECTS =

src/P1.exe: src/CMakeFiles/P1.dir/main.c.obj
src/P1.exe: src/CMakeFiles/P1.dir/functions/scan_nmrplade.c.obj
src/P1.exe: src/CMakeFiles/P1.dir/functions/beregn_p_plads.c.obj
src/P1.exe: src/CMakeFiles/P1.dir/build.make
src/P1.exe: src/CMakeFiles/P1.dir/linkLibs.rsp
src/P1.exe: src/CMakeFiles/P1.dir/objects1.rsp
src/P1.exe: src/CMakeFiles/P1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\patri\CLionProjects\P1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable P1.exe"
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\P1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/P1.dir/build: src/P1.exe
.PHONY : src/CMakeFiles/P1.dir/build

src/CMakeFiles/P1.dir/clean:
	cd /d C:\Users\patri\CLionProjects\P1\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\P1.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/P1.dir/clean

src/CMakeFiles/P1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\patri\CLionProjects\P1 C:\Users\patri\CLionProjects\P1\src C:\Users\patri\CLionProjects\P1\cmake-build-debug C:\Users\patri\CLionProjects\P1\cmake-build-debug\src C:\Users\patri\CLionProjects\P1\cmake-build-debug\src\CMakeFiles\P1.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/P1.dir/depend
