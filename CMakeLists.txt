cmake_minimum_required(VERSION 3.26)

project(rtxt 
    VERSION 0.1.0 
    LANGUAGES CXX
)

add_executable(rtxi main.cpp backend.cpp)

target_compile_features(rtxi PRIVATE cxx_std_23)
set_target_properties(rtxi PROPERTIES
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF 
)

if(MSVC)
    target_compile_options(rtxi PRIVATE /W4 /WX)
else()
    target_compile_options(rtxi PRIVATE 
        -Wall 
        -Wextra 
        -Wpedantic 
        # -Werror 
        -O3      
        -march=native
    )
endif()

target_include_directories(rtxi PRIVATE include)
target_link_libraries(rtxi readline)
