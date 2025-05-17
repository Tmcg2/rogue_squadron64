#!/bin/bash

#
# m2c_helper.sh
# Utility to aid in the generation of m2c output for specific functions
#
# example usages:
#  m2c_helper.sh cinematic_overlay func_800AAC18
#  m2c_helper.sh main audio_init
#
# It may take a while for either run to complete as including binary data
#   from .incbin directives is a bit slow
#

# Parent directory that function specific contexts will be placed/found in
CONTEXT_DIR="m2c_output"

# Context for all the non-function-specific stuff (type definitions, function prototypes, etc.)
COMMON_CONTEXT="ctx.c"
# Extra options when generating the function specific context
CONTEXT_M2C_OPTS="--stack-structs --zfill-constants -t mips-gcc-c"

# Directory where the m2c program can be found
M2C_DIR="../mips_to_c"
# Collect the SHA1 sum of the commit m2c is checked out too
pushd "${M2C_DIR}" > /dev/null
M2C_SHA="$(git rev-parse HEAD)"
popd > /dev/null

OVERLAY="$1"
FUNCTION="$2"

if ! ASSEMBLY_FILE=$(grep -rl "glabel ${FUNCTION}" ./asm/${OVERLAY}); then
    echo "Could not find ${FUNCTION} anywhere in ./asm/${OVERLAY}"
    exit 1
fi

DATA_FILES=$(find ./asm/data/${OVERLAY} -type f -name "*.s")

OUTPUT_DIR="./m2c_output/${OVERLAY}"
mkdir -p "${OUTPUT_DIR}"

${M2C_DIR}/m2c.py           \
${DATA_FILES}               \
${ASSEMBLY_FILE}            \
${CONTEXT_M2C_OPTS}         \
--context ${COMMON_CONTEXT} \
-f ${FUNCTION} > "${OUTPUT_DIR}/${FUNCTION}.c" 2>&1
