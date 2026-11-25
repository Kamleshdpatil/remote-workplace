#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

// Function to check if a string is a purely numeric PID
int is_pid_folder(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isdigit(name[i])) return 0;
    }
    return 1;
}

// Function to get the process name/command line
void print_process_name(const char *pid) {
    char path[256];
    char cmdline[256] = "Unknown";
    snprintf(path, sizeof(path), "/proc/%s/cmdline", pid);
    
    FILE *f = fopen(path, "r");
    if (f) {
        if (fgets(cmdline, sizeof(cmdline), f) != NULL) {
            // cmdline separates args with null bytes; clean them for printing
            for(int i=0; i<sizeof(cmdline) && cmdline[i] != '\0'; i++) {
                if (cmdline[i] == '\0' && cmdline[i+1] != '\0') cmdline[i] = ' ';
            }
        }
        fclose(f);
    }
    printf("\n==================================================\n");
    printf("PROCESS PID: %s | COMMAND: %s\n", pid, cmdline);
    printf("==================================================\n");
}

// Function to scan and print all open files/resources for a PID
void print_open_files(const char *pid) {
    char fd_dir_path[256];
    snprintf(fd_dir_path, sizeof(fd_dir_path), "/proc/%s/fd", pid);
    
    DIR *dir = opendir(fd_dir_path);
    if (!dir) {
        perror("  [Error] Could not open fd directory (Permission Denied)");
        return;
    }

    struct dirent *entry;
    char link_path[512];
    char real_path[512];

    printf("  Open Files & Resources:\n");
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build the full path to the symlink (e.g., /proc/1234/fd/0)
        snprintf(link_path, sizeof(link_path), "%s/%s", fd_dir_path, entry->d_name);
        
        // System Call: Resolve where the File Descriptor points
        ssize_t len = readlink(link_path, real_path, sizeof(real_path) - 1);
        if (len != -1) {
            real_path[len] = '\0'; // Null-terminate the string
            printf("    -> FD %s: %s\n", entry->d_name, real_path);
        }
    }
    closedir(dir);
}

int main() {
    // Open the root /proc directory
    DIR *proc_dir = opendir("/proc");
    if (!proc_dir) {
        perror("Failed to open /proc");
        return 1;
    }

    struct dirent *entry;
    // Iterate through all entries in /proc
    while ((entry = readdir(proc_dir)) != NULL) {
        // Filter out non-PID folders
        if (is_pid_folder(entry->d_name)) {
            print_process_name(entry->d_name);
            print_open_files(entry->d_name);
        }
    }

    closedir(proc_dir);
    return 0;
}
