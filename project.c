#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
//유준열
typedef struct movie {
	int serial_number;
	char *title;
	char *genre;
	char *director;
	char *year;
	char *time;
	char *actors;
	struct movie *next;
}movie;

typedef struct director {
	int serial_number;
	char *name;
	char *sex;
	char *birth;
	char *best_movies;
	struct director *next;
}director;

typedef struct actor {
	int serial_number;
	char *name;
	char *sex;
	char *birth;
	char *best_movies;
	struct actor *next;
}actor;

movie *root_movie;
director *root_director;
actor *root_actor;
int root_m = 0, root_d = 0, root_a = 0;

void add_movie(movie *m){
	movie *temp_mp;
	char *temp;
	m = (movie *)malloc(sizeof(movie));	
	temp = (char *)malloc(sizeof(char) * 200);
	printf("title > ");
	scanf("%s", temp);
	m->title = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(m->title, temp);
	printf("%s\n", m->title);

	printf("genre > ");
	scanf("%s", temp);
	m->genre = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(m->genre, temp);
	
	printf("director > ");
	scanf("%s", temp);
	m->director = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(m->director, temp);

	printf("year > ");
	scanf("%s", temp);
	m->year = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(m->year, temp);

	printf("time > ");
	scanf("%s", temp);
	m->time = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(m->time, temp);
	
	printf("actors > ");
	scanf("%s", temp);
	m->actors = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(m->actors, temp);

	if (root_m == 0) {
		printf("넣음\n");
		root_movie = m;
		root_m = 1;
	}
	m->next = (movie *)malloc(sizeof(movie));
	m = m->next;
}

void add_director(director *d) {
	director *temp_dp;
	char *temp;
	d = (director *)malloc(sizeof(director));
	temp = (char *)malloc(sizeof(char) * 200);
	printf("name > ");
	scanf("%s", temp);
	d->name = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(d->name, temp);

	printf("sex > ");
	scanf("%s", temp);
	d->sex = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(d->sex, temp);

	printf("birth > ");
	scanf("%s", temp);
	d->birth = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(d->birth, temp);

	printf("best_movies > ");
	scanf("%s", temp);
	d->best_movies = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(d->best_movies, temp);
}

void add_actor(actor *a) {
	actor *temp_ap;
	char *temp;
	a = (actor *)malloc(sizeof(actor));
	temp = (char *)malloc(sizeof(char) * 200);
	printf("name > ");
	scanf("%s", temp);
	a->name = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(a->name, temp);
	strcat(a->name, "\0");

	printf("sex > ");
	scanf("%s", temp);
	a->sex = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(a->sex, temp);
	strcat(a->sex, "\0");

	printf("birth > ");
	scanf("%s", temp);
	a->birth = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(a->birth, temp);
	strcat(a->birth, "\0");

	printf("best_movies > ");
	scanf("%s", temp);
	a->best_movies = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(a->best_movies, temp);
}


int main(void) {
	movie *m;
	actor *a;
	director *d;

	char *input_words;
	input_words = (char *)malloc(sizeof(char) * 20);
	printf(">> Welcome to My Movie <<\n");
	printf("File Loading.....\n");
	printf("You can use add, update, delete, search, sort, save, end commands.\n");
	while (1) {
		printf("(movie) ");
		gets(input_words);
		printf("input words : %s\n", input_words);
		if (!strcmp(input_words, "add m"))
			add_movie(m);
		else if (!strcmp(input_words, "add d"))
			add_director(d);
		else if (!strcmp(input_words, "add a"))
			add_actor(a);
	}
	return 0;
}
