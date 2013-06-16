#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout<<"provide the file name\n";
		return 0;
	}
	if(argc >2)
	{
		cout<<"more than one files provided\n";
		return 0;
	}
	char f_name[100];
	strcpy(f_name,argv[1]);
	/*test whether the file is a velid c file or not*/
	{
		FILE *out = fopen("out.txt","w");
		fclose(out);
		int len = strlen(argv[1]);
	//	cout<<argv[1]<<endl;
	//	cout<<argv[1][len-2]<<endl;
		if(strncmp(argv[1]+len-2,".c",2)){
			cout<<"file is not a valid c file\n";
			return 0;
		}
	}
	char command[100] = "gcc ";
	strcat(command,f_name);
	strcat(command," 2> out.txt");
	system(command);             //compiles the file
	/*************************************************/
	FILE *out;
	out = fopen("out.txt","r");
	int index=0;
	string temp_file_str;
	while(!feof(out)){
		temp_file_str += fgetc(out);
		if(++index > 500){
			temp_file_str+= '\0';
			break;
		}
	}
	fclose(out); //file out.txt closed with contents written
	int len = index;
	index = 0;
	while(index<len){
		if(temp_file_str[index] == 'e'){
			if(temp_file_str.compare(index,6,"error:"))
			{
				cout<<"************ DUH!!!!! COMPILATION ERROR ************"<<endl;
				return 0;
			}
		}
		index++;
	}
	/************ empties the file********************/
	out = fopen("out.txt","w");
	fclose(out);
	/*************************************************/
	strcpy(command,"./a.out <input.txt >out.txt");
	system(command);
	FILE *usr_prog_output = fopen("out.txt","r");
	FILE *expected_output = fopen("output.txt","r");
	while(!feof(usr_prog_output) || !feof(expected_output)){
		char usr[1000],expected[1000];
		fscanf(usr_prog_output,"%s\n",usr);
		fscanf(expected_output,"%s\n",expected);
		if(strcmp(usr,expected)!=0){
			cout<<"**************** WRONG ANSWER ****************"<<endl;
			cout<<"Expected answer: "<<expected<<'\n';
			cout<<"Your answer: "<<usr<<'\n';
			cout<<"At input:"<<endl;
			//TODO at input
			return 0;
		}
	}
	fclose(usr_prog_output);
	fclose(expected_output);
	cout<<"CONGRATS!!!! ACCEPTED SOLUTION"<<'\n';


return 0;
}
