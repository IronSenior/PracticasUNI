//Jose Marquez Doblas
//i72madoj@uco.es

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

/* Libraries for structs passwd and group */
#include <pwd.h>
#include <grp.h>

void printUserInfo(struct passwd *pw);
void printGroupInfo(struct group *gr);
void printAllInfo(char *userName, struct passwd *pw, struct group *gr);
void printSystemGroups(struct group *gr);
void printHelpMessage();

int main (int argc, char **argv)
{
    static struct option long_options[] = {
		{"username", required_argument, 0, 'u'},
		{"useruid", required_argument, 0, 'i'},
		{"groupname", required_argument, 0, 'g'},
		{"groupuid", required_argument, 0, 'd'},
		{"allgroups", no_argument, 0, 's'},
		{"allinfo", required_argument, 0, 'a'},
		{"bactive", no_argument, 0, 'b'},
		{"help", no_argument, 0, 'h'},
		{0, 0, 0, 0}
    };

    char *userName = NULL;
    char *userID = NULL;
    char *groupName = NULL;
    char *groupID = NULL;
    char *cvalue = NULL;
    int index;
    int c;

    //Desabilita los errores
    //opterr = 0; 

    struct passwd *pw = NULL;
    struct group *gr = NULL;

    if(argc == 1) {
		pw = getpwuid(getuid()); //Es mejor que getlogin()
        gr = getgrgid(getgid());
		if((pw == NULL)||(gr == NULL)){
			perror("No se pudo obtener la informacion del usuario");
			exit(-1);
		}
		printUserInfo(pw);
        printf("\n");
        printGroupInfo(gr);
    }

    while ((c = getopt_long(argc, argv, "u:i:g:d:sa:bh", long_options, &index)) != -1)
    {     
        switch (c)
        {
		    case 'u':
		        userName = optarg;
                pw = getpwnam(userName);
                if (pw == NULL){
                    fprintf(stderr, "That user does not exists");
                    exit(-1);
                }
                printUserInfo(pw);
		        break;

		    case 'i':
		        userID = optarg;
                pw = getpwuid(atoi(userID));
                if (pw == NULL){
                    fprintf(stderr, "That user does not exists");
                    exit(-1);
                }
                printUserInfo(pw);
		        break;

		    case 'g':
		        groupName = optarg;
                gr = getgrnam(groupName);
                if (gr == NULL){
                    fprintf(stderr, "That group does not exists");
                    exit(-1);
                }
                printGroupInfo(gr);
		        break;

		    case 'd':
		        groupID = optarg;
                gr = getgrgid(atoi(groupID));
                if (gr == NULL){
                    fprintf(stderr, "That group does not exists");
                    exit(-1);
                }
                printGroupInfo(gr);
		        break;

		    case 's':
                printSystemGroups(gr);
		        break;

            case 'a':
                userName = optarg;
                printAllInfo(userName, pw, gr);
                break;

            case 'b':
                pw = getpwuid(getuid()); //Es mejor que getlogin()
                gr = getgrgid(getgid());
                if((pw == NULL)||(gr == NULL)){
                    perror("No se pudo obtener la informacion del usuario");
                    exit(-1);
                }
                printUserInfo(pw);
                printf("\n");
                printGroupInfo(gr);
                break;
            
            case 'h':
                printHelpMessage();
                break;

		     case '?': 
                printHelpMessage();
                break;

		     default:
		         abort ();
        }
    }


    for (index = optind; index < argc; index++)
        printf ("Argumento \"%s\" de la línea de comandos que NO ES UNA OPCIÓN.\n\n", argv[index]);

    if(cvalue==NULL)
        cvalue="ValorPorDefecto";
    
    return 0;
}


void printUserInfo(struct passwd *pw) {
	printf("Nombre de usuario: %s\n", pw->pw_gecos);
    printf("Identificador de usuario: %d\n", pw->pw_uid);
	printf("Contraseña: %s\n", pw->pw_passwd);
	printf("Login de usuario: %s\n", pw->pw_name);
	printf("Carpeta inicio: %s\n", pw->pw_dir);
	printf("ID de grupo principal: %d\n", pw->pw_gid);
}

void printGroupInfo(struct group *gr) {
	printf("Nombre: %s\n", gr->gr_name);
    printf("Identificador del grupo: %d\n", gr->gr_gid);
	printf("Contraseña: %s\n", gr->gr_passwd);
	printf("Miembros del grupo: %s\n", *(gr->gr_mem)); 
}

void printAllInfo(char *userName, struct passwd *pw, struct group *gr){
    pw = getpwnam(userName);
    if(pw == NULL) {
        fprintf(stderr, "El usuario no existe");
        exit(-1);
    }
    gr = getgrgid(pw->pw_gid);
    printUserInfo(pw);
    printf("\n");
    printGroupInfo(gr);
}

void printSystemGroups(struct group *gr) {
	char line[50];
	char *groupName = NULL;
   	
	FILE *group_file;
	group_file = fopen("/etc/group", "r");

	while((fgets(line, 50, group_file)) != NULL) {
		groupName = strtok(line, ":");
		gr = getgrnam(groupName);
		printGroupInfo(gr);
        printf("\n");
	}
	fclose(group_file);
}

void printHelpMessage(){
	printf("    -h, --help 						Muestra este mensaje\n");
	printf("    -u, --username <user_login>		Muestra la información del usuario\n");
	printf("    -i, --useruid <user_id>			Muestra la información del usuario\n");
	printf("    -g, --groupname <group_name>	Muestra la información del grupo\n");
	printf("    -d, --groupuid <group_id>		Muestra la información del grupo\n");
	printf("    -s, --allgroups					Muestra la información de todos los grupos del sistema\n");
	printf("    -a, --allinfo <user_login>		Muestra la información del grupo y del usuario\n");
	printf("    -b, --bactive					Muestra la información del grupo y del usuario\n");
}