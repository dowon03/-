#include <stdio.h>

//int intersection(int 

int is_start(int fp);
int is(int before, int *a, int ownnum, int order);

int sp;
int n;

int con[100][100];
int conlen[100];

void main()
{
	int pos1[100][2]; //{{x좌표, y좌표},{ } ...}
	int pos2[100][2]; //위와 동일
	int sx, sy;
	int tx, ty;

	int spaces[100][100]; //[[1번째 도형의 경로1, 2, 3...][2번째 도형의 경로 1, 2, 3...]...]

	int a; //기울기
	int b; //y절편

	int a1;
	int b1;

	int inf = 0;
	int inf1 = 0;

	int L1x1, L1x2, L1y1, L1y2, L2x1, L2x2, L2y1, L2y2;

	int lc; //Line Calculated , 함수대입값

	int count; //con[][?]에 들어간 항목수

	int i, j;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &pos1[i][0], &pos1[i][1], &pos2[i][0], &pos2[i][1]);
	}
	scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
	for (i = 0; i < n; i++)
	{
		inf = 0;
		if (pos1[i][0] == pos2[i][0])
		{
			inf = 1;	//a=무한(위쪽 직선)
			a = 1;

		}
		else
		{
			a = (pos1[i][1] - pos2[i][1]) / (pos1[i][0] - pos2[i][0]);
			//pos1[i], pos2[i]를 지나는 직선의 기울기 계산, a에 대입

			b = pos1[i][1] - pos1[i][0] * a;
			//직선의 y절편 계산, b에 대입
			//y=ax+b

		}
		//printf("%d %d\n",i,a);

		L1x1 = pos1[i][0];
		L1x2 = pos2[i][0];
		L1y1 = pos1[i][1];
		L1y2 = pos2[i][1];

		count = 0;
		for (j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			inf1 = 0;
			if (pos1[j][0] == pos2[j][0])
			{
				inf1 = 1;	//a=무한(위쪽 직선)
				a1 = 1;
				//printf("*");
			}
			else
			{
				a1 = (pos1[j][1] - pos2[j][1]) / (pos1[j][0] - pos2[j][0]); //다른 점의 기울기
				b1 = pos1[j][1] - pos1[j][0] * a1; //다른 점의 y절편
				//y=a1x+b1

			}
			//printf("%d %d\n",j,a1);

			L2x1 = pos1[j][0];
			L2x2 = pos2[j][0];
			L2y1 = pos1[j][1];
			L2y2 = pos2[j][1];

			//둘다 NULL 또는 둘다 0일때 코드도 만들어놓자 - if / else

			if ((inf == 1) && (inf1 == 1))
			{
				if ((L1x1 != L2x1) && ((((L1y1 >= ((L2y1 >= L2y2) ? L2y2 : L2y1)) && (L1y1 <= ((L2y1 >= L2y2) ? L2y1 : L2y2)))) || ((L1y1 >= ((L2y1 >= L2y2) ? L2y2 : L2y1)) && (L1y1 <= ((L2y1 >= L2y2) ? L2y1 : L2y2)))))
					continue;
				//printf("%d %d\n",a,a1);
			}
			else if ((a == 0) && (a1 == 0))
			{
				if (L1y1 != L2y1)
					continue;
				//printf("%d %d %d %d\n",i, j, a, a1);
			}
			else
			{
				if (inf == 1)
				{
					lc = a1 * L1x1 + b1; //L2에 L1의 x값을 대입했을 때의y값, 이것이 L1의 y값의 범위 사이에 있어야함
					if (((L1x1 >= ((L2x1 >= L2x2) ? L2x2 : L2x1)) && (L1x1 <= ((L2x1 <= L2x2) ? L2x2 : L2x1)) /*부등식, L1이 L2의 x범위 안에 있는지 확인*/ && (lc >= ((L1y1 >= L1y2) ? L1y2 : L1y1)) && (lc <= ((L1y1 <= L1y2) ? L1y2 : L1y1))) == 0)
						continue;
				}
				else if (inf1 == 1)
				{
					lc = a * L2x1 + b; //L1에 L2의 x값을 대입했을 때의y값, 이것이 L2의 y값의 범위 사이에 있어야함

					if (((L2x1 >= ((L1x1 >= L1x2) ? L1x2 : L1x1)) && (L2x1 <= ((L1x1 <= L1x2) ? L1x2 : L1x1)) /*부등식, L2이 L1의 x범위 안에 있는지 확인*/ && (lc >= ((L2y1 >= L2y2) ? L2y2 : L2y1)) && (lc <= ((L2y1 <= L2y2) ? L2y2 : L2y1))) == 0)
						continue;
				}
				else if (a != a1)
				{
					lc = (b - b1) / (a - a1);
					if (((lc >= ((L1x1 >= L1x2) ? L1x2 : L1x1)) && (lc <= ((L1x1 >= L1x2) ? L1x1 : L1x2)) && (lc >= ((L2x1 >= L2x2) ? L2x2 : L2x1)) && (lc <= ((L2x1 >= L2x2) ? L2x1 : L2x2))) == 0)
						continue;
				}
				else
				{
					if (L1y1 != L2y1)
						continue;
				}
			}
			//if(a==0&&a1==1)
				//printf("%d %d %d %d\n",i, j, L1y1, L2y1);
			con[i][count] = j;

			count++;

		}
		conlen[i] = count - 1;
	}
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j <= conlen[i]; j++)
			printf("%d %d\n", i, con[i][j]);
	}
}