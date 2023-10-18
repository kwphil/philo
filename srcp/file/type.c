const char *filetypes[] = {
                           "%PRIVATE%",
                           "%MANDATORY%"
                          };

int getFileType(char *filename) {
    if(!strmatch(fileExtension(filename), "phih") && !strmatch(fileExtension(filename), "h")) {
        bError = true;
        sError = "Compiler Error: tried to assign filetype to non-header file";
        return -1;
    }

    
}