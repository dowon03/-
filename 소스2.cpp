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
	int pos1[100][2]; //{{x��ǥ, y��ǥ},{ } ...}
	int pos2[100][2]; //���� ����
	int sx, sy;
	int tx, ty;

	int spaces[100][100]; //[[1��° ������ ���1, 2, 3...][2��° ������ ��� 1, 2, 3...]...]

	int a; //����
	int b; //y����

	int a1;
	int b1;

	int inf = 0;
	int inf1 = 0;

	int L1x1, L1x2, L1y1, L1y2, L2x1, L2x2, L2y1, L2y2;

	int lc; //Line Calculated , �Լ����԰�

	int count; //con[][?]�� �� �׸��

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
			inf = 1;	//a=����(���� ����)
			a = 1;

		}
		else
		{
			a = (pos1[i][1] - pos2[i][1]) / (pos1[i][0] - pos2[i][0]);
			//pos1[i], pos2[i]�� ������ ������ ���� ���, a�� ����

			b = pos1[i][1] - pos1[i][0] * a;
			//������ y���� ���, b�� ����
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
				inf1 = 1;	//a=����(���� ����)
				a1 = 1;
				//printf("*");
			}
			else
			{
				a1 = (pos1[j][1] - pos2[j][1]) / (pos1[j][0] - pos2[j][0]); //�ٸ� ���� ����
				b1 = pos1[j][1] - pos1[j][0] * a1; //�ٸ� ���� y����
				//y=a1x+b1

			}
			//printf("%d %d\n",j,a1);

			L2x1 = pos1[j][0];
			L2x2 = pos2[j][0];
			L2y1 = pos1[j][1];
			L2y2 = pos2[j][1];

			//�Ѵ� NULL �Ǵ� �Ѵ� 0�϶� �ڵ嵵 �������� - if / else

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
					lc = a1 * L1x1 + b1; //L2�� L1�� x���� �������� ����y��, �̰��� L1�� y���� ���� ���̿� �־����
					if (((L1x1 >= ((L2x1 >= L2x2) ? L2x2 : L2x1)) && (L1x1 <= ((L2x1 <= L2x2) ? L2x2 : L2x1)) /*�ε��, L1�� L2�� x���� �ȿ� �ִ��� Ȯ��*/ && (lc >= ((L1y1 >= L1y2) ? L1y2 : L1y1)) && (lc <= ((L1y1 <= L1y2) ? L1y2 : L1y1))) == 0)
						continue;
				}
				else if (inf1 == 1)
				{
					lc = a * L2x1 + b; //L1�� L2�� x���� �������� ����y��, �̰��� L2�� y���� ���� ���̿� �־����

					if (((L2x1 >= ((L1x1 >= L1x2) ? L1x2 : L1x1)) && (L2x1 <= ((L1x1 <= L1x2) ? L1x2 : L1x1)) /*�ε��, L2�� L1�� x���� �ȿ� �ִ��� Ȯ��*/ && (lc >= ((L2y1 >= L2y2) ? L2y2 : L2y1)) && (lc <= ((L2y1 <= L2y2) ? L2y2 : L2y1))) == 0)
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