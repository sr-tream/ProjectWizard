cmake_minimum_required(VERSION 2.8)

project(projwizard_cli)

set(Boost_DETAILED_FAILURE_MSG TRUE)
#set(BOOST_LIBRARYDIR "/usr/lib/x86_64-linux-gnu/")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(Boost_ADDITIONAL_VERSIONS "1.62.0")
find_package(Boost ${Boost_ADDITIONAL_VERSIONS} COMPONENTS filesystem REQUIRED)


file(GLOB ${PROJECT_NAME}_SOURCES "*.cpp")
file(GLOB ${PROJECT_NAME}_HEADERS "*.h")
file(GLOB LIB_PW_H "../*.h")
file(GLOB LIB_PW_HPP "../*.hpp")
file(GLOB LIB_PW_FMH "../FileMan/*.h")
file(GLOB ${PROJECT_NAME}_LIST ${${PROJECT_NAME}_LIST}
	${LIB_PW_H} ${LIB_PW_HPP} ${LIB_PW_FMH}
	${${PROJECT_NAME}_SOURCES}
	${${PROJECT_NAME}_HEADERS})


add_definitions("-std=c++14 -ffunction-sections -fexec-charset=CP1251")
set(BUILD_LFLAGS "-Wl,--gc-sections")
set(CMAKE_SHARED_LINKER_FLAGS ${BUILD_LFLAGS})

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_LIST})

target_link_libraries(${PROJECT_NAME} ProjectWizard ${Boost_LIBRARIES})
