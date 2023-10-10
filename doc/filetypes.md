# File Types
If you look at the 'include' section, you may notice things like %MANDATORY% and %PRIVATE%
These are called filetypes, and have special implications
They must have % on either side of the type, and must come before the filename
They can be used on phih or h files
If it is used on an h file, macros will be defined as so:
```
/* # PHILO MACRO LIST #
 * #whitelist {"ex.phic", "ex0.phic"}
 * #
 */
```
- %MANDATORY% indicates that the file will be included, no matter if it is defined in the file as included or not.
In user files, %MANDATORY% will be included in every file in the directory, and if you want it in every file, move it to the include/header section of the compiler
- %PRIVATE% allows only for a specific set of files allowed, defined with the #whitelist macro
