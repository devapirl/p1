#include "crt.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include "lib.h"
#include "book_util.h"
void book_lib_input() {
	LIB lb= { 0, };
	printf("����������������������������������������������������������������������\n");
	printf("���������� ���� ���� �Է�             ��\n");
	printf("����������������������������������������������������������������������\n");
	//printf(" ���� ������ �Է��մϴ�\n");
	printf(" �൵�� ������ �Է��ϼ���.\n");
	getchar();
	gets_s(lb.book.name, sizeof(char) * 100);
	printf(" �൵�� ��ȣ�� �Է��ϼ���.\n");
	scanf("%d", &lb.book.sn);
	int sn1 = lb.book.sn;
	sn1 = sn_overlap_no(sn1);
	lb.book.sn = sn1;
	printf(" �൵�� ���ڸ� �Է��ϼ���.\n");
	scanf("%s", lb.book.writer);
	printf(" �����ǻ縦 �Է��ϼ���.\n");
	scanf("%s", lb.book.public);
	printf(" ��ī�װ��� �Է��ϼ���.\n");
	scanf("%s", lb.book.cate);
	printf(" �࿵ȭ ������ �Է��ϼ���.\n");
	printf(" 1. YES\n 2. NO\n");
	scanf(" %d", &lb.book.movie_search);
	
	if (lb.book.movie_search == 1)
	{
		printf("����������������������������������������������������������������������\n");
		printf("���������� ��ȭ ����                  ��\n");
		printf("����������������������������������������������������������������������\n");
		printf(" �῵ȭ ������ �Է��ϼ���.\n");
		getchar();
		gets_s(lb.movie.name, sizeof(char) * 100);
		printf(" �῵ȭ ��û ����Ʈ�� �Է��ϼ���.\n");
		scanf("%s", lb.movie.site);
		printf(" �῵ȭ �������� �Է��ϼ���.\n");
		scanf("%s", lb.movie.producer);
		printf(" �῵ȭ ������ �Է��ϼ���.\n");
		scanf("%d", &lb.movie.price);
	}
	else if(lb.book.movie_search == 2)
	{
		printf(" �῵ȭ�� ���� �����Դϴ�.");
	}
	else
	{
		rewind(stdin);
		printf(" �߸� �Է��ϼ̽��ϴ�.");
		lb.book.movie_search = 2;
		printf(" ���Ŀ� ��ȭ ������ �����ϼ���.");
	}
	printf("\n");
	printf("����������������������������������������������������������������������\n");
	printf("���������� ���� ���� ����             ��\n");
	printf("����������������������������������������������������������������������\n");
	printf(" �൵�� ���� : ");
	printf("  %s\n", lb.book.name);
	printf(" �౸�� ����Ʈ �̸��� �Է��ϼ���.\n");
	scanf("%s", lb.buybook.site);
	printf(" �൵�� ������ �Է��ϼ���.\n");
	scanf("%d", &lb.buybook.price);
	
	book_write(lb);

}
int sn_overlap_no(int sn)
{
	FILE* fp = NULL;
	fp = fopen("book.txt", "r");
	if (fp == NULL) {
		//printf(" ������ ������ �� �����ϴ�.");
		printf("");//��ĭó��10_27
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
		printf(" �ߺ��� ���� ��ȣ �Է��Դϴ�.\n ���� ��ȣ�� �ڵ����� %d�� �Էµ˴ϴ�.\n", sn);
	}
	
	fclose(fp);
	return sn;
}
void lib_lb_show(LIB lb) {
	printf("�������������������\n");
	printf("����������������������������������������������������������������������\n");
	printf("���������� ���� ����                  ��\n");
	printf("����������������������������������������������������������������������\n");
	printf("%8s %s\n"," �õ��� ����:", lb.book.name);
	//printf(" �õ��� ��ȣ : %d\n", lb.book.sn);
	printf(" �õ��� ���� : %s\n", lb.book.writer);
	printf(" �õ��� ���ǻ� : %s\n", lb.book.public);
	printf(" �õ��� ī�װ� : %s\n", lb.book.cate);
	if (lb.book.loan == 1) {
		printf(" �ô뿩 ���� : �Ұ���\n");
	}
	else if (lb.book.loan == 2|| lb.book.loan == 0) {
		printf(" �ô뿩 ���� : ����\n");
	}
	printf(" �õ��� ��ȣ : %d\n", lb.book.sn);//������ȣ �˻��Ʒ���.
	if (lb.movie.price != 0) 
	{
		printf("����������������������������������������������������������������������\n");
		printf("���������� ��ȭ ����                  ��\n");
		printf("����������������������������������������������������������������������\n");
		printf(" �῵ȭ �̸� : %s\n", lb.movie.name);
		printf(" �῵ȭ ��û ����Ʈ : %s\n", lb.movie.site);
		printf(" �῵ȭ ������ : %s\n", lb.movie.name);
		printf(" �῵ȭ ���� : %d\n", lb.movie.price);
	}
	else
	{
		printf(" �῵ȭ ���� : NO\n");
	}
	
}