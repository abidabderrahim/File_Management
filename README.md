# File Management Program

## Overview

This C program organizes files in a specified directory by their file format. It creates folders based on file extensions (e.g., `txt`, `png`, `csv`) and moves files into the corresponding folders. This helps in keeping the directory tidy and well-organized.

## Features

- **Organize Files by Format**: Automatically sorts files into folders named after their extensions.
- **Handles Multiple Formats**: Supports any file format by dynamically creating folders as needed.
- **Error Handling**: Includes basic error handling to manage cases where directories or files cannot be processed.

## How It Works

1. The program takes a directory path as input.
2. It scans through all the files in the specified directory.
3. For each file, it checks the file extension.
4. If the extension is recognized, it creates a corresponding folder (if it doesn't already exist).
5. The file is then moved to the appropriate folder.

## Requirements

- A UNIX-like operating system (Linux, macOS).
- A C compiler like `gcc`.

## Compilation

To compile the program, open a terminal and run:

```sh
gcc -o file_manager file_manager.c
