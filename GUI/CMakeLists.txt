cmake_minimum_required(VERSION 2.8.11)
project(projwizard)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

set(gui_SRC
  src/main.cpp
  src/gui.cpp
)

set(Boost_DETAILED_FAILURE_MSG TRUE)
#set(BOOST_LIBRARYDIR "/usr/lib/x86_64-linux-gnu/")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(Boost_ADDITIONAL_VERSIONS "1.54.0")
find_package(Boost ${Boost_ADDITIONAL_VERSIONS} COMPONENTS filesystem REQUIRED)

# Create code from a list of Qt designer ui files.
#set(CMAKE_AUTOUIC ON) # use this if you have CMake 3.x instead of the following
qt5_wrap_ui(gui_SRC src/gui.ui)

# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} ${gui_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets ProjectWizard ${Boost_LIBRARIES})
