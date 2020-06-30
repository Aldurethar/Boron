# List of all the source files, add new files here
set(SOURCE_LIST
	Boron.h
	BoronCore/Core.h
	BoronCore/Application.h
	BoronCore/Application.cpp
	BoronCore/Entrypoint.h
	BoronCore/Logging.h
	BoronCore/Logging.cpp
	BoronCore/Message.h
	BoronCore/MessageBus.h
	BoronCore/MessageBus.cpp
)

# Setup Boron as shared/dynamic library (dll)
add_library(Boron SHARED ${SOURCE_LIST})

# Add Precompiler Definitions to Boron
target_compile_definitions(Boron PRIVATE BORON_BUILD_DLL)

# Make the Folder structure within the VS Project follow the folder structure of the files
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_LIST})

# Link any Libraries that Boron uses, add new libraries here
target_link_libraries(Boron glfw)
target_link_libraries(Boron glad)
target_link_libraries(Boron spdlog)