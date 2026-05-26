cmake_minimum_required(VERSION 3.20)
project(eser8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Abilita il supporto ai test in CMake (crea il comando "make test" o "ctest")
enable_testing()

# Cerca la libreria Eigen nel sistema
find_package(Eigen3 REQUIRED)

# Creo il target per l'eseguibile di test
set(SRC_pcg pcg.cpp)
add_executable(main_pcg ${SRC_pcg})

# Collego Eigen all'eseguibile
target_link_libraries(main_pcg PRIVATE Eigen3::Eigen)

# REGISTRAZIONE DEL TEST: Diciamo a CTest di lanciare questo eseguibile
# "test_gradiente" è il nome che comparirà nella lista dei test di CTest
add_test(NAME test_gradiente COMMAND main_pcg)