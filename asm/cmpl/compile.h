#ifndef ACOMPILE_H
#define ACOMPILE_H

extern funcOrg_t *CMPL_LIST;

//Gets the file list and converts it into an asm_t *
bool asmCompile();
void setCMPL_LIST();

#endif