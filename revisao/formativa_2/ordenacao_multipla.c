#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double score;
    int member;
    int position;
} Problem;

int compare(const void *a, const void *b)
{
    Problem *problemA = (Problem *)a;
    Problem *problemB = (Problem *)b;
    if (problemA->score > problemB->score)
        return -1;
    if (problemA->score < problemB->score)
        return 1;
    if (problemA->member > problemB->member)
        return 1;
    if (problemA->member < problemB->member)
        return -1;
    if (problemA->position > problemB->position)
        return 1;
    if (problemA->position < problemB->position)
        return -1;
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int M, N;
        scanf("%d %d", &M, &N);
        Problem *problems = malloc(M * N * sizeof(Problem));
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                problems[i * N + j].member = i + 1;
                problems[i * N + j].position = j + 1;
                scanf("%lf", &problems[i * N + j].score);
            }
        }
        qsort(problems, M * N, sizeof(Problem), compare);
        for (int i = 0; i < M * N; i++)
        {
            printf("%d,%d ", problems[i].member, problems[i].position);
        }
        printf("\n");
        free(problems);
    }
    return 0;
}