
########################################################################################################################
# Global Settings                                                                                                      #
########################################################################################################################
# project name
set(project_name "she_ini_parse")
PROJECT(${project_name}
        VERSION      0.0.1
        LANGUAGES    CXX
        )

# [Release] or [Debug] or [MinSizeRel]
set(compilation_options "Debug")

# src target
set(library_static_name "${PROJECT_NAME}_static")
set(library_dynamic_name "${PROJECT_NAME}_dynamic")
set(generate_lib ON)

# test target
set(test_name "${project_name}_test")
set(generate_test ON)

# exec target
set(exec_name "${project_name}_exec")
set(generate_exec ON)


