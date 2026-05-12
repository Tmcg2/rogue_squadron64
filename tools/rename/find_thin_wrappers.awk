# find_thin_wrappers.awk — identify single-callee thin wrappers
#
# Finds functions that:
#   1. Are <25 lines of recompiled C
#   2. Make exactly one named-function jal call
#
# These are typically register-with-different-constant wrappers (e.g.,
# the voice-line wrappers across funcs_45-48 each call playObjectiveVoiceLine1
# with a different hardcoded voice ID).
#
# Usage:
#   awk -f find_thin_wrappers.awk RecompiledFuncs/funcs_NN.c
#
# Output format:
#   func_XXXXXXXX (NN lines) -> wrappedFunctionName

/^RECOMP_FUNC void / {
  if (curr_name && curr_name ~ /^func_/ && jal_count == 1 && curr_lines < 25 && named_callee != "") {
    print curr_name " (" curr_lines " lines) -> " named_callee
  }
  curr_name = $3
  gsub(/\(uint8_t\*/, "", curr_name)
  curr_lines = 0; jal_count = 0; named_callee = ""
  if ($3 !~ /^func_/) curr_name = ""
  next
}
curr_name { curr_lines++ }
curr_name && /[a-zA-Z_][a-zA-Z0-9_]*\(rdram, ctx\);/ {
  if (match($0, /[ \t]([a-zA-Z_][a-zA-Z0-9_]*)\(rdram, ctx\);/, m)) {
    jal_count++
    if (m[1] !~ /^func_/ && m[1] !~ /^fake_func/) named_callee = m[1]
  }
}
END {
  if (curr_name && curr_name ~ /^func_/ && jal_count == 1 && curr_lines < 25 && named_callee != "") {
    print curr_name " (" curr_lines " lines) -> " named_callee
  }
}
