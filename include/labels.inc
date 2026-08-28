# This file is used by the original compiler/assembler.
# Defines the expected assembly macros.

# A function symbol.
.macro .globl label, visibility=global
    .\visibility \label
    .type \label, @function
    \label:
        .ent \label
.endm

# The end of a function symbol.
.macro .end label
    .size \label, . - \label
    .end \label
.endm

# A label referenced by an error handler table.
.macro ehlabel label, visibility=global
    .\visibility \label
    \label:
.endm



