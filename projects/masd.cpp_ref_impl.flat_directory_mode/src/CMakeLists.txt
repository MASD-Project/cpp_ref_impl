set(files "")
file(GLOB_RECURSE files RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(masd_cpp_ref_impl_flat_directory_mode STATIC ${files})
set_target_properties(masd_cpp_ref_impl_flat_directory_mode PROPERTIES
    OUTPUT_NAME masd_cpp_ref_impl_flat_directory_mode)

install(TARGETS masd_cpp_ref_impl_flat_directory_mode ARCHIVE DESTINATION lib COMPONENT libraries)
