#ifndef ACOMPILE_H
#define ACOMPILE_H

extern funcOrg_t *CMPL_LIST;
//Sets the values for the CMPL_LIST variable, in order to be used for later
void setCMPL_LIST();

//Gets the file list and converts it into an asm_t *
bool asmCompile();

#endif