#2. Inventory Backup Script

A simple Bash script to automate backing up your inventory data with a precise timestamp.

## Features
- Creates a `backups/` directory automatically if it does not exist.
- Copies `inventory.txt` into the backup folder.
- Renames the file using the current date and time (`YYYYMMDD_HHMMSS`).
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

## Project Structure
```text
├── backup.sh      # The automation script
├── inventory.txt  # Your main inventory file (tracked by Git)
├── .gitignore     # Ignores the backups/ folder
└── backups/       # Generated backups (ignored by Git)
```
