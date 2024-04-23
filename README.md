# reverse-file-content

This project aims to reverse the file content by using file pointers.

Main c++ `fstream` functions used: 

- `seekg`
- `tellg`
- `put`
- `get`

**Note**: the program does not create a new file instead it modifies the original file.

**To test the program**:

- First run the program and notice the change in `example.txt`
- Run the program again, and notice `example.txt` is back to its original content.