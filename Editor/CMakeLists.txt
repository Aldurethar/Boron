# List of all the source files, add new files here
set(SOURCE_LIST
	main.cpp
)

# Setup Editor as an executable
add_executable(Editor ${SOURCE_LIST})

# Make the Folder structure within the VS Project follow the folder structure of the files
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_LIST})

# Link Boron to Editor, should be the only required Link
target_link_libraries(Editor Boron)

# Add an include path for editor to access Boron.h
target_include_directories(Editor PRIVATE
	"../Boron")