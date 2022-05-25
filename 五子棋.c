#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
int A[14][14];
int i = 0, s = 8, n = 0, p = 1, t = 0, M = 0, N = 0, bushu = 0, ppp = 0;
char c;
char laji[1000000];
void printqipan();
void luozi(int a, int b);
void panduan();
void jiqi();
void zhineng(int m, int n);
void jiqiluozi();
void congming();
void renji();
void renren();
void jiqijiqi();
void xiaqi();
void duquqiju(int jushu);
void jiruqiju();
void jinxing();
void qijushu();
void qijubofang(int jushu);
void chuangjian(int jushu);
void meibujiru(int a, int b);

int main() {
	int sum = 0, a, b;
	FILE *fpp;
	fopen_s(&fpp, "abc.txt", "r");
	for (a = 1; a < 14; a++) {
		for (b = 1; b < 14; b++) {
			fscanf(fpp, "%d%d%d", &a, &b, &A[a][b]);
			sum = sum + A[a][b];
			A[a][b] = 0;
		}
	}
	fclose(fpp);
	if (sum == 0 ) {
		FILE *fppp;
		fopen_s(&fppp, "jushu.txt", "w");
		fprintf(fppp, "%d", 0);
		fclose(fppp);
	}
	FILE *fppp;
	int aaa;
	fopen_s(&fppp, "jushu.txt", "r");
	fscanf(fppp, "%d", &aaa);
	fclose(fppp);
	int shibie, jieshu = 0;
	printf("开始游戏请输入1，查看历史棋局请输入2：");
	scanf("%d", &shibie);
	gets(laji);
	do {
		if (shibie == 1) {
			chuangjian(aaa);
			xiaqi();
			jieshu = 1;
		} else if (shibie == 2) {
			int sum = 0, a, b, aaaa = 0;
			FILE *fpp;
			fopen_s(&fpp, "abc.txt", "r");
			for (a = 1; a < 14; a++) {
				for (b = 1; b < 14; b++) {
					fscanf(fpp, "%d%d%d", &a, &b, &A[a][b]);
					sum = sum + A[a][b];
					A[a][b] = 0;
				}
			}
			fclose(fpp);
			if (sum == 0) {
				printf("您目前没有历史棋局，请在创建棋局后查看。");
			} else {
				printf("请输入想要读取的棋局局数(目前总局数%d):", aaa);
				int jushu;
				scanf("%d", &jushu);
				gets(laji);
				do {
					if (jushu <= aaa && jushu != 0) {
						duquqiju(jushu);
						printqipan();
						for (a = 1; a < 14; a++) {
							for (b = 1; b < 14; b++) {
								A[a][b] = 0;
							}
						}
						qijubofang(jushu);
						aaaa = 1;
					} else {
						printf("\n数值或格式错误，请重新输入\n");
						printf("请输入想要读取的棋局局数(目前总局数%d):", aaa);
						scanf("%d", &jushu);
						gets(laji);
					}
				} while (aaaa == 0);
			}
			jieshu = 1;
		} else {
			printf("\n数值或格式错误，请重新输入\n");
			printf("开始游戏请输入1，查看历史棋局请输入2：");
			scanf("%d", &shibie);
			gets(laji);
		}
	} while (jieshu == 0);
	return 0;
}

void meibujiru(int a, int b) {
	FILE *fppp;
	int m;
	fopen_s(&fppp, "jushu.txt", "r");
	fscanf(fppp, "%d", &m);
	m = m + 1;
	bushu++;
	fclose(fppp);
	char str1[20] = "bushu", str2[20] = "jushu";
	char T[10] = {};
	_itoa(m, T, 10);
	strcat(str2, T);
	strcat(str2, ".txt");
	FILE *fp4 = fopen(str2, "a");
	fprintf(fp4, "%d %d ", a, b);
	strcat(str1, T);
	strcat(str1, ".txt");
	FILE *fp3 = fopen(str1, "w");
	fprintf(fp3, "%d", bushu);
	fclose(fp4);
	fclose(fp3);
}

void chuangjian(int jushu) {
	jushu++;
	char str1[20] = "bushu", str2[20] = "jushu";
	char T[10] = {};
	_itoa(jushu, T, 10);
	strcat(str2, T);
	strcat(str2, ".txt");
	FILE *fp4 = fopen(str2, "w");
	strcat(str1, T);
	strcat(str1, ".txt");
	FILE *fp3 = fopen(str1, "w");
	fclose(fp4);
	fclose(fp3);
}

void qijubofang(int jushu) {
	char str1[20] = "bushu", str2[20] = "jushu";
	char T[10] = {};
	int m, a, b, i;
	_itoa(jushu, T, 10);
	strcat(str1, T);
	strcat(str1, ".txt");
	FILE *fp4 = fopen(str1, "r");
	fscanf(fp4, "%d", &m);
	strcat(str2, T);
	strcat(str2, ".txt");
	FILE *fp3 = fopen(str2, "r");
	printf("棋局开始播放\n");
	sleep(2);
	for (int i = 1; i <= m; i++) {
		fscanf(fp3, "%d%d", &a, &b);
		if (i % 2 == 0) {
			A[a][b] = 1;
		} else {
			A[a][b] = 2;
		}
		printf("第%d局第%d步\n", jushu, i);
		printqipan();
		sleep(1);
	}
	fclose(fp4);
	fclose(fp3);
}

void qijushu() {
	FILE *fppp;
	int a;
	fopen_s(&fppp, "jushu.txt", "r");
	fscanf(fppp, "%d", &a);
	a = a + 1;
	fclose(fppp);
	fopen_s(&fppp, "jushu.txt", "w");
	fprintf(fppp, "%d", a);
	fclose(fppp);
}

void jiruqiju() {
	qijushu();
	FILE *fp;
	fopen_s(&fp, "abc.txt", "a");
	int a, b;
	for (a = 1; a < 14; a++) {
		for (b = 1; b < 14; b++) {
			fprintf(fp, "%d %d %d ", a, b, A[a][b]);
		}
	}
	fclose(fp);
}

void duquqiju( int jushu) {
	FILE *fpp;
	int a, b;
	fopen_s(&fpp, "abc.txt", "r");
	for (int i = 1; i <= jushu; i++) {
		for (a = 1; a < 14; a++) {
			for (b = 1; b < 14; b++) {
				fscanf(fpp, "%d%d%d", &a, &b, &A[a][b]);
			}
		}
	}
	fclose(fpp);
}

void jinxing() {
	bushu = 0;
	jiruqiju();
	printf("再来一局？\n请输入Y or N:");
	scanf("%s", &c);
	gets(laji);
	M = 1;
	int mm = 0;
	do {
		int a, b;
		if (c == 'Y') {
			i = 0;
			for (a = 1; a < 14; a++) {
				for (b = 1; b < 14; b++) {
					A[a][b] = 0;
				}
			}
			n = 0;
			do {
				printf("PVE请输入1，PVP请输入2，EVE请输入3：");
				scanf("%d", &n);
				gets(laji);
				if (n != 1 && n != 2 && n != 3)
					printf("\n数值或格式错误，请重新输入\n");
			} while (n != 1 && n != 2 && n != 3);
			if (n == 1) {
				printf("你执黑，电脑执白，你是先手。\n");
				printf("请选择难度【简单（输入0）普通（输入1）困难（输入2）】：");
				scanf("%d", &s);
				gets(laji);
				N = 1;
			}
			mm = 1;
		} else if (c == 'N') {
			i = 1;
			printf("谢谢您玩这个游戏!\nPs：万水千山总是情，给个高分行不行");
			t = 1;
			mm = 1;
		} else {
			printf("\n格式错误，请重新输入\n");
			printf("再来一局？\n请输入Y or N:");
			scanf("%s", &c);
			gets(laji);
		}
	} while (mm == 0);
}

void xiaqi() {
	printf("PVE请输入1，PVP请输入2，EVE请输入3：");
	scanf("%d", &n);
	gets(laji);
	do {
		bushu = 0;
		if (n == 1) {
			renji();
		} else if (n == 2) {
			renren();
		} else if (n == 3) {
			jiqijiqi();
		} else {
			printf("\n数值或格式错误，请重新输入\n");
			printf("PVE请输入1，PVP请输入2，EVE请输入3：");
			scanf("%d", &n);
			gets(laji);
		}
	} while (i == 0);
}

void renji() {
	srand(time(0));
	if (N == 0) {
		printf("你执黑，电脑执白，你是先手。\n");
		printf("请选择难度【简单（输入0）普通（输入1）困难（输入2）】：");
		scanf("%d", &s);
		gets(laji);
	}
	do {
		if (s == 0 || s == 1 || s == 2) {
			int a = 114514, b = 114514;
			printf("请输入您的棋子坐标(1~13)，如2 3(表示第二行第三列)：");
			p = 1;
			scanf("%d%d", &a, &b);
			gets(laji);
			printf("\n");
			luozi( a,  b);
		} else {
			printf("\n数值或格式错误，请重新输入\n");
			printf("请选择难度【简单（输入0）普通（输入1）困难（输入2）】：");
			scanf("%d", &s);
			gets(laji);
		}
	} while (i == 0 && n == 1);
}

void renren() {
	do {
		int a = 114514, b = 114514;
		do {
			printf("请玩家1输入棋子坐标(1~13)，如2 3(表示第二行第三列)：");
			p = 1;
			scanf("%d%d", &a, &b);
			gets(laji);
			luozi( a,  b);
		} while (p == 0 && i == 0);
		p = 0;
		while (p == 0 && i == 0 && t == 0) {
			printf("请玩家2输入棋子坐标(1~13)，如2 3(表示第二行第三列)：");
			p = 2;
			scanf("%d%d", &a, &b);
			gets(laji);
			luozi( a,  b);
		}
	} while (i == 0 && n == 2);
}

void jiqijiqi() {
	do {
		M = 0;
		p = 0;
		while (p == 0 && i == 0 ) {
			printf("电脑1执子:\n");
			p = 2;
			sleep(1);
			jiqiluozi( );
			printqipan();
			panduan( );
		};
		p = 0;
		while (p == 0 && i == 0 && M == 0 ) {
			printf("电脑2执子:\n");
			p = 1;
			sleep(1);
			jiqiluozi();
			printqipan();
			panduan( );
		}
	} while (i == 0 && n == 3);
}

void luozi(int a, int b) {
	if (a < 1 || a > 13 || b < 1 || b > 13) {
		if (a == 114514 || b == 114514) {
			printf("\n格式错误，请重新输入\n");
			if (n == 2) {
				p = 0;
			}
		} else {
			printf("输入的位置超出了棋盘的范围，请重新输入！\n");
			if (n == 2) {
				p = 0;
			}
		}
	} else if (A[a][b] == 1 || A[a][b] == 2) {
		printf("提示：该位置已经有棋子了!\n");
		if (n == 2) {
			p = 0;
		}
	} else {
		if (p == 1) {
			A[a][b] = 2;
			meibujiru(a, b);
		}
		if (p == 2) {
			A[a][b] = 1;
			meibujiru(a, b);
		}
		if (n == 1) {
			if (s == 2) {
				congming();
			} else if (s == 1)  {
				zhineng(a, b);
			} else if (s == 0) {
				jiqi();
			}
		}
		printqipan();
		panduan();
	}
}

void panduan() {
	int a, b;
	for (a = 1; a < 14; a++) {
		for (b = 1; b < 14; b++) {
			if ((A[a][b] == A[a + 1][b] && A[a][b] == A[a + 2][b] && A[a][b] == A[a + 3][b] && A[a][b] == A[a + 4][b]) ||
			        (A[a][b] == A[a ][b + 1] && A[a][b] == A[a ][b + 2] && A[a][b] == A[a ][b + 3] && A[a][b] == A[a ][b + 4]) ||
			        (A[a][b] == A[a + 1][b + 1] && A[a][b] == A[a + 2][b + 2] && A[a][b] == A[a + 3][b + 3] && A[a][b] == A[a + 4][b + 4])
			        ||
			        (A[a][b] == A[a + 1][b - 1] && A[a][b] == A[a + 2][b - 2] && A[a][b] == A[a + 3][b - 3] && A[a][b] == A[a + 4][b - 4])
			   ) {
				if (A[a][b] == 2 && i == 0) {
					if (n == 3) {
						printf("电脑1（黑）赢了！\n");
						t = 1;
					} else if (n == 1) {
						printf("你赢了！\n");
					} else {
						printf("玩家1（黑）赢了！\n");
						t = 1;
					}
					jinxing();
				}
				if (A[a][b] == 1 && i == 0 ) {
					if (n == 3) {
						printf("电脑2（白）赢了！\n");
					} else if (n == 1)
						printf("你输了！\n");
					else
						printf("玩家2（白）赢了！\n");
					jinxing();
				}
			}
		}
	}
}

void jiqi() {
	int i = 0;
	do {
		int a = (rand() % 13) + 1;
		int b = (rand() % 13) + 1;
		if (A[a][b] == 0) {
			A[a][b] = p;
			meibujiru(a, b);
			i = 1;
		}
	} while (i == 0);
}

void zhineng(int m, int n) {
	int i = 0, t ;
	do {
		int a, b;
		t = (rand() % 8) + 1;
		if (t == 1) {
			a = m + 1;
			b = n;
		}
		if (t == 2) {
			a = m + 1;
			b = n - 1;
		}
		if (t == 3) {
			a = m;
			b = n - 1;
		}
		if (t == 4) {
			a = m - 1;
			b = n - 1;
		}
		if (t == 5) {
			a = m - 1;
			b = n;
		}
		if (t == 6) {
			a = m - 1;
			b = n + 1;
		}
		if (t == 7) {
			a = m;
			b = n + 1;
		}
		if (t == 8) {
			a = m + 1;
			b = n + 1;
		}
		if (A[a][b] == 0 && (!(a < 1 || a > 13 || b < 1 || b > 13))) {
			A[a][b] = p;
			meibujiru(a, b);
			i = 1;
		}
	} while (i == 0);
}

void jiqiluozi() {
	int i = 0;
	while (i == 0 && p == 1) {
		congming();
		i = 1;
	}
	while (i == 0 && p == 2) {
		congming();
		i = 1;
	}
}

void congming( ) {
	int a, b, i = 0, m, n;
	for (a = 1; a < 14; a++) {
		for (b = 1; b < 14; b++) {
			if (A[a][b] == p % 2 + 1 && i == 0) {
				if (A[a][b] == A[a ][b + 1] && A[a][b] == A[a ][b + 2] && A[a][b] == A[a ][b + 3] && i == 0 ) {
					if (A[a ][b - 1] == 0 && b < 15 && b > 1) {
						A[a ][b - 1] = p;
						meibujiru(a, b - 1);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b] && A[a][b] == A[a + 2][b] && A[a][b] == A[a + 3][b] && i == 0 ) {
					if (A[a - 1][b] == 0 && a < 15 && a > 1) {
						A[a - 1][b] = p;
						meibujiru(a - 1, b);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b + 1] && A[a][b] == A[a + 2][b + 2] && A[a][b] == A[a + 3][b + 3] && i == 0 ) {
					if (A[a - 1][b - 1] == 0 && a < 15 && a > 1 && b < 15 && b > 1) {
						A[a - 1][b - 1] = p;
						meibujiru(a - 1, b - 1);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b - 1] && A[a][b] == A[a + 2][b - 2] && A[a][b] == A[a + 3][b - 3] && i == 0 ) {
					if (A[a - 1][b + 1] == 0 && a < 15 && a > 1 && b < 13 && b > -1) {
						A[a - 1][b + 1] = p;
						meibujiru(a - 1, b + 1);
						i = 1;
					}
				} else if (A[a][b] == A[a][b + 1] && A[a][b + 1] == A[a][b + 2] && A[a][b - 1] == A[a][b + 3] && A[a][b - 1] == 0
				           && b > -3 && b < 11 && i == 0) {
					A[a][b + 3] = p;
					meibujiru(a, b + 3);
					i = 1;
				} else if (A[a][b] == A[a + 1][b] && A[a + 1][b] == A[a + 2][b] && A[a - 1][b] == A[a + 3][b] && A[a - 1][b] == 0
				           && a > -3 && a < 11 && i == 0) {
					A[a + 3][b] = p;
					meibujiru(a + 3, b);
					i = 1;
				} else if (A[a][b] == A[a + 1][b + 1] && A[a + 1][b + 1] == A[a + 2][b + 2] && A[a - 1][b - 1] == A[a + 3][b + 3]
				           && A[a - 1][b - 1] == 0 && b > -3 && b < 11 && a > -3 && a < 11 && i == 0) {
					A[a + 3][b + 3] = p;
					meibujiru(a + 3, b + 3);
					i = 1;
				} else if (A[a][b] == A[a + 1][b - 1] && A[a + 1][b - 1] == A[a + 2][b - 2] && A[a - 1][b + 1] == A[a + 3][b - 3]
				           && A[a - 1][b + 1] == 0 && a > -3 && a < 11 && b > 3 && b < 17 && i == 0) {
					A[a + 3][b - 3] = p;
					meibujiru(a + 3, b - 3);
					i = 1;
				} else if (A[a][b] == A[a][b + 3] && A[a][b + 1] != A[a][b + 2] && A[a][b + 1] + A[a][b + 2] == p % 2 + 1 && i == 0) {
					if (A[a][b + 1] == 0 && b > -1 && b < 13 && i == 0) {
						A[a][b + 1] = p;
						meibujiru(a, b + 1);
						i = 1;
					}
					if (A[a][b + 2] == 0 && b > -2 && b < 12 && i == 0) {
						meibujiru(a, b + 2);
						A[a][b + 2] = p;
						i = 1;
					}
				} else if (A[a][b] == A[a + 3][b] && A[a + 1][b] != A[a + 2][b] && A[a + 1][b] + A[a + 2][b] == p % 2 + 1 && i == 0) {
					if (A[a + 1][b] == 0 && a > -1 && a < 13) {
						meibujiru(a + 1, b);
						A[a + 1][b] = p;
						i = 1;
					}
					if (A[a + 2][b] == 0 && a > -2 && a < 12) {
						meibujiru(a + 2, b);
						A[a + 2][b] = p;
						i = 1;
					}
				} else if (A[a][b] == A[a + 3][b + 3] && A[a + 1][b + 1] != A[a + 2][b + 2]
				           && A[a + 1][b + 1] + A[a + 2][b + 2] == p % 2 + 1 && i == 0) {
					if (A[a + 1][b + 1] == 0 && b > -1 && b < 13 && a > -1 && a < 13) {
						meibujiru(a + 1, b + 1);
						A[a + 1][b + 1] = p;
						i = 1;
					}
					if (A[a + 2][b + 2] == 0 && b > -2 && b < 12 && a > -2 && a < 12) {
						meibujiru(a + 2, b + 2);
						A[a + 2][b + 2] = p;
						i = 1;
					}
				} else if (A[a][b] == A[a + 3][b - 3] && A[a + 1][b - 1] != A[a + 2][b - 2]
				           && A[a + 1][b - 1] + A[a + 2][b - 2] == p % 2 + 1 && i == 0) {
					if (A[a + 1][b - 1] == 0 && b > 1 && b < 15 && a > -1 && a < 13) {
						meibujiru(a + 1, b - 1);
						A[a + 1][b - 1] = p;
						i = 1;
					}
					if (A[a + 2][b - 2] == 0 && b > 2 && b < 16 && a > -2 && a < 12) {
						meibujiru(a + 2, b - 2);
						A[a + 2][b - 2] = p;
						i = 1;
					}
				}
			}
		}
	}
	for (a = 1; a < 14; a++) {
		for (b = 1; b < 14; b++) {
			if (A[a][b] == p  && i == 0) {
				if (A[a][b] == A[a ][b + 1] && A[a][b] == A[a ][b + 2] && A[a][b] == A[a ][b + 3]  && i == 0) {
					if (A[a ][b - 1] == 0 && b < 15 && b > 1) {
						A[a ][b - 1] = p;
						meibujiru(a, b - 1);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b] && A[a][b] == A[a + 2][b] && A[a][b] == A[a + 3][b] && i == 0  ) {
					if (A[a - 1][b] == 0 && a < 15 && a > 1) {
						A[a - 1][b] = p;
						meibujiru(a - 1, b);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b + 1] && A[a][b] == A[a + 2][b + 2] && A[a][b] == A[a + 3][b + 3] && i == 0  ) {
					if (A[a - 1][b - 1] == 0 && a < 15 && a > 1 && b < 15 && b > 1) {
						A[a - 1][b - 1] = p;
						meibujiru(a - 1, b - 1);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b - 1] && A[a][b] == A[a + 2][b - 2] && A[a][b] == A[a + 3][b - 3] && i == 0 ) {
					if (A[a - 1][b + 1] == 0 && a < 15 && a > 1 && b < 13 && b > -1) {
						A[a - 1][b + 1] = p;
						meibujiru(a - 1, b + 1);
						i = 1;
					}
				} else if (A[a][b] == A[a][b + 1] && A[a][b + 1] == A[a][b + 2] && A[a][b - 1] == A[a][b + 3] && A[a][b - 1] == 0
				           && b > -3 && b < 11 && i == 0) {
					A[a][b + 3] = p;
					meibujiru(a, b + 3);
					i = 1;
				} else if (A[a][b] == A[a + 1][b] && A[a + 1][b] == A[a + 2][b] && A[a - 1][b] == A[a + 3][b] && A[a - 1][b] == 0
				           && a > -3 && a < 11 && i == 0) {
					A[a + 3][b] = p;
					meibujiru(a + 3, b);
					i = 1;
				} else if (A[a][b] == A[a + 1][b + 1] && A[a + 1][b + 1] == A[a + 2][b + 2] && A[a - 1][b - 1] == A[a + 3][b + 3]
				           && A[a - 1][b - 1] == 0 && b > -3 && b < 11 && a > -3 && a < 11 && i == 0) {
					A[a + 3][b + 3] = p;
					meibujiru(a + 3, b + 3);
					i = 1;
				} else if (A[a][b] == A[a + 1][b - 1] && A[a + 1][b - 1] == A[a + 2][b - 2] && A[a - 1][b + 1] == A[a + 3][b - 3]
				           && A[a - 1][b + 1] == 0 && a > -3 && a < 11 && b > 3 && b < 17 && i == 0) {
					A[a + 3][b - 3] = p;
					meibujiru(a + 3, b - 3);
					i = 1;
				} else if (A[a][b] == A[a][b + 3] && A[a][b + 1] != A[a][b + 2] && A[a][b + 1] + A[a][b + 2] == p % 2 + 1 && i == 0) {
					if (A[a][b + 1] == 0 && b > -1 && b < 13) {
						A[a][b + 1] = p;
						meibujiru(a, b + 1);
						i = 1;
					}
					if (A[a][b + 2] == 0 && b > -2 && b < 12) {
						meibujiru(a, b + 2);
						A[a][b + 2] = p;
						i = 1;
					}
				} else if (A[a][b] == A[a + 3][b] && A[a + 1][b] != A[a + 2][b] && A[a + 1][b] + A[a + 2][b] == p % 2 + 1 && i == 0) {
					if (A[a + 1][b] == 0 && a > -1 && a < 13) {
						meibujiru(a + 1, b);
						A[a + 1][b] = p;
						i = 1;
					}
					if (A[a + 2][b] == 0 && a > -2 && a < 12) {
						meibujiru(a + 2, b);
						A[a + 2][b] = p;
						i = 1;
					}
				} else if (A[a][b] == A[a + 3][b + 3] && A[a + 1][b + 1] != A[a + 2][b + 2]
				           && A[a + 1][b + 1] + A[a + 2][b + 2] == p % 2 + 1 && i == 0) {
					if (A[a + 1][b + 1] == 0 && b > -1 && b < 13 && a > -1 && a < 13) {
						meibujiru(a + 1, b + 1);
						A[a + 1][b + 1] = p;
						i = 1;
					}
					if (A[a + 2][b + 2] == 0 && b > -2 && b < 12 && a > -2 && a < 12) {
						meibujiru(a + 2, b + 2);
						A[a + 2][b + 2] = p;
						i = 1;
					}
				} else if (A[a][b] == A[a + 3][b - 3] && A[a + 1][b - 1] != A[a + 2][b - 2]
				           && A[a + 1][b - 1] + A[a + 2][b - 2] == p % 2 + 1 && i == 0) {
					if (A[a + 1][b - 1] == 0 && b > 1 && b < 15 && a > -1 && a < 13) {
						meibujiru(a + 1, b - 1);
						A[a + 1][b - 1] = p;
						i = 1;
					}
					if (A[a + 2][b - 2] == 0 && b > 2 && b < 16 && a > -2 && a < 12) {
						meibujiru(a + 2, b - 2);
						A[a + 2][b - 2] = p;
						i = 1;
					}
				}
			}
		}
	}
	for (a = 1; a < 14; a++) {
		for (b = 1; b < 14; b++) {
			if (A[a][b] == p  && i == 0) {
				if (A[a][b] == A[a][b + 1]) {
					if (A[a][b + 2] == 0 && i == 0 && b > -2 && b < 12) {
						A[a][b + 2] = p;
						meibujiru(a, b + 2);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b]) {
					if (A[a + 2][b] == 0 && i == 0 && a > -2 && a < 12) {
						A[a + 2][b] = p;
						meibujiru(a + 2, b);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b + 1]) {
					if (A[a + 2][b + 2] == 0 && i == 0 && a > -2 && a < 12 && b > -2 && b < 12) {
						A[a + 2][b + 2] = p;
						meibujiru(a + 2, b + 2);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b - 1]) {
					if (A[a + 2][b - 2] == 0 && i == 0 && b > 2 && b < 16 && a > -2 && a < 12) {
						A[a + 2][b - 2] = p;
						meibujiru(a + 2, b - 2);
						i = 1;
					}
				} else if (A[a][b + 1] + A[a + 1][b + 1] + A[a - 1][b + 1] + A[a][b - 1] + A[a - 1][b - 1] + A[a + 1][b ] + A[a - 1][b ]
				           + A[a + 1][b - 1] <= 3 && a > 1 && a < 13 && b > 1 && b < 13) {
					zhineng(a, b);
					i = 1;
				}
			}
		}
	}
	for (a = 1; a < 14; a++) {
		for (b = 1; b < 14; b++) {
			if (A[a][b] == p % 2 + 1 && i == 0) {
				if (A[a][b] == A[a][b + 1]) {
					if (A[a][b + 2] == 0 && i == 0 && b > -2 && b < 12) {
						A[a][b + 2] = p;
						meibujiru(a, b + 2);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b]) {
					if (A[a + 2][b] == 0 && i == 0 && a > -2 && a < 12) {
						A[a + 2][b] = p;
						meibujiru(a + 2, b);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b + 1]) {
					if (A[a + 2][b + 2] == 0 && i == 0 && a > -2 && a < 12 && b > -2 && b < 12) {
						A[a + 2][b + 2] = p;
						meibujiru(a + 2, b + 2);
						i = 1;
					}
				} else if (A[a][b] == A[a + 1][b - 1]) {
					if (A[a + 2][b - 2] == 0 && i == 0 && b > 2 && b < 16 && a > -2 && a < 12) {
						A[a + 2][b - 2] = p;
						meibujiru(a + 2, b - 2);
						i = 1;
					}
				} else if (A[a][b + 1] + A[a + 1][b + 1] + A[a - 1][b + 1] + A[a][b - 1] + A[a - 1][b - 1] + A[a + 1][b ] + A[a - 1][b ]
				           + A[a + 1][b - 1] <= 3 && a > 1 && a < 13 && b > 1 && b < 13) {
					zhineng(a, b);
					i = 1;
				}
			}
		}
	}
	if (i == 0 && A[7][7] == 0) {
		A[7][7] = p;
		meibujiru(7, 7);
		i = 1;
	}
	if (i == 0)
		jiqi();
}

void printqipan() {
	int i, j;
	for (i = 0; i < 14; i++) {
		if (i == 0) {
			for ( j = 1; j <= 13; j++)
				printf("%2d", j);
			printf("\n");
		}
		if (i == 1) {
			j = 1;
			if (j == 1) {
				if (A[i][j] == 0)
					printf("┌ ");
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
			}
			for (j = 2; j < 13; j++) {
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
				if (A[i][j] == 0)
					printf("┬ ");
			}
			if (j == 13) {
				if (A[i][j] == 0)
					printf("┐ ");
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
				printf("%d", i);
				printf("\n");
			}
		}
		if (i > 1 && i < 13) {
			j = 1;
			if (j == 1) {
				if (A[i][j] == 0)
					printf("├ ");
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
			}
			for (j = 2; j < 13; j++) {
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
				if (A[i][j] == 0)
					printf("┼ ");
			}
			if (j == 13) {
				if (A[i][j] == 0)
					printf("┤ ");
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
				printf("%d", i);
				printf("\n");
			}
		}
		if (i == 13) {
			j = 1;
			if (j == 1) {
				if (A[i][j] == 0)
					printf("└ ");
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
			}
			for (j = 2; j < 13; j++) {
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
				if (A[i][j] == 0)
					printf("┴ ");
			}
			if (j == 13) {
				if (A[i][j] == 0)
					printf("┘ ");
				if (A[i][j] == 1)
					printf("●");
				if (A[i][j] == 2)
					printf("○");
				printf("%d", i);
				printf("\n");
			}
		}
	}
}
