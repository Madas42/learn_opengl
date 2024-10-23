cmake_minimum_required(VERSION 3.29)
project(learn_opengl)

set(CMAKE_CXX_STANDARD 20)
# Override default linker flags to remove unnecessary paths (tcl-tk, etc.)
set(CMAKE_EXE_LINKER_FLAGS "")
set(CMAKE_MODULE_LINKER_FLAGS "")
set(CMAKE_SHARED_LINKER_FLAGS "")

# Source files
set(SOURCES
    main.cpp
        src/Application.cpp
        src/DrawableObject.cpp
        src/Model.cpp
        src/Scene.cpp
        src/Transformation.cpp
        src/Shader.cpp
        src/ShaderProgram.cpp
)

# Header files
set(HEADERS
        src/Application.h
        src/DrawableObject.h
        src/Model.h
        src/Scene.h
        src/Transformation.h
        src/Shader.h
        src/ShaderProgram.h
)

add_executable(learn_opengl ${SOURCES} ${HEADERS})

# Include directories for GLFW and GLM
include_directories(/opt/homebrew/opt/glfw/include)
include_directories(/opt/homebrew/opt/glm/include)
include_directories(/opt/homebrew/opt/glew/include)

# Link directories for GLFW
link_directories(/opt/homebrew/opt/glfw/lib)
link_directories(/opt/homebrew/opt/glew/lib)

# Link against GLFW and required frameworks
target_link_libraries(learn_opengl /opt/homebrew/opt/glfw/lib/libglfw.dylib)
target_link_libraries(learn_opengl /opt/homebrew/opt/glew/lib/libGLEW.dylib)
target_link_libraries(learn_opengl "-framework Cocoa")
target_link_libraries(learn_opengl "-framework OpenGL")
target_link_libraries(learn_opengl "-framework IOKit")