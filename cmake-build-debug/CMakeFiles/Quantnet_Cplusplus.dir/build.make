# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Quantnet_Cplusplus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Quantnet_Cplusplus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Quantnet_Cplusplus.dir/flags.make

CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.o: CMakeFiles/Quantnet_Cplusplus.dir/flags.make
CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.o: ../Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.o -c "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp"

CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp" > CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.i

CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp" -o CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.s

# Object files for target Quantnet_Cplusplus
Quantnet_Cplusplus_OBJECTS = \
"CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.o"

# External object files for target Quantnet_Cplusplus
Quantnet_Cplusplus_EXTERNAL_OBJECTS =

Quantnet_Cplusplus: CMakeFiles/Quantnet_Cplusplus.dir/Level_5/Homework/Section_3_5/Exercise_1/test_Shape.cpp.o
Quantnet_Cplusplus: CMakeFiles/Quantnet_Cplusplus.dir/build.make
Quantnet_Cplusplus: CMakeFiles/Quantnet_Cplusplus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Quantnet_Cplusplus"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Quantnet_Cplusplus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Quantnet_Cplusplus.dir/build: Quantnet_Cplusplus

.PHONY : CMakeFiles/Quantnet_Cplusplus.dir/build

CMakeFiles/Quantnet_Cplusplus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Quantnet_Cplusplus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Quantnet_Cplusplus.dir/clean

CMakeFiles/Quantnet_Cplusplus.dir/depend:
	cd "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus" "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus" "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/cmake-build-debug" "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/cmake-build-debug" "/Users/jeffsnguyen/OneDrive/Cloud Storage/Courses/Quantnet/C++/Quantnet_Cplusplus/cmake-build-debug/CMakeFiles/Quantnet_Cplusplus.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Quantnet_Cplusplus.dir/depend

