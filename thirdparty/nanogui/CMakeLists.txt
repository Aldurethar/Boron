#cmake_minimum_required (VERSION 2.8.12)

project(nanogui)

set(NANOGUI_BUILD_EXAMPLES OFF)

# Required libraries, flags, and include files for compiling and linking against nanogui (all targets)
set(LIBNANOGUI_EXTRA_SOURCE "")

#Add OpenGL specific sources
list(APPEND LIBNANOGUI_EXTRA_SOURCE
    src/texture_gl.cpp src/shader_gl.cpp
    src/renderpass_gl.cpp src/opengl.cpp
    src/opengl_check.h
)
message(STATUS "NanoGUI: using OpenGL backend.")

if (MSVC)
  # Disable annoying MSVC warnings (all targets)
  add_definitions(/D "_CRT_SECURE_NO_WARNINGS")

  # Parallel build on MSVC (all targets)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
  
  # Compile with compiler warnings turned on
  if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
endif()

# glob all the resource files
file(GLOB resources
  "${CMAKE_CURRENT_SOURCE_DIR}/resources/*.ttf"
  "${CMAKE_CURRENT_SOURCE_DIR}/resources/*.gl"
)
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/resources")

foreach(fname_in IN LISTS resources)
  list(APPEND resources_processed ${fname_in})
endforeach()

# Concatenate resource files into a comma separated string
string(REGEX REPLACE "([^\\]|^);" "\\1," resources_string "${resources_processed}")
string(REGEX REPLACE "[\\](.)" "\\1" resources_string "${resources_string}")

# Create command line for running bin2c cmake script
set(bin2c_cmdline
  -DOUTPUT_C=nanogui_resources.cpp
  -DOUTPUT_H=nanogui_resources.h
  "-DINPUT_FILES=${resources_string}"
  -P "${CMAKE_CURRENT_SOURCE_DIR}/resources/bin2c.cmake")
  
# Run bin2c on resource files
add_custom_command(
  OUTPUT nanogui_resources.cpp nanogui_resources.h
  COMMAND ${CMAKE_COMMAND} ARGS ${bin2c_cmdline}
  DEPENDS ${resources} ${resources_processed}
  COMMENT "Running bin2c"
  PRE_BUILD VERBATIM)
  
add_definitions(-DNANOGUI_USE_OPENGL)

# Compile main NanoGUI library
add_library(nanogui STATIC
  # Merge NanoVG into the NanoGUI library
  ext/nanovg/src/nanovg.c
  ext/nanovg/src/stb_image.h
  # Add OpenGL specific sources
  ${LIBNANOGUI_EXTRA_SOURCE}
  # Fonts etc.
  nanogui_resources.cpp
  include/nanogui/common.h src/common.cpp
  include/nanogui/widget.h src/widget.cpp
  include/nanogui/theme.h src/theme.cpp
  include/nanogui/layout.h src/layout.cpp
  include/nanogui/screen.h src/screen.cpp
  include/nanogui/label.h src/label.cpp
  include/nanogui/window.h src/window.cpp
  include/nanogui/popup.h src/popup.cpp
  include/nanogui/checkbox.h src/checkbox.cpp
  include/nanogui/button.h src/button.cpp
  include/nanogui/popupbutton.h src/popupbutton.cpp
  include/nanogui/combobox.h src/combobox.cpp
  include/nanogui/progressbar.h src/progressbar.cpp
  include/nanogui/slider.h src/slider.cpp
  include/nanogui/messagedialog.h src/messagedialog.cpp
  include/nanogui/textbox.h src/textbox.cpp
  include/nanogui/textarea.h src/textarea.cpp
  include/nanogui/imagepanel.h src/imagepanel.cpp
  include/nanogui/vscrollpanel.h src/vscrollpanel.cpp
  include/nanogui/colorwheel.h src/colorwheel.cpp
  include/nanogui/colorpicker.h src/colorpicker.cpp
  include/nanogui/graph.h src/graph.cpp
  include/nanogui/tabwidget.h src/tabwidget.cpp
  include/nanogui/canvas.h src/canvas.cpp
  include/nanogui/texture.h src/texture.cpp
  include/nanogui/shader.h src/shader.cpp
  include/nanogui/imageview.h src/imageview.cpp
  include/nanogui/traits.h src/traits.cpp
  include/nanogui/renderpass.h
  include/nanogui/formhelper.h
  include/nanogui/icons.h
  include/nanogui/toolbutton.h
  include/nanogui/opengl.h
  include/nanogui/nanogui.h
)

target_include_directories(nanogui PUBLIC
  "ext/nanovg/src"
  "include"
  ${CMAKE_CURRENT_BINARY_DIR}
)

# Compile/link flags for NanoGUI
set_property(TARGET nanogui APPEND PROPERTY COMPILE_DEFINITIONS "NANOGUI_BUILD;NVG_BUILD;NVG_STB_IMAGE_IMPLEMENTATION")

if(WIN32)
  target_link_libraries(nanogui PUBLIC opengl32)
endif()

target_link_libraries(nanogui PUBLIC glfw)
target_link_libraries(nanogui PUBLIC glad)

# Quench warnings while compiling NanoVG
if(MSVC)
  set_source_files_properties(ext/nanovg/src/nanovg.c PROPERTIES COMPILE_FLAGS "/wd4005 /wd4456 /wd4457")
endif()

# Build example application if desired
if (NANOGUI_BUILD_EXAMPLES)
  add_executable(example1      src/example1.cpp)
  add_executable(example2      src/example2.cpp)
  add_executable(example3      src/example3.cpp)
  add_executable(example4      src/example4.cpp)
  add_executable(example_icons src/example_icons.cpp)

  target_link_libraries(example1      nanogui)
  target_link_libraries(example2      nanogui)
  target_link_libraries(example3      nanogui ${opengl_library})
  target_link_libraries(example4      nanogui)
  target_link_libraries(example_icons nanogui)

  # Copy icons for example application
  file(COPY resources/icons DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()