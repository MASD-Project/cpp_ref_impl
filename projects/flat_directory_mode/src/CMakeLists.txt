set(files "")
file(GLOB_RECURSE files RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set(odb_files "")
file(GLOB_RECURSE odb_files RELATIVE
   "${CMAKE_CURRENT_SOURCE_DIR}/"
   "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx")
set(files ${files} ${odb_files})

add_library(flat_directory_mode STATIC ${files})
set_target_properties(flat_directory_mode PROPERTIES
    OUTPUT_NAME dogen.flat_directory_mode)

install(TARGETS flat_directory_mode ARCHIVE DESTINATION lib COMPONENT libraries)
