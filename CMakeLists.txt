cmake_minimum_required(VERSION 3.15)
project(lin_sim C)

set(CMAKE_C_STANDARD 11)

# ── Library ──
add_library(lin_sim
    src/lin_frame.c
)

target_include_directories(lin_sim PUBLIC
    src
)

# ── Tests ──
enable_testing()

add_executable(test_lin_sim
    tests/test_lin_sim.c
    tests/unity.c
)

target_include_directories(test_lin_sim PRIVATE
    src
    tests
)

target_link_libraries(test_lin_sim
    lin_sim
)

add_test(NAME test_lin_sim COMMAND test_lin_sim)