#!/bin/bash

#
# m2c_helper.sh
# Utility to aid in the generation of m2c output for specific functions
#
# example usages:
#  m2c_helper.sh code_80091750 func_800AAC18
#  m2c_helper.sh audio/load audio_init
#
# Be sure to set DISASSEMBLY_FILE to a filename you are comfortable with.
#   Defaulted to function_disassembly.c
#
# It's expected that the utility will be ran twice for any given function.
# The first run will create a context file specific to the target function
# The second run will create the full m2c output for the function,
#   assuming the appropriate function specific context file found.
#
# 99.9% of the time you will only use the function specific context file to give names
#   to the function arguments. Even then, you don't HAVE to do that. The file can be
#   empty if you want.
# As long as its contents are acceptable to m2c, do whatever you want to it.
#
# It may take a while for either run to complete as including all binary data
#   from .incbin directives is a bit slow
#

# Parent directory for all the non-matching function assembly files
ASM_DIR="asm"
# Parent directory that function specific contexts will be placed/found in
CONTEXT_DIR="m2c_output"

# Expand the data/**.s glob into an array.
DATA_FILES=(asm/data/**.rodata.s asm/data/**.data.s)
# Un-array the file list
DATA_FILES="${DATA_FILES[@]}"
DATA_FILES_EXCLUDE=""
# Use bash variable expansion to remove each file-to-exclude from the DATA_FILES string
for file in $DATA_FILES_EXCLUDE; do
	DATA_FILES="${DATA_FILES//$file/}"
done

# Context for all the non-function-specific stuff (type definitions, function prototypes, etc.)
COMMON_CONTEXT="ctx.c"
# Extra options when generating the function specific context
CONTEXT_M2C_OPTS="--stack-structs --zfill-constants -t mips-gcc-c"
# Extra options when generating the function disassembly
DISASSEMBLY_M2C_OPTS="--zfill-constants"
# Directories to search when a .incbin line is encountered in a data file
INCBIN_OPTS=""
# File that the final disassembly output will be placed. Can be named whatever you want
DISASSEMBLY_FILE=""

# Directory where the m2c program can be found
M2C_DIR="../mips_to_c"
# Collect the SHA1 sum of the commit m2c is checked out too
pushd "${M2C_DIR}" > /dev/null
M2C_SHA="$(git rev-parse HEAD)"
popd > /dev/null

asm_file="$1"
function="$2"

make_function_context () {
	echo "$(${M2C_DIR}/m2c.py \
		-f $2 \
		${ASM_DIR}/$1.s \
		${DATA_FILES} \
		${INCBIN_OPTS} \
		${CONTEXT_M2C_OPTS} \
		--context ${COMMON_CONTEXT})" > "${CONTEXT_DIR}/$1/$2.c" 2>&1
}

make_function_disassembly () {
    echo "#ifdef MIPS_TO_C";
    echo "//generated by m2c commit ${M2C_SHA} on $(date +%b-%d-%Y)";
    ${M2C_DIR}/m2c.py \
    	${ASM_DIR}/${asm_file}/${function}.s \
		${DATA_FILES} \
		${INCBIN_OPTS} \
		${DISASSEMBLY_M2C_OPTS} \
	    --context ${COMMON_CONTEXT} --context ${CONTEXT_DIR}/${asm_file}/${function}.c
    echo "#else";
    echo "GLOBAL_ASM(\"${ASM_DIR}/${asm_file}/${function}.s\")";
    echo "#endif"
}

mkdir -p "${CONTEXT_DIR}/${asm_file}"

# If there is a function specific context file, create the full disassembly
# Otherwise, create the function specific context file
# if [[ -f "${CONTEXT_DIR}/${asm_file}/${function}.c" ]]; then
# 	echo "$(make_function_disassembly ${asm_file} ${function})" > "${DISASSEMBLY_FILE}" 2>&1
# else
# 	make_function_context ${asm_file} ${function}
# fi

make_function_context ${asm_file} ${function}