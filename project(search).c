#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void add_movie(movie *m) {
	movie *temp_mp;
	char *temp;
	m = (movie *)malloc(sizeof(movie));
	temp = (char *)malloc(sizeof(char) * 200);
	printf("title > ");
	scanf("%s", temp);
	m->title = (char *)malloc(sizeof(char) * strlen(temp));
	strcpy(m->title, temp);

	m = m->next;
}
void search(void) {
	char *option, *search_word, *keyword;
	char *token; // strtok()함수를 위한 변수
	search_word = (char *)malloc(sizeof(char) * 50);// 검색어 길이만큼 동적할당 받는법좀
	option = (char *)malloc(sizeof(char) * 10);
	keyword = (char *)malloc(sizeof(char) * 40);
	printf("검색어를 입력하세요([option] 검색어) : ");
	gets(search_word);

	token = strtok(search_word, "- "); // "- "를 이용하여 옵션과 검색어를 분리시킴
	option = token; // 현재 token에는 옵션부분이 저장되있음

	token = strtok(NULL, ""); // strtok를 다시 한번 실행하여 검색어 부분을 추출함
	keyword = token; // keyword에 검색어 부분을 넣음

	//printf("%s %s", option, keyword); // 잘 저장됬는지 확인 코드

	if (strlen(option) == 3) { //링크리스트 필요함
		if (option == "dma") {

		}
		else if (option == "dam") {

		}
		else if (option == "mda") {

		}
		else if (option == "mad") {

		}
		else if (option == "amd") {

		}
		else if (option == "adm") {

		}
	}
	else if (strlen(option) == 2) {//링크리스트 필요함
		if (option == "da") {

		}
		else if (option == "ad") {

		}
		else if (option == "dm") {

		}
		else if (option == "md") {

		}
		else if (option == "am") {

		}
		else if (option == "ma") {

		}
	}
	else if (strlen(option) == 1) { //링크리스트 필요함
		if (option == "d") {

		}
		else if (option == "a") {

		}
		else if (option == "m") {

		}
	}
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
		scanf("%s", input_words);
		add_movie(m);
	}
	return 0;
}
