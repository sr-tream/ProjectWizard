cmake_minimum_required(VERSION 2.8)

project(ProjectWizard)

option(BUILD_CLI "Build CLI frontend [ON/OFF]" ON)
option(BUILD_GUI "Build GUI frontend [ON/OFF]" ON)

set(Boost_DETAILED_FAILURE_MSG TRUE)
#set(BOOST_LIBRARYDIR "/usr/lib/x86_64-linux-gnu/")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(Boost_ADDITIONAL_VERSIONS "1.54.0")
find_package(Boost ${Boost_ADDITIONAL_VERSIONS} COMPONENTS filesystem REQUIRED)

macro( getSrcList placeholder floderName )
	set( GSL "" )
	file(GLOB GSL_CPP "${floderName}/*.cpp")
	file(GLOB GSL_HPP "${floderName}/*.hpp")
	file(GLOB GSL_C "${floderName}/*.c")
	file(GLOB GSL_H "${floderName}/*.h")
	file(GLOB GSL ${GSL}}
		${GSL_CPP}
		${GSL_HPP}
		${GSL_C}
		${GSL_H})
endmacro( getSrcList )


set( GSL "" )
getSrcList(${GSL}, .)
file(GLOB ${PROJECT_NAME}_LIST ${${PROJECT_NAME}_LIST} ${GSL})

set( GSL "" )
getSrcList(${GSL}, FileMan)
file(GLOB ${PROJECT_NAME}_LIST ${${PROJECT_NAME}_LIST} ${GSL})


add_definitions("-std=c++14 -ffunction-sections -fexec-charset=CP1251")
set(BUILD_LFLAGS "-Wl,--gc-sections")
set(CMAKE_SHARED_LINKER_FLAGS ${BUILD_LFLAGS})

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_LIST})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

if (BUILD_CLI)
	add_subdirectory(CLI)
endif(BUILD_CLI)

if (BUILD_GUI)
	add_subdirectory(GUI)
endif(BUILD_GUI)
