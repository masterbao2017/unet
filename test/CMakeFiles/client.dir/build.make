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
CMAKE_SOURCE_DIR = /home/uuchen/uProject/unet/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uuchen/uProject/unet/test

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/TcpClientTest.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/TcpClientTest.cc.o: TcpClientTest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/TcpClientTest.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/TcpClientTest.cc.o -c /home/uuchen/uProject/unet/test/TcpClientTest.cc

CMakeFiles/client.dir/TcpClientTest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/TcpClientTest.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uuchen/uProject/unet/test/TcpClientTest.cc > CMakeFiles/client.dir/TcpClientTest.cc.i

CMakeFiles/client.dir/TcpClientTest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/TcpClientTest.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uuchen/uProject/unet/test/TcpClientTest.cc -o CMakeFiles/client.dir/TcpClientTest.cc.s

CMakeFiles/client.dir/TcpClientTest.cc.o.requires:

.PHONY : CMakeFiles/client.dir/TcpClientTest.cc.o.requires

CMakeFiles/client.dir/TcpClientTest.cc.o.provides: CMakeFiles/client.dir/TcpClientTest.cc.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/TcpClientTest.cc.o.provides.build
.PHONY : CMakeFiles/client.dir/TcpClientTest.cc.o.provides

CMakeFiles/client.dir/TcpClientTest.cc.o.provides.build: CMakeFiles/client.dir/TcpClientTest.cc.o


CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o: /home/uuchen/uProject/unet/TcpConnection.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o -c /home/uuchen/uProject/unet/TcpConnection.cc

CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uuchen/uProject/unet/TcpConnection.cc > CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.i

CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uuchen/uProject/unet/TcpConnection.cc -o CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.s

CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o.requires:

.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o.requires

CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o.provides: CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o.provides.build
.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o.provides

CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o.provides.build: CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o


CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o: /home/uuchen/uProject/unet/base/Alloc.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o -c /home/uuchen/uProject/unet/base/Alloc.cc

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uuchen/uProject/unet/base/Alloc.cc > CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.i

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uuchen/uProject/unet/base/Alloc.cc -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.s

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o.requires:

.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o.requires

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o.provides: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o.provides.build
.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o.provides

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o.provides.build: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o


CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o: /home/uuchen/uProject/unet/base/Buffer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o -c /home/uuchen/uProject/unet/base/Buffer.cc

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uuchen/uProject/unet/base/Buffer.cc > CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.i

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uuchen/uProject/unet/base/Buffer.cc -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.s

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o.requires:

.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o.requires

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o.provides: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o.provides.build
.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o.provides

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o.provides.build: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o


CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o: /home/uuchen/uProject/unet/base/Socket.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o -c /home/uuchen/uProject/unet/base/Socket.cc

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uuchen/uProject/unet/base/Socket.cc > CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.i

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uuchen/uProject/unet/base/Socket.cc -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.s

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o.requires:

.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o.requires

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o.provides: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o.provides.build
.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o.provides

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o.provides.build: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o


CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o: /home/uuchen/uProject/unet/base/Mutex.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o -c /home/uuchen/uProject/unet/base/Mutex.cc

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uuchen/uProject/unet/base/Mutex.cc > CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.i

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uuchen/uProject/unet/base/Mutex.cc -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.s

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o.requires:

.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o.requires

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o.provides: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o.provides.build
.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o.provides

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o.provides.build: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o


CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o: /home/uuchen/uProject/unet/base/Global.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o -c /home/uuchen/uProject/unet/base/Global.cc

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uuchen/uProject/unet/base/Global.cc > CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.i

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uuchen/uProject/unet/base/Global.cc -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.s

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o.requires:

.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o.requires

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o.provides: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o.provides.build
.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o.provides

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o.provides.build: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o


CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o: /home/uuchen/uProject/unet/base/InetAddress.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o -c /home/uuchen/uProject/unet/base/InetAddress.cc

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uuchen/uProject/unet/base/InetAddress.cc > CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.i

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uuchen/uProject/unet/base/InetAddress.cc -o CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.s

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o.requires:

.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o.requires

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o.provides: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o.provides.build
.PHONY : CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o.provides

CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o.provides.build: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o


# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/TcpClientTest.cc.o" \
"CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o" \
"CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o" \
"CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o" \
"CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o" \
"CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o" \
"CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o" \
"CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/TcpClientTest.cc.o
client: CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o
client: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o
client: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o
client: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o
client: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o
client: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o
client: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o
client: CMakeFiles/client.dir/build.make
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uuchen/uProject/unet/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/requires: CMakeFiles/client.dir/TcpClientTest.cc.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/home/uuchen/uProject/unet/TcpConnection.cc.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Alloc.cc.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Buffer.cc.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Socket.cc.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Mutex.cc.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/Global.cc.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/home/uuchen/uProject/unet/base/InetAddress.cc.o.requires

.PHONY : CMakeFiles/client.dir/requires

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/uuchen/uProject/unet/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uuchen/uProject/unet/test /home/uuchen/uProject/unet/test /home/uuchen/uProject/unet/test /home/uuchen/uProject/unet/test /home/uuchen/uProject/unet/test/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend
