cmake_minimum_required(VERSION 3.10)

# 1. Nombre de tu mod
project(BetterInfoAndroid)

# 2. IMPORTANTE: Decirle a CxStudio dónde están los headers de Geode
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 3. Crear el archivo de salida (librería .so)
add_library(BetterInfoAndroid SHARED main.cpp)

# 4. Enlazar librerías base de Android
target_link_libraries(BetterInfoAndroid log android GLESv2)