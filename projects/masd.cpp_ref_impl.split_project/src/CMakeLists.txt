set(files "")
file(GLOB_RECURSE files RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(masd_cpp_ref_impl_split_project STATIC ${files})
set_target_properties(masd_cpp_ref_impl_split_project PROPERTIES
    OUTPUT_NAME masd_cpp_ref_impl_split_project)

install(TARGETS masd_cpp_ref_impl_split_project ARCHIVE DESTINATION lib COMPONENT libraries)
