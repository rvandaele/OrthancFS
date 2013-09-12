#include "../include/orthanc_hash.h"
#include <stdio.h>

void add_patient(char * ofs_patient_name, int o_pid){
	struct opair * ppair = Malloc(struct opair,1);
	strncpy(ppair->rname,ofs_patient_name,MAX_CHAR_HASH);
	ppair->o_id = o_pid;
	HASH_ADD_STR(hash_patient,rname,ppair);
}

void add_study(char * ofs_study_name, int o_stid){
	struct opair * stpair = Malloc(struct opair,1);
	strncpy(stpair->rname,ofs_study_name,MAX_CHAR_HASH);
	stpair->o_id=o_stid;
	HASH_ADD_STR(hash_study,rname,stpair);
}

void add_serie(char * ofs_serie_name, int o_seid){
	struct opair * sepair = Malloc(struct opair,1);
	strncpy(sepair->rname,ofs_serie_name,MAX_CHAR_HASH);
	sepair->o_id=o_seid;
	HASH_ADD_STR(hash_serie,rname,sepair);
}

void add_instance(char * ofs_instance_name, int o_iid){
	struct opair * ipair = Malloc(struct opair,1);
	strncpy(ipair->rname,ofs_instance_name,MAX_CHAR_HASH);
	ipair->o_id=o_iid;
	HASH_ADD_STR(hash_instance,rname,ipair);
}

int get_o_pid(char * ofs_pid){
	struct opair * p = Malloc(struct opair,1);
	HASH_FIND_STR(hash_patient,ofs_pid,p);
	if(p==NULL)return -1;
	return p->o_id;
}

int get_o_stid(char * ofs_stid){
	struct opair * st;
	HASH_FIND_STR(hash_study,ofs_stid,st);
	if(st==NULL)return -1;
	return st->o_id;
}

int get_o_seid(char * ofs_seid){
	struct opair * se;
	HASH_FIND_STR(hash_serie,ofs_seid,se);
	if(se==NULL)return -1;
	return se->o_id;
}

int get_o_iid(char * ofs_iid){
	struct opair * i;
	HASH_FIND_STR(hash_instance,ofs_iid,i);
	if(i==NULL)return -1;
	return i->o_id;
}

/*int main(int argc, char * argv[]){
	char * yourmom = "/mobama";
	char * yourmom2 = "/42";
	add_patient("/bobama","/42");
	add_study("/bobama/irm","/42/666");
	add_serie("/bobama/irm/sa","/42/666/1024");
	add_instance("/bobama/irm/sa/nose.dcm","/42/666/1024/512");
	char * pid = get_o_pid(yourmom);
	if(pid==NULL)
		printf("This does not exist\n");
	else
		printf("Identifier : %s\n",pid);
	return EXIT_SUCCESS;
}*/