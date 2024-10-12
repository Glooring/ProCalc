import os
import shutil

def remove_paths_from_cleanup_file(base_folder, cleanup_file):
    """Removes the files and directories listed in cleanup_file from the base_folder."""
    
    # Normalize the base folder path
    base_folder = os.path.abspath(os.path.normpath(base_folder))
    
    # Read the cleanup file
    with open(cleanup_file, 'r', encoding='utf-8') as file:
        paths_to_remove = file.readlines()

    # Process each path from cleanup_files.txt
    for relative_path in paths_to_remove:
        # Clean up the relative path
        relative_path = relative_path.strip()
        full_path = os.path.join(base_folder, relative_path)

        # Debug: Show the full path being processed
        print(f"[DEBUG] Processing: {full_path}")

        # Check if it's a file or directory and delete it
        try:
            if os.path.isfile(full_path):
                os.remove(full_path)
                print(f"[INFO] File removed: {full_path}")
            elif os.path.isdir(full_path):
                shutil.rmtree(full_path)
                print(f"[INFO] Directory removed: {full_path}")
            else:
                print(f"[WARNING] Path does not exist: {full_path}")
        except Exception as e:
            print(f"[ERROR] Failed to remove {full_path}: {e}")

def remove_empty_directories(folder):
    """Recursively remove empty directories, including nested empty folders."""
    for dirpath, dirnames, filenames in os.walk(folder, topdown=False):
        # Only try to remove if directory is empty
        if not dirnames and not filenames:
            try:
                os.rmdir(dirpath)
                print(f"[INFO] Empty directory removed: {dirpath}")
            except Exception as e:
                print(f"[ERROR] Failed to remove directory {dirpath}: {e}")

def remove_all_empty_directories(base_folder):
    """Recursively remove all empty directories in the base_folder, even if nested."""
    for dirpath, dirnames, filenames in os.walk(base_folder, topdown=False):
        # This time we remove the directories after checking that everything inside is empty
        if not os.listdir(dirpath):  # If the directory is empty
            try:
                os.rmdir(dirpath)
                print(f"[INFO] Removed empty directory: {dirpath}")
            except OSError as e:
                print(f"[ERROR] Could not remove {dirpath}: {e}")

if __name__ == "__main__":
    # Get input folder and cleanup_files.txt path from the user
    input_folder = input("Enter the path to the input folder: ").strip().strip('"')
    cleanup_file_path = input("Enter the path to cleanup_files.txt: ").strip().strip('"')

    # Call the function to remove files
    remove_paths_from_cleanup_file(input_folder, cleanup_file_path)

    # After removing files, remove empty directories recursively
    remove_all_empty_directories(input_folder)
