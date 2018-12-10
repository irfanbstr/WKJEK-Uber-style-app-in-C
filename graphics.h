
void IMG(char *filename)	//fungsi print gambar dari file .txt dengan variabel pointer
{	
	char *dir[80];			//variabel pointer dir untuk directory file
	strcpy(dir, "img/");	//path file berada di assets/"filename.txt"
	strcat(dir, filename);
	strcat(dir, ".txt");
	
    FILE *fptr = NULL;		//inisialisasi file pointer FILE *fptr untuk membuka dan parsing file.
 
    if((fptr = fopen(dir,"r")) == NULL)	//file tidak ditemukan
    {
        fprintf(stderr,"error opening %s. file not found\n",filename);	//error file not found
        return 1; //jalankan program, lewati error
    }
 
    char read_string[MAX_LEN];	//baca string dari file txt dengan maksimum 129 karakter
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)	//baca dengan metode fgets()
        printf("%s",read_string);	//print string yang disimpan dalam variabel read_string
 
    fclose(fptr);	//tutup file pointer
 
    return 0;	//return 0;
}
