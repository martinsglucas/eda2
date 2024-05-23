# include <stdio.h>
# include <string.h>

int main(){
    int fileiras, lugares;
    scanf("%d %d", &fileiras, &lugares);
    char cinema[fileiras][lugares][3];
    for(int i = 0; i < fileiras; i++){
        for(int j = 0; j < lugares; j++){
            strcpy(cinema[i][j], "--");
        }
    }
    char bilhete[4];
    while (scanf("%s", bilhete) != EOF){
        int fileira = bilhete[0] - 'A';
        int lugar;
        if (bilhete[2] < '0' || bilhete[2] > '9'){
            lugar = (bilhete[1] - '0' - 1);
        } else {
            lugar = (bilhete[1] - '0') * 10 + (bilhete[2] - '0') - 1;
        }
        if (fileira < fileiras && lugar < lugares){
            strcpy(cinema[fileira][lugar], "XX");
        }
    }
    printf("  ");
    for (int i = 0; i < lugares; i++){
        printf("%02d ", i + 1);
    }
    printf("\n");
    for(int i = fileiras - 1; i >= 0; i--){
        printf("%c ", 'A' + i);
        for(int j = 0; j < lugares; j++){
            printf("%s ", cinema[i][j]);
        }
        printf("\n");
    }
}