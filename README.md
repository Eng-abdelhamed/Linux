#####  Command Source Code CP
# Syntax 
./cp source_file destination_file

source_file: The file to be copied.
destination_file: The file where the copied content will be stored.

# How It Works
1 - Opens the source file for reading.
2 - Creates (or truncates) the destination file for writing.
3 - Reads data from the source file and writes it to the destination file in chunks.
4 - Closes both files after copying.

# Compilation
 gcc cp.c -o cp

# Error Handling
If the source file does not exist, an error message is displayed.
