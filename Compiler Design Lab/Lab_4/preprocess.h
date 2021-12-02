int process(){
	FILE *fin = fopen("space_output.c", "r");
	FILE *fout = fopen("process_output.c", "w+");
	char c = 0;
	char buffer[100];
	buffer[0] = '\0';
	int i = 0;
	char *includeStr = "include", *defineStr = "define", *mainStr = "main";
	int mainFlag = 0;
	while(c != EOF){
		c = fgetc(fin);
		if(c == '#' && mainFlag == 0){
			while(c!=' '){
				c = fgetc(fin);
				buffer[i++] = c;
			}
			buffer[i] = '\0';
			if(strstr(buffer, includeStr)!=NULL || strstr(buffer, defineStr)!=NULL){
				while(c!='\n'){
					c = fgetc(fin);
				}
			}
			else{
				fputc('#', fout);
				for(int j = 0; j<i; j++){
					fputc(buffer[j], fout);
				}
				while(c!='\n'){
					c = fgetc(fin);
					fputc(c, fout);
				}
			}
			i = 0;
			buffer[0]= '\0';
		}
		else{
			if(mainFlag == 0){
				buffer[i++] = c;
				buffer[i] = '\0';
				if(strstr(buffer, mainStr)!=NULL){
					mainFlag = 1;
				}
			}
			if(c == ' ' || c == '\n'){
				buffer[0] = '\0';
				i = 0;
			}
			fputc(c, fout);
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}