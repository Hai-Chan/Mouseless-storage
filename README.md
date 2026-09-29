## 1. Program connect to a separate text file

- User can use the program to connect to the text file and add/subtract content as will
- Since it's a text file, user can also freely manipulate its content, just make sure to respect the format in order for the program to read.

## 2. Inventory Backup Script

A simple Bash script to automate backing up your inventory data with a precise timestamp.

## Features
- Creates a `backups/` directory automatically if it does not exist.
- Copies `inventory.txt` into the backup folder.
-  Renames the file using the current date and time (`YYYYMMDD_HHMMSS`).
	![backup](images/backup.png)
- Prints a clear success timestamp.

## How to Use

1. Make sure you have your `inventory.txt` file in the same directory as the script.
2. Give the script execution permission (run this only once):
   ```bash
   chmod +x backup.sh
   ```
3. Run the script whenever you need a backup:
   ```bash
   ./backup.sh
   ```

## 3. Project Structure
```text
├── Makefile	   # Makefile script to be used later on instead of manually compile the code after modification
├── backup.sh      # The automation script
├── store.c	   # Main program file
├── inventory.txt  # Your main inventory file
├── .gitignore     # Ignores the backups/ folder
└── backups/       # Generated backups (ignored by Git)
```
