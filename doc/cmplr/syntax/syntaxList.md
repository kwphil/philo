## Using syntax lists
If you are creating a new operator, keyword, or others, the process is the same.

- Add it on the operator list.
- Add the syntax to the list.

The syntax list has its own syntax to use.
- ^ Indicates the operator/keyword
- \0 Indicates to skip it, because the keyword/operator is defined in another seciton
- ? Indicates that the section is unnecessary, and can be included, but does not have to.
-  "" Anything inside the quotes is a group, and will be affected by ? as a whole
- // Anything inside the slashes is considered a comment
- '' Anything inside is considered a type, say a expr, or etc.

#### Using ''
- ##### + Used to specifically include specific types of the return
- ##### - Used to exclude specific types of the return
