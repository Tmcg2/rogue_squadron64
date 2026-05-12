# classify_funcs.awk — categorize unnamed recompiled C functions by the
# objective-system primitives they call. Used during the rename grind to
# spot per-level handler patterns (mission-start, dialogue, progress,
# state-transition, etc.) without reading each function body.
#
# Usage:
#   awk -f classify_funcs.awk /path/to/funcs_NN.c
#
# Output (one line per unnamed func_*):
#   func_XXXXXXXX : <line> : voice=N obj_bool=N obj_count=N timer=N hud=N damage=N complete=N
#
# Interpretation cheatsheet (see memory entry: project_objective_classify_pattern):
#   voice=8 + obj_bool=2 + timer + hud + complete = lvN_startMissionAndBriefing
#   obj_bool=10                                   = lvN_setMissionBooleansMass
#   voice + obj_bool + count + complete           = lvN_completeAndProgressObjective
#   voice + obj_count                             = lvN_progressWithDialogue
#   damage only                                   = lvN_dealDamageHook
#   voice only (count=1-4)                        = lvN_dialogueSequence
#
# Filter for non-trivial entries with:
#   awk '!/voice=0 obj_bool=0 obj_count=0 timer=0 hud=0 damage=0 complete=0$/'

/^RECOMP_FUNC void / {
  if (curr_name && curr_name ~ /^func_/) {
    print curr_name " : " curr_line " : voice=" v_count " obj_bool=" b_count " obj_count=" c_count " timer=" t_count " hud=" h_count " damage=" d_count " complete=" a_count
  }
  curr_name = $3; gsub(/\(uint8_t\*/, "", curr_name); curr_line = NR
  v_count=0; b_count=0; c_count=0; t_count=0; h_count=0; d_count=0; a_count=0
}
/playObjectiveVoiceLine/{v_count++}
/setObjectiveBoolean|getObjectiveBoolean/{b_count++}
/setObjectiveCount|getObjectiveCount|increaseObjectiveCount/{c_count++}
/addTimerHandle|getObjectiveTimer/{t_count++}
/setHudFlagBit40/{h_count++}
/dealDamage/{d_count++}
/activateObjectiveComplete/{a_count++}
END {
  if (curr_name && curr_name ~ /^func_/) {
    print curr_name " : " curr_line " : voice=" v_count " obj_bool=" b_count " obj_count=" c_count " timer=" t_count " hud=" h_count " damage=" d_count " complete=" a_count
  }
}
