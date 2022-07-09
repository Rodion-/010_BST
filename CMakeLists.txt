cmake_minimum_required(VERSION 3.16)

set( prj_name algo10 )

project(${prj_name} VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -pthread")

add_executable(${prj_name} main.cpp )


#target_compile_features(thread cxx_std_17)


target_include_directories(${prj_name} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
          	  
install(TARGETS ${prj_name} DESTINATION bin)
		
