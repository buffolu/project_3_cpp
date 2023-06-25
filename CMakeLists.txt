cmake_minimum_required(VERSION 3.23)
project(project_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_3 main.cpp Model.cpp Model.h Thug.cpp Agent.cpp Agent.h Thug.h Sim_object.h Sim_object.cpp  Structure.h
        Structure.cpp Peasant.cpp Knight.cpp Controller.cpp Controller.h)
