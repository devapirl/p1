#include "crt.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include "lib.h"
#include "book_util.h"
void book_lib_input() {
	LIB lb= { 0, };
	printf("┌─────────────────────────────────┐\n");
	printf("├───□ 도서 정보 입력             │\n");
	printf("└┸┸──────────────────────────────┸┘\n");
	//printf(" 도서 정보를 입력합니다\n");
	printf(" □도서 제목을 입력하세요.\n");
	getchar();
	gets_s(lb.book.name, sizeof(char) * 100);
	printf(" □도서 번호를 입력하세요.\n");
	scanf("%d", &lb.book.sn);
	int sn1 = lb.book.sn;
	sn1 = sn_overlap_no(sn1);
	lb.book.sn = sn1;
	printf(" □도서 저자를 입력하세요.\n");
	scanf("%s", lb.book.writer);
	printf(" □출판사를 입력하세요.\n");
	scanf("%s", lb.book.public);
	printf(" □카테고리를 입력하세요.\n");
	scanf("%s", lb.book.cate);
	printf(" □영화 유무를 입력하세요.\n");
	printf(" 1. YES\n 2. NO\n");
	scanf(" %d", &lb.book.movie_search);
	
	if (lb.book.movie_search == 1)
	{
		printf("┌─────────────────────────────────┐\n");
		printf("├───■ 영화 정보                  │\n");
		printf("└┸┸──────────────────────────────┸┘\n");
		printf(" ■영화 제목을 입력하세요.\n");
		getchar();
		gets_s(lb.movie.name, sizeof(char) * 100);
		printf(" ■영화 시청 사이트를 입력하세요.\n");
		scanf("%s", lb.movie.site);
		printf(" ■영화 감독명을 입력하세요.\n");
		scanf("%s", lb.movie.producer);
		printf(" ■영화 가격을 입력하세요.\n");
		scanf("%d", &lb.movie.price);
	}
	else if(lb.book.movie_search == 2)
	{
		printf(" ■영화가 없는 도서입니다.");
	}
	else
	{
		rewind(stdin);
		printf(" 잘못 입력하셨습니다.");
		lb.book.movie_search = 2;
		printf(" 이후에 영화 정보를 수정하세요.");
	}
	printf("\n");
	printf("┌─────────────────────────────────┐\n");
	printf("├───□ 도서 구매 정보             │\n");
	printf("└┸┸──────────────────────────────┸┘\n");
	printf(" □도서 제목 : ");
	printf("  %s\n", lb.book.name);
	printf(" □구매 사이트 이름을 입력하세요.\n");
	scanf("%s", lb.buybook.site);
	printf(" □도서 가격을 입력하세요.\n");
	scanf("%d", &lb.buybook.price);
	
	book_write(lb);

}
int sn_overlap_no(int sn)
{
	FILE* fp = NULL;
	fp = fopen("book.txt", "r");
	if (fp == NULL) {
		//printf(" 파일을 생성할 수 없습니다.");
		printf("");//빈칸처리10_27
		return 0;
	}
	LIB snsn = { 0, };
	int count = 0;
	char ok;
	while (fread(&snsn, sizeof(LIB), 1, fp) == 1)
	{
		if (sn == snsn.book.sn)
		{
			sn = sn + 1;
			count++;
		}
	}
	if (count != 0) {
		printf(" 중복된 도서 번호 입력입니다.\n 도서 번호는 자동으로 %d로 입력됩니다.\n", sn);
	}
	
	fclose(fp);
	return sn;
}
void lib_lb_show(LIB lb) {
	printf("▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼\n");
	printf("┌─────────────────────────────────┐\n");
	printf("├───▣ 도서 정보                  │\n");
	printf("└┸┸──────────────────────────────┸┘\n");
	printf("%8s %s\n"," ▣도서 제목:", lb.book.name);
	//printf(" ▣도서 번호 : %d\n", lb.book.sn);
	printf(" ▣도서 저자 : %s\n", lb.book.writer);
	printf(" ▣도서 출판사 : %s\n", lb.book.public);
	printf(" ▣도서 카테고리 : %s\n", lb.book.cate);
	if (lb.book.loan == 1) {
		printf(" ▣대여 여부 : 불가능\n");
	}
	else if (lb.book.loan == 2|| lb.book.loan == 0) {
		printf(" ▣대여 여부 : 가능\n");
	}
	printf(" ▣도서 번호 : %d\n", lb.book.sn);//고유번호 검색아래둠.
	if (lb.movie.price != 0) 
	{
		printf("┌─────────────────────────────────┐\n");
		printf("├───■ 영화 정보                  │\n");
		printf("└┸┸──────────────────────────────┸┘\n");
		printf(" ■영화 이름 : %s\n", lb.movie.name);
		printf(" ■영화 시청 사이트 : %s\n", lb.movie.site);
		printf(" ■영화 감독명 : %s\n", lb.movie.name);
		printf(" ■영화 가격 : %d\n", lb.movie.price);
	}
	else
	{
		printf(" ■영화 정보 : NO\n");
	}
	
}