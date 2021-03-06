set(NOARCH_LIB_DIR ${CMAKE_SOURCE_DIR}/libs/noarch_c_lib)

# Make sure that git submodule is initialized and updated
if (NOT EXISTS "${NOARCH_LIB_DIR}")
  message(FATAL_ERROR "noarch_c_lib submodule not found. Initialize with 'git submodule update --init' in the source directory")
endif()

include_directories(
    ${NOARCH_LIB_DIR}/
)

set(NOARCH_LIB_SRC
    # ${NOARCH_LIB_DIR}/btn_lib.c
    ${NOARCH_LIB_DIR}/rotary_cont_pot.c
    ${NOARCH_LIB_DIR}/rotary_enc_pot.c
)