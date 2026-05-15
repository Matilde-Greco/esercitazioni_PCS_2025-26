cmake_minimum_required(VERSION 3.20)
project(eser7)

# Specifica lo standard C++ richiesto dall'esercitazione [cite: 103]
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Flag di compilazione per mantenere il codice pulito (come nel tuo esempio)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Aggiungiamo l'eseguibile principale per i test richiesti
# Assicurati che il file si chiami main.cpp, altrimenti cambia il nome qui sotto
add_executable(main main.cpp)

# Se vuoi mantenere la struttura dei test unitari per i singoli algoritmi
enable_testing()

# Esempio: aggiungi un test che esegue il programma principale
add_test(NAME esercitazione_test COMMAND main)