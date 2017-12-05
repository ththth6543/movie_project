#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <signal.h>

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

movie *root_movie, *m;	//movie*의 헤더와 다른거
director *root_director, *d;	//director*의 헤더와 다른거
actor *root_actor, *a;	//actor*의 헤더와 다른거
int root_m_num = 0, root_d_num = 0, root_a_num = 0;	//헤더인지 아닌지 판별할 변수
int serial_m_num = 1, serial_d_num = 1, serial_a_num = 1;	//각각의 시리얼 넘버 전역변수

void add_movie() {	//movie 정보 입력받는 함수
	char *temp;	//글자를 입력받을 임시 포인터
	temp = (char *)malloc(sizeof(char) * 200);	//임시 포인터 동적할당

	if (root_m_num == 0) {	//링크드 리스트 처음 헤더를 root_movie에 저장
		root_movie = m;
		root_m_num = 1;
	}
	m->serial_number = serial_m_num++;

	printf("title > ");
	gets(temp);	//title 입력
	m->title = (char *)malloc(sizeof(char) * strlen(temp) + 1);	//입력받은 글자의 크기만큼 동적할당 받음(+1은 맨뒤에 null을 넣을 공간)
	strcpy(m->title, temp);	//temp를 구조체 멤버에 옮김

	printf("genre > ");
	gets(temp);
	m->genre = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(m->genre, temp);

	printf("director > ");
	gets(temp);
	m->director = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(m->director, temp);

	printf("year > ");
	scanf("%s", temp);
	m->year = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(m->year, temp);

	printf("time > ");
	scanf("%s", temp);
	getchar();
	m->time = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(m->time, temp);

	printf("actors > ");
	gets(temp);
	m->actors = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(m->actors, temp);

	m->next = (movie *)malloc(sizeof(movie));	//m의 next포인터를 동적할당
	m = m->next;	//m을 현재 m의 next로 바꿈
	m->next = NULL;	//지금의 m의 next를 null로 해줌

	printf("@@ Done\n\n");
}

void add_director() {	//director 정보 입력받는 함수
	char *temp;
	temp = (char *)malloc(sizeof(char) * 200);

	if (root_d_num == 0) {	//링크드 리스트 처음 헤더를 root_director에 저장
		root_director = d;
		root_d_num = 1;
	}
	d->serial_number = serial_d_num++;

	printf("name > ");
	gets(temp);	//name 입력
	d->name = (char *)malloc(sizeof(char) * strlen(temp) + 1);	//입력받은 글자의 크기만큼 동적할당 받음(+1은 맨뒤에 null을 넣을 공간)
	strcpy(d->name, temp);	//temp를 구조체 멤버에 옮김

	printf("sex > ");
	scanf("%s", temp);
	d->sex = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(d->sex, temp);

	printf("birth > ");
	scanf("%s", temp);
	getchar();
	d->birth = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(d->birth, temp);

	printf("best_movies > ");
	gets(temp);
	d->best_movies = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(d->best_movies, temp);

	d->next = (director *)malloc(sizeof(director));	//d의 next포인터를 동적할당
	d = d->next;	//d를 현재 d의 next로 바꿈
	d->next = NULL;	//지금의 d의 next를 null로 해줌

	printf("@@ Done\n\n");
}

void add_actor() {	//actor의 정보를 입력받는 함수
	char *temp;
	temp = (char *)malloc(sizeof(char) * 200);

	if (root_a_num == 0) {	//링크드 리스트 처음 헤더를 root_actor에 저장
		root_actor = a;
		root_a_num = 1;
	}
	a->serial_number = serial_a_num++;

	printf("name > ");
	gets(temp);
	a->name = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(a->name, temp);

	printf("sex > ");
	scanf("%s", temp);
	a->sex = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(a->sex, temp);

	printf("birth > ");
	scanf("%s", temp);
	getchar();
	a->birth = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(a->birth, temp);

	printf("best_movies > ");
	gets(temp);
	a->best_movies = (char *)malloc(sizeof(char) * strlen(temp) + 1);
	strcpy(a->best_movies, temp);

	a->next = (actor *)malloc(sizeof(actor));	//a의 next포인터를 동적할당
	a = a->next;	//a을 현재 a의 next로 바꿈
	a->next = NULL;	//지금의 a의 next를 null로 해줌

	printf("@@ Done\n\n");
}

void save_director() {
	FILE *fp;
	fp = fopen("director_list", "w");
	d = root_director;
	while (d->next != NULL) {
		fprintf(fp, "%d:%s:%s:%s:%s\n", d->serial_number, d->name, d->sex, d->birth, d->best_movies);
		d = d->next;
	}
	fclose(fp);
	printf("@@ Done\n\n");
}

void save_movie() {
	FILE *fp;
	fp = fopen("movie_list", "w");
	m = root_movie;
	while (m->next != NULL) {
		fprintf(fp, "%d:%s:%s:%s:%s:%s\n", m->serial_number, m->title, m->genre, m->director, m->year, m->time);
		m = m->next;
	}
	fclose(fp);
	printf("@@ Done\n\n");
}

void save_actor() {
	FILE *fp;
	fp = fopen("actor_list", "w");
	a = root_actor;
	while (a->next != NULL) {
		fprintf(fp, "%d:%s:%s:%s:%s\n", a->serial_number, a->name, a->sex, a->birth, a->best_movies);
		a = a->next;
	}
	fclose(fp);
	printf("@@ Done\n\n");
}
int power(int x, int y){ //x^y
	int pow = 1;
	int i = 0;
	while (i < y){
		pow = pow * x;
		i++;
	}

	return pow;
}

void search(char *string, char *option) {

	int i = 0, j = 1; // while문 돌리기 위해 필요한 변수

	d = root_director; //포인터 초기화
	m = root_movie; //포인터 초기화
	a = root_actor; //포인터 초기화

	int str_len; // string의 길이를 저장할 변수
	char *meta_string; //메타문자를 제외한 검색어를 저장하는 포인터
	char *string_token; // strtok()를 한 변수를 저장

	int question_num = 0; // 물음표 숫자
	char *question_location; // 물음표 위치 저장

	question_location = (char *)malloc(sizeof(char)*str_len);

	str_len = strlen(string); // string 길이 저장

	int correct_score = 0; // 맞는지 확인 변수

	while (i < str_len){ //물음표 있는지 검사
		if (*(string + i) == '?'){ // ? 확인
			*(question_location + i) = 1; // ? 위치를 기억, ? 있으면 1, 없으면 0
			question_num++;
			i++;
		}
		else{
			*(question_location + i) = 0;
		}
		i++;
	}
	if (question_num != 0){ // '?'가 1개이상 존재
		if (*(string) == '*'){ //메타문자 *이 앞에 있을때
			/*string_token = (char *)malloc(sizeof(char)*str_len);
			meta_string = (char *)malloc(sizeof(char)*str_len);
			string_token = strtok(string, "*"); //문자열에 있는 '*'제거
			meta_string = string_token; // *를 제거한 문자열을 meta_string에 저장
			*/
			if (strlen(option) == 4) { //링크리스트 필요함, 옵션 확인
				if (!strcmp(option, "-dma")) {
					while(d -> next != NULL){ // 감독검색
						while(j < str_len ){
							if (*(question_location + j)){ // ? 확인하고 있는 경우
								j++;
							}
							else{ // ? 확인하고 없는 경우
								if (*(string + j) == *(d -> name) + (strlen(d -> name) - str_len + j)){
									correct_score++;
									j++;
								}
							}
						}
						if (correct_score == (str_len - question_num - 1)){
							printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> birth, d -> best_movies);
							d = d -> next;
							j = 1; // j 초기화
							correct_score = 0; // correct_score 초기화
						}
						else{
							d = d -> next;
							j = 1; // j 초기화
							correct_score = 0; // correct_score 초기화
						}
					}
					while(m -> next != NULL){ // 영화 검색
						while(j < str_len){
							if (*(question_location + j)){
								j++;
							}
							else{
								if (*(string + j) == *(m -> title) + (strlen(m -> title) - str_len + j)){
									correct_score++;
									j++;
								}
							}
						}
						if (correct_score == (str_len - question_num - 1)){
							printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
							m = m -> next;
							j = 1; // 초기화
							correct_score = 0; // 초기화
						}
						else{
							m = m -> next;
							j = 1;
							correct_score = 0;
						}
					}
					while(a -> next != NULL){ // 배우 검색
						while(j < str_len){
							if (*(question_location + j)){
								j++;
							}
							else{
								if (*(string + j) == *(a -> name) + (strlen(a -> name) - str_len + j)){
									correct_score++;
									j++;
								}
							}
						}
						if (correct_score == (str_len - question_num - 1)){
							printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
							a = a -> next;
							j = 1;
							correct_score = 0;
						}
						else{
							a = a -> next;
							j = 1;
							correct_score = 0;
						}
					}
				}
				else if (!strcmp(option, "-dam")) {
					printf("2\n"); //확인코드
				}
				else if (!strcmp(option, "-mda")) {
					printf("3\n"); //확인코드
				}
				else if (!strcmp(option, "-mad")) {
					printf("4\n"); //확인코드
				}
				else if (!strcmp(option, "-amd")) {
					printf("5\n"); //확인코드
				}
				else if (!strcmp(option, "-adm")) {
					printf("6\n"); //확인코드
				}
			}
			else if (strlen(option) == 3) {//링크리스트 필요함
				if (!strcmp(option, "-da")) {
					printf("7\n"); //확인코드
				}
				else if (!strcmp(option, "-ad")) {
					printf("8\n"); //확인코드
				}
				else if (!strcmp(option, "-dm")) {
					printf("9\n"); //확인코드
				}
				else if (!strcmp(option, "-md")) {
					printf("10\n"); //확인코드
				}
				else if (!strcmp(option, "-am")) {
					printf("11\n"); //확인코드
				}
				else if (!strcmp(option, "-ma")) {
					printf("12\n"); //확인코드
				}
			}
			else if (strlen(option) == 2) { //링크리스트 필요함
				if (!strcmp(option, "-d")) {
					printf("13\n"); //확인코드
				}
				else if (!strcmp(option, "-a")) {
					printf("14\n"); //확인코드
				}
				else if (!strcmp(option, "-m")) {
					printf("15\n"); //확인코드
				}
			}
		}

		else if (*(string + (str_len - 1)) == '*'){ // 메타문자 '*'이 뒤에 있을 때

		}
		else{ // '?'만 존재

		}
	}


	if (strlen(option) == 4) { //링크리스트 필요함, 메타문자 없이 전체를 검색할때
		if (!strcmp(option, "-dma")) {
			printf("1\n"); //확인코
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-dam")) {
			printf("2\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-mda")) {
			printf("3\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-mad")) {
			printf("4\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-amd")) {
			printf("5\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-adm")) {
			printf("6\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
	}
	else if (strlen(option) == 3) {//링크리스트 필요함
		if (!strcmp(option, "-da")) {
			printf("7\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-ad")) {
			printf("8\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-dm")) {
			printf("9\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
		}
		else if (!strcmp(option, "-md")) {
			printf("10\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
		}
		else if (!strcmp(option, "-am")) {
			printf("11\n"); //확인코드
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-ma")) {
			printf("12\n"); //확인코드
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
	}
	else if (strlen(option) == 2) { //링크리스트 필요함
		if (!strcmp(option, "-d")) {
			printf("13\n"); //확인코드
			while (d -> next != NULL){ //감독 검색
				if (!strcmp(string, d -> name)){
					printf("%d:%s:%s:%s:%s\n", d -> serial_number, d -> name, d -> sex, d -> birth, d -> best_movies, d -> name);
				}
				d = d -> next;
			}
		}
		else if (!strcmp(option, "-a")) {
			printf("14\n"); //확인코드
			while (a -> next != NULL){ //배우 검색
				if (!strcmp(string, a -> name)){
					printf("%d:%s:%s:%s:%s\n", a -> serial_number, a -> name, a -> sex, a -> birth, a -> best_movies);
				}
				a = a -> next;
			}
		}
		else if (!strcmp(option, "-m")) {
			printf("15\n"); //확인코드
			while (m -> next != NULL){ //영화 검색
				if (!strcmp(string, m -> title)){
					printf("%d:%s:%s:%s:%s:%s:%s\n", m -> serial_number, m -> title, m -> genre, m -> director, m -> year, m -> time, m -> actors);
				}
				m = m -> next;
			}
		}
	}
}
int menu_func(char *input) {	//명령어 입력한거 실행하는거, 추후에 같은 형식으로 추가하세용
	char *temp;	//input받는 임시 변수, input을 바꾸는 사태가 일어나지 않게 해줌
	char *token;	//명령어 쪼개서 저장하는 토큰
	char *cut;	//명령어 쪼개는 기준이 담긴 포인터
	char *menu;	//명령 부분을 담는 포인터(예: update)
	char *factor;	//인자 부분을 담는 포인터(예: m, d, a중 하나임)
	char *option;	//옵션 부분을 담는 포인터(예: tdy)
	char *string;	//search명령에 쓰이는 찾을 문자열
	char *file_name;	//파일 이름을 담는 포인터(예: my_list)
	int get_serial_num;	//print나 delete명령에 쓰이는 관리 번호
	int i;	//for문을 돌리는 변수, 왜 for도 없는데 선언했냐 물으신다면 대답 안하는게 인! 지! 상! 정!

	temp = (char *)malloc(sizeof(char) * 50);	//temp 동적 할당
	token = (char *)malloc(sizeof(char) * 50);	//토큰 동적 할당
	cut = (char *)malloc(sizeof(char) * 10);	//cut 동적 할당
	strcpy(temp, input);	//temp에 input 복사
	cut = " ";	//공백으로 명령어 쪼개기

	token = strtok(temp, cut);
	menu = (char *)malloc(sizeof(char) * strlen(token) + 1);
	strcpy(menu, token);
	printf("menu : %s\n", menu);

	if (!strcmp(menu, "end"))
		return 0;	//exit_num을 0으로 만들어 종료하기
	else if (!strcmp(menu, "add")) {	//add 명령어 처리
		token = strtok(NULL, cut);
		factor = (char *)malloc(sizeof(char) * strlen(token) + 1);
		strcpy(factor, token);
		printf("factor : %s\n", factor);	//factor 확인

		if (!strcmp(factor, "m"))
			add_movie();
		else if (!strcmp(factor, "d"))
			add_director();
		else if (!strcmp(factor, "a"))
			add_actor();
	}
	else if (!strcmp(menu, "print")) {	//print 명령어 처리, serial_num 안붙이면 오류뜸
		token = strtok(NULL, cut);
		factor = (char *)malloc(sizeof(char) * strlen(token) + 1);
		strcpy(factor, token);
		printf("factor : %s\n", factor);	//factor 확인

		token = strtok(NULL, cut);
		get_serial_num = atoi(token);	//문자열을 숫자로 변환
		printf("num : %d\n", get_serial_num);	//get_serial_num 확인

		if (!strcmp(factor, "m")) {	//임시 moive 출력하는 함수
			m = root_movie;
			while (m->next != NULL) {
				printf("%s\n", m->title);
				m = m->next;
			}
			printf("\n");
		}
		else if (!strcmp(factor, "d")) {	//임시 director 출력하는 함수
			d = root_director;
			while (d->next != NULL) {
				printf("%s\n", d->name);
				d = d->next;
			}
			printf("\n");
		}
		else if (!strcmp(factor, "a")) {	//임시 actor 출력하는 함수
			a = root_actor;
			while (a->next != NULL) {
				printf("%s\n", a->name);
				a = a->next;
			}
			printf("\n");
		}
	}
	else if (!strcmp(menu, "delete")) {	//delete 명령어 처리
		token = strtok(NULL, cut);
		factor = (char *)malloc(sizeof(char) * strlen(token) + 1);
		strcpy(factor, token);
		printf("factor : %s\n", factor);	//factor 확인

		token = strtok(NULL, cut);
		get_serial_num = atoi(token);
		printf("num : %s\n", get_serial_num);	//get_serial_num 확인

		if (!strcmp(factor, "m"))
			;	//moive 삭제하는 함수
		else if (!strcmp(factor, "d"))
			;	//director 삭제하는 함수
		else if (!strcmp(factor, "a"))
			;	//actor 삭제하는 함수
	}
	else if (!strcmp(menu, "search")) {	//search 명령어 처리
		token = strtok(NULL, cut);
		if(*token == '-'){
			option = (char *)malloc(sizeof(char) * strlen(token) + 1);
			strcpy(option, token);
			printf("option : %s\n", option);	//option 확인
			token = strtok(NULL, cut);
		}
		string = (char *)malloc(sizeof(char) * strlen(token) + 1);
		strcpy(string, token);
		printf("string : %s\n", string);	//string 확인

		search(string, option);
	}
	else if (!strcmp(menu, "update")) {	//update 명령어 처리
		token = strtok(NULL, cut);
		factor = (char *)malloc(sizeof(char) * strlen(token) + 1);
		strcpy(factor, token);
		printf("factor : %s\n", factor);	//factor 확인

		token = strtok(NULL, cut);
		option = (char *)malloc(sizeof(char) * strlen(token) + 1);
		strcpy(option, token);
		printf("option : %s\n", option);	//option 확인

		token = strtok(NULL, cut);
		get_serial_num = atoi(token);
		printf("num : %s\n", get_serial_num);	//get_serial_num 확인
	}
	else if (!strcmp(menu, "sort")) {	//sort 명령어 처리
		token = strtok(NULL, cut);
		factor = (char *)malloc(sizeof(char) * strlen(token) + 1);
		strcpy(factor, token);
		printf("factor : %s\n", factor);	//factor 확인

		if ((token = strtok(NULL, cut)) != NULL) {	//뒤에 뭐가 더 있는지 확인 
			if (!strcmp(token, "-f")) {	//뒤에 있는게 -f이면
				token = strtok(NULL, cut);	//-f 건너뛰기
				file_name = (char *)malloc(sizeof(char) * strlen(token) + 1);
				strcpy(file_name, token);
				printf("file_name : %s\n", file_name);	//file_name 확인
			}
			else {	//뒤에 있는게 옵션이면
				option = (char *)malloc(sizeof(char) * strlen(token) + 1);
				strcpy(option, token);
				printf("option : %s\n", option);	//option 확인

				if ((token = strtok(NULL, cut)) != NULL) {	//뒤에 뭐가 더 있는지 확인
					token = strtok(NULL, cut);	//있다면 -f일테니 건너뛰기
					file_name = (char *)malloc(sizeof(char) * strlen(token) + 1);
					strcpy(file_name, token);
					printf("file_name : %s\n", file_name);	//file_name 확인
				}
			}
		}
		printf("\n");
	}
	else if (!strcmp(menu, "save")) {	//save 명령어 처리
		token = strtok(NULL, cut);
		factor = (char *)malloc(sizeof(char) * strlen(token) + 1);
		strcpy(factor, token);
		printf("factor : %s\n", factor);	//factor 확인

		if ((token = strtok(NULL, cut)) != NULL) {	//뒤에 뭐가 더 있는지 확인 
			if (!strcmp(token, "-f")) {	//뒤에 있는게 -f이면
				token = strtok(NULL, cut);	//-f 건너뛰기
				file_name = (char *)malloc(sizeof(char) * strlen(token) + 1);
				strcpy(file_name, token);
				printf("file_name : %s\n", file_name);	//file_name 확인
			}
			else {	//뒤에 있는게 옵션이면
				option = (char *)malloc(sizeof(char) * strlen(token) + 1);
				strcpy(option, token);
				printf("option : %s\n", option);	//option 확인

				if ((token = strtok(NULL, cut)) != NULL) {	//뒤에 뭐가 더 있는지 확인
					token = strtok(NULL, cut);	//있다면 -f일테니 건너뛰기
					file_name = (char *)malloc(sizeof(char) * strlen(token) + 1);
					strcpy(file_name, token);
					printf("file_name : %s\n", file_name);	//file_name 확인
				}
			}
		}
		printf("\n");
	}



	if (!strcmp(input, "save m")) {	//임시 movie 세이브
		save_movie();
	}
	else if (!strcmp(input, "save d")) {	//임시 director 세이브
		save_director();
	}
	else if (!strcmp(input, "save a")) {	//임시 actor 세이브
		save_actor();
	}

	return 1;
}
void control_c(int sig)
{
	char *answer;
	answer = (char *)malloc(sizeof(char)*5);
	printf("\nGet Interrupt signal.\n");
	printf("Do you want to exit program? (Y/n) ");
	scanf("%s", answer);
	//printf("(movie) ");
	if((*answer == 'y' || *answer == 'Y'))
		exit(1);
}

int main(void) {
	m = (movie *)malloc(sizeof(movie));	//movie *m 전역 구조체 동적할당
	d = (director *)malloc(sizeof(director));	//director *d 전역 구조체 동적할당
	a = (actor *)malloc(sizeof(actor));	//actor *a 전역 구조체 동적할당
	int exit_num = 1;	//프로그램 끝내는 변수
	char *input_words;
	input_words = (char *)malloc(sizeof(char) * 50);
	printf(">> Welcome to My Movie <<\n");
	printf("File Loading.....\n");
	printf("You can use add, update, delete, search, sort, save, end commands.\n");

	/*if (signal(SIGINT, control_c) == &control_c){
	  signal(SIGINT, control_c);
	  printf("(movie) ");
	  }*/
	signal(2, control_c);
	while (exit_num) {
		//signal(SIGINT, control_c);
		printf("(movie) ");
		//signal(SIGINT, control_c);
		gets(input_words);
		exit_num = menu_func(input_words);
	}
	return 0;
}
