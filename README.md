### Command Source Code
####  First Program  - This program replicates the functionality of the cp command in UNIX, copying a source file to a destination file.

# Syntax 
./cp source_file destination_file
-
source_file: The file to be copied.
destination_file: The file where the copied content will be stored.
-
source_file: The file to be copied.
destination_file: The file where the copied content will be stored.

# How It Works
1 - Opens the source file for reading.
2 - Creates (or truncates) the destination file for writing.
3 - Reads data from the source file and writes it to the destination file in chunks.
4 - Closes both files after copying.

