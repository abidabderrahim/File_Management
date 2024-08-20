#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

char *get_file_extension(const char *filename){
	char *dot = strrchr(filename, '.');
	if (!dot || dot == filename) return "";
	return dot + 1;
}

// strrchr function for search for last occurence character .

void create_directory(const char *dir_name){
	struct stat st = {0}; // initialized struct to zero .
	if (stat(dir_name, &st) == -1){
		mkdir(dir_name, 0700);
	}
}

// stat function check if the directory exists .
// mkdir create directory with permissions 0700 .

void move_file_to_folder(const char *filename, const char *ext){
	char dest_folder[256];
	snprintf(dest_folder, sizeof(dest_folder), "./%s", ext);
	create_directory(dest_folder);

	char dest_path[512];
	snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_folder, filename);

	if(rename(filename, dest_path) != 0){
		perror("Error Moving File.");
	}
}

// snprintf 1 : format the folder name as ./type .
// snprintf 2 : format the path where the file will be moved .

int main(int argc, char **argv){

	if(argc != 2){
		fprintf(stderr, "Usage : %s <directory_path>\n", argv[0]);
		return 1;
	}

	DIR *dir;
	struct dirent *entry;

	dir = opendir(argv[1]);
	if (dir == NULL) {
		perror("Unable To Open Directory");
		return 1;
	}

	while ((entry = readdir(dir)) != NULL){
		if(entry->d_type == DT_REG){
			char *ext = get_file_extension(entry->d_name);
			if(strlen(ext) > 0){
				move_file_to_folder(entry->d_name, ext);
			}
		}
	}

	closedir(dir);
	return 0;
}

// opendir function for open directory .
